#include <array>
#include "../include/Int2D.hpp"

bool isMoveLegal(const std::array<std::array<int, 8>, 8>& board, const int player , const int y, const int x) {
    std::array<Int2D, 8> directions = {{
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
    }};

    int value;
    bool pass;
    for (const auto& dir : directions) {
        Int2D pos(y + dir.y, x + dir.x);
        pass = false;

        while (pos.x >= 0 && pos.y >= 0 && pos.x < 8 && pos.y < 8) {
            value = board[pos.y][pos.x];
            if (!value) {
                break;
            } else if (value == player) {
                if (pass) return true;
                break;
            } else {
                pass = true;
            }
            pos.add(dir);
        }
    }

    return false;
}

std::array<std::array<bool, 8>, 8> getLegalMoves(const std::array<std::array<int, 8>, 8>& board, const int player) {
    std::array<std::array<bool, 8>, 8> legalMoves = {{false}};

    for (size_t y = 0; y < 8; y++) {
        for (size_t x = 0; x < 8; x++) {
            if (!board[y][x]) {
                legalMoves[y][x] = isMoveLegal(board, player, y, x);
            }
        }
    }
    
    return legalMoves;
}