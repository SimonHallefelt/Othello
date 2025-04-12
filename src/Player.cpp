#include "../include/Player.hpp"

extern Int2D randomPlayerMove(std::array<std::array<int, 8>, 8>& board, int player);

Player::Player(const int player, int playerType) : 
player(player), playerType(playerType) {
    std::cout << "Created Player " << player << std::endl;
}

Player::~Player() {
    std::cout << "destroyed Player " << player << std::endl;
}

int Player::getPlayer() const {
    return player;
}

Int2D Player::move(std::array<std::array<int, 8>, 8>& board) const {
    std::vector<Int2D> possibleMoves = getLegalMoves(board, player);
    if (possibleMoves.size() == 0) return {-1, -1}; // no legal move

    switch (playerType) {
    case 1:
        return randomPlayerMove(board, player);
    default:
        return randomPlayerMove(board, player);
    }
}