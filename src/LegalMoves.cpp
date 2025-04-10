#include "../include/LegalMoves.hpp"

bool isMoveLegal(const std::array<std::array<int, 8>, 8>& board, const int player , const Int2D startPos) {
    std::array<Int2D, 8> directions = {{
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
    }};

    int value;
    bool pass;
    for (const auto& dir : directions) {
        Int2D pos(startPos.y + dir.y, startPos.x + dir.x);
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

std::vector<Int2D> getLegalMoves(const std::array<std::array<int, 8>, 8>& board, const int player) {
    std::vector<Int2D> legalMoves = {};

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (!board[y][x]) {
                Int2D pos(y, x);
                if (isMoveLegal(board, player, pos)) {
                    legalMoves.push_back(pos);
                }
            }
        }
    }
    
    return legalMoves;
}