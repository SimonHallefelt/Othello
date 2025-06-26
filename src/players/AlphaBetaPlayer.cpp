#include <LegalMoves.hpp>

#include <limits>


int getScore(std::array<std::array<int, 8>, 8>& board) {
    int sum = 0;
    for (auto row : board) {
        for (auto value : row) {
            sum += value;
        }
    }
    return sum;
}

std::array<std::array<int, 8>, 8>& makeMove(std::array<std::array<int, 8>, 8> board, int player, Int2D move, std::vector<Int2D>& captured) {
    if (move.y == -1) return board;
    board[move.y][move.x] = player;
    for (const auto& pos : captured) {
        board[pos.y][pos.x] = player;
    }
    return board;
}

int alphaBetaPruning(std::array<std::array<int, 8>, 8>& board, int alpha, int beta, int player, int depth, int score) {
    if (!depth) return score;
    std::vector<Int2D> possibleMoves = getLegalMoves(board, player);
    if (!possibleMoves.size()) possibleMoves.push_back({-1,-1});
    for (const auto& move : possibleMoves) {
        std::vector<Int2D> captured = getPositionsCaptured(board, player, move);
        std::array<std::array<int, 8>, 8> newBoard = makeMove(board, player, move, captured);
        int newScore = alphaBetaPruning(newBoard, alpha, beta, player*-1, depth-1, score+(1+captured.size())*player);
        if (player == -1 && newScore < beta) {
            beta = newScore;
        } else if (player == 1 && newScore > alpha) {
            alpha = newScore;
        }
        if (alpha >= beta) {
            break;
        }
    }
    return player == 1 ? alpha : beta;
}

Int2D AlphaBetaPlayerMove(const std::array<std::array<int, 8>, 8>& initialBoard, int player) {
    std::array<std::array<int, 8>, 8> board = initialBoard;
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
    int score = getScore(board);
    for (const auto& move : possibleMoves) {
        std::vector<Int2D> captured = getPositionsCaptured(board, player, move);
        std::array<std::array<int, 8>, 8> newBoard = makeMove(board, 1, move, captured);
        int newScore = alphaBetaPruning(newBoard, alpha, beta, -1, 7, score+1+captured.size());
        if (newScore > alpha) {
            alpha = newScore;
            bestMove = move;
        }
    }

    return bestMove;
}