#include "raylib.h"
#include <memory>
#include <thread>
#include <iostream>

#include "../include/GameInfo.hpp"
#include "../include/Game.hpp"

void startGUI()
{
    const int gridSize = 8;
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int boardSize = 600;
    int cellSize = boardSize / gridSize;
    int boardMarginLeft = (screenWidth - boardSize) / 2;
    InitWindow(screenWidth, screenHeight, "OTHELLO");
    SetTargetFPS(60);

    Color lightGreen = CLITERAL(Color){ 144, 238, 144, 255 };

    std::array<std::array<int, 8>, 8> board;
    Int2D clickedCell(-1, -1);

    std::shared_ptr<GameInfo> gameInfo = std::make_shared<GameInfo>();
    std::thread t1([gameInfo]() {
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

            if (gameInfo -> getCurrentPlayer().getPlayerType() == 0) { // manual player
                auto legalMoves = getLegalMoves(board, gameInfo -> getCurrentPlayer().getPlayer());
                for (const auto& possibleMove : legalMoves) {

                }
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

        EndDrawing();
    }

    gameInfo -> setStopGame();
    t1.join();
    CloseWindow();
}