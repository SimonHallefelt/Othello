#include <array>

struct direction {
    int dir_y;
    int dir_x;
};

bool isMoveLegal(const std::array<std::array<int, 8>, 8>& board, const int player , const int y, const int x) {
    std::array<direction, 8> directions = {{
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}
    }};

    int pos_y, pos_x, value;
    bool pass;
    for (const auto& [dir_y, dir_x] : directions) {
        pos_y = y + dir_y;
        pos_x = x + dir_x;
        pass = false;

        while (pos_x >= 0 && pos_y >= 0 && pos_x < 8 && pos_y < 8) {
            value = board[pos_y][pos_x];
            if (!value) {
                break;
            } else if (value == player) {
                if (pass) return true;
                break;
            } else {
                pass = true;
            }
            pos_y += dir_y;
            pos_x += dir_x;
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