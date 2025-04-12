#include "raylib.h"
#include <memory>

#include "../include/Board.hpp"

void startGUI(const std::shared_ptr<Board>& board)
{
    const int gridSize = 8;
    const int screenWidth = 800;
    const int screenHeight = 800;
    const int boardSize = 600;
    int cellSize = boardSize / gridSize;
    int boardMarginLeft = (screenWidth - boardSize) / 2;
    InitWindow(screenWidth, screenHeight, "OTHELLO");
    SetTargetFPS(60);

    std::array<std::array<int, 8>, 8> b;

    while (!WindowShouldClose())
    {
        b = board -> getBoard();



        BeginDrawing();
            ClearBackground(RAYWHITE);

            for (int i = 0; i < gridSize; i++) {
                for (int j = 0; j < gridSize; j++) {
                    DrawRectangle(boardMarginLeft + i*cellSize, j*cellSize, cellSize, cellSize, GREEN);
                    DrawRectangleLines(boardMarginLeft + i*cellSize, j*cellSize, cellSize, cellSize, BLACK);
                    if (b[i][j]) {
                        auto color = b[i][j] == 1 ? WHITE : BLACK;
                        DrawCircle(boardMarginLeft + i*cellSize + cellSize/2, j*cellSize + cellSize/2, cellSize/3, color);
                    }
                }
            }
            


        EndDrawing();
    }

    CloseWindow();
}