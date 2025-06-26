#include <LegalMoves.hpp>

#include <random>

Int2D RandomPlayerMove(std::array<std::array<int, 8>, 8>& board, int player) {
    std::vector<Int2D> possibleMoves = getLegalMoves(board, player);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, possibleMoves.size() - 1);
    return possibleMoves[dis(gen)];
}