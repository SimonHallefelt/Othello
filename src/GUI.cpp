#include "raylib.h"
#include <memory>
#include <thread>
#include <iostream>
#include <string>

#include "../include/GameInfo.hpp"
#include "../include/Game.hpp"

void drawPlayerVisuals(std::shared_ptr<GameInfo> gameInfo, int player, int width, Int2D origin, 
        std::vector<std::string> buttonsText, std::vector<Rectangle>& buttons) {
    int titleFontSize = 30;
    const char* title = player == -1 ? "BLACK" : "white";
    int titleWidth = MeasureText(title, titleFontSize);
    int titleHeight = titleFontSize;
    DrawText(title, origin.x+width/2 - titleWidth / 2, origin.y - titleHeight / 2, titleFontSize, BLACK);
    origin.add({titleHeight+10, 0});

    int score = 0;
    for (const auto& row : gameInfo -> getBoard()) {
        for (const auto& value : row) {
            score += value == player;
        }
    }
    int scoreFontSize = 30;
    int scoreWidth = MeasureText(std::to_string(score).c_str(), scoreFontSize);
    int scoreHeight = scoreFontSize;
    DrawText(std::to_string(score).c_str(), origin.x+width/2 - scoreWidth / 2, origin.y - scoreHeight / 2, scoreFontSize, BLACK);
    origin.add({scoreHeight+10, 0});

    if (buttons.size() < buttonsText.size()*2) {
        int buttonFontSize = 20;
        int buttonMarginWidth = 10;
        int buttonMarginHight = 5;
        for (int i = 0; i < buttonsText.size(); i++) {
            const auto& str = buttonsText[i];
            int buttonWidth = MeasureText(str.c_str(), buttonFontSize) + buttonMarginWidth * 2;
            int buttonHeight = buttonFontSize + buttonMarginHight * 2;
            Rectangle button = { origin.x+width/2 - buttonWidth/2, origin.y, buttonWidth, buttonHeight };
            origin.add({buttonFontSize+10, 0});
            buttons.push_back(button);
        }
    }
}

void makeNewGameButton(std::shared_ptr<GameInfo> gameInfo, int center, int y, std::unique_ptr<std::thread>& t) {
    int newGameFontSize = 30;
    int marginWidth = 10;
    int marginHight = 5;
    const char* text = "New Game";
    int newGameWidth = MeasureText(text, newGameFontSize) + marginWidth * 2;
    int newGameHeight = newGameFontSize + marginHight * 2;
    Rectangle button = { center - newGameWidth / 2, y, newGameWidth, newGameHeight };
    
    Color buttonColor = LIGHTGRAY;
    if (CheckCollisionPointRec(GetMousePosition(), button)) {
        buttonColor = GRAY;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            buttonColor = DARKGRAY;
            gameInfo -> setStopGame();
            if (t -> joinable()) {
                t -> join();
            }
            gameInfo -> newGame();
            t = std::make_unique<std::thread>([gameInfo]() {
                startGame(gameInfo);
            });
        }
    }
    DrawRectangleRec(button, buttonColor);
    DrawText(text, button.x + marginWidth, button.y + marginHight, newGameFontSize, BLACK);
}

void startGUI()
{
    const int gridSize = 8;
    const int screenWidth = 800;
    const int screenHeight = 900;
    const int boardSize = screenWidth * 3 / 4;
    int cellSize = boardSize / gridSize;
    int boardMarginLeft = (screenWidth - boardSize) / 2;
    InitWindow(screenWidth, screenHeight, "OTHELLO");
    SetTargetFPS(60);

    std::vector<std::string> buttonsText = {"Manual", "Random"};
    std::vector<Rectangle> buttons;

    Color lightGreen = CLITERAL(Color){ 144, 238, 144, 255 };
    Color transparentWhite = CLITERAL(Color){ 255, 255, 255, 130 };

    std::array<std::array<int, 8>, 8> board;
    Int2D clickedCell(-1, -1);

    std::shared_ptr<GameInfo> gameInfo = std::make_shared<GameInfo>();
    std::unique_ptr<std::thread> t = std::make_unique<std::thread>([gameInfo]() {
        startGame(gameInfo);
    });

    while (!WindowShouldClose()) {
        board = gameInfo -> getBoard();


        BeginDrawing();
            ClearBackground(RAYWHITE);

            for (int y = 0; y < gridSize; y++) {
                for (int x = 0; x < gridSize; x++) {
                    auto color = y == clickedCell.y && x == clickedCell.x ? lightGreen : GREEN;
                    DrawRectangle(boardMarginLeft + x*cellSize, y*cellSize, cellSize, cellSize, color);
                    DrawRectangleLines(boardMarginLeft + x*cellSize, y*cellSize, cellSize, cellSize, BLACK);
                    if (board[y][x]) {
                        color = board[y][x] == 1 ? WHITE : BLACK;
                        DrawCircle(boardMarginLeft + x*cellSize + cellSize/2, y*cellSize + cellSize/2, cellSize/3, color);
                    }
                }
            }

            auto legalMoves = getLegalMoves(board, gameInfo -> getCurrentPlayer().getPlayer());
            for (const auto& pm : legalMoves) {
                DrawCircle(boardMarginLeft + pm.x*cellSize + cellSize/2, pm.y*cellSize + cellSize/2, cellSize/5, transparentWhite);
            }
            
            
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mousePos = GetMousePosition();
                if (boardMarginLeft < mousePos.x && boardMarginLeft+cellSize*8 > mousePos.x && cellSize*8 > mousePos.y ) {
                    int y = mousePos.y / cellSize;
                    int x = (mousePos.x - boardMarginLeft) / cellSize;
                    clickedCell = {y, x};
                    gameInfo -> setManualMove(clickedCell);
                    std::cout << "Clicked cell: " << clickedCell << std::endl;
                } else {
                    clickedCell = {-1,-1};
                }
            }

            Int2D origin(boardSize+25, (screenWidth-boardSize)/2);
            drawPlayerVisuals(gameInfo, -1, boardSize/2, origin, buttonsText, buttons);
            origin.add({0, boardSize/2});
            drawPlayerVisuals(gameInfo, 1, boardSize/2, origin, buttonsText, buttons);

            for(int i = 0; i < buttons.size(); i++) {
                const auto& button = buttons[i];
                Color buttonColor = LIGHTGRAY;
                if (CheckCollisionPointRec(GetMousePosition(), button)) {
                    buttonColor = GRAY;
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        buttonColor = DARKGRAY;
                        gameInfo -> setPlayerType(i < buttonsText.size() ? -1 : 1, i % buttonsText.size());
                    }
                }
                DrawRectangleRec(button, buttonColor);
                DrawText(buttonsText[i%buttonsText.size()].c_str(), button.x + 10, button.y + 5, 20, BLACK);
            }

            int hight = buttons[buttons.size()-1].y + buttons[buttons.size()-1].height + 20;
            makeNewGameButton(gameInfo, screenWidth/2, hight, t);

        EndDrawing();
    }

    gameInfo -> setStopGame();
    if (t -> joinable()) {
        t -> join();
    }
    CloseWindow();
}