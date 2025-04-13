#include <LegalMoves.hpp>

#include <limits>


int score(std::array<std::array<int, 8>, 8>& board) {
    int sum = 0;
    for (auto row : board) {
        for (auto value : row) {
            sum += value;
        }
    }
    return sum;
}

std::array<std::array<int, 8>, 8>& makeMove(std::array<std::array<int, 8>, 8> board, int player, Int2D move) {
    std::vector<Int2D> captured = getPositionsCaptured(board, player, move);
    board[move.y][move.x] = player;
    for (const auto& pos : captured) {
        board[pos.y][pos.x] = player;
    }
    return board;
}

int alphaBetaPruning(std::array<std::array<int, 8>, 8> board, int alpha, int beta, int player, int depth) {
    if (!depth) return score(board);
    std::vector<Int2D> possibleMoves = getLegalMoves(board, player);
    for (const auto& move : possibleMoves) {
        std::array<std::array<int, 8>, 8> newBoard = makeMove(board, player, move);
        int score = alphaBetaPruning(newBoard, alpha, beta, player*-1, depth-1);
        if (player == -1 && score < beta) {
            beta = score;
        } else if (player == 1 && score > alpha) {
            alpha = score;
        }
        if (alpha >= beta) {
            break;
        }
    }
    return player == 1 ? alpha : beta;
}

Int2D AlphaBetaPlayerMove(std::array<std::array<int, 8>, 8>& board, int player) {
    if (player == -1) {
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                board[y][x] *= -1;
            }
        }
    }
    std::vector<Int2D> possibleMoves = getLegalMoves(board, 1);
    int alpha = std::numeric_limits<int>::min();
    int beta = std::numeric_limits<int>::max();
    Int2D bestMove = possibleMoves[0];
    for (const auto& move : possibleMoves) {
        std::array<std::array<int, 8>, 8> newBoard = makeMove(board, 1, move);
        int score = alphaBetaPruning(newBoard, alpha, beta, -1, 7);
        if (score > alpha) {
            alpha = score;
            bestMove = move;
        }
    }

    return bestMove;
}