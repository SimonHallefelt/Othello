#include "../include/Player.hpp"

extern Int2D RandomPlayerMove(std::array<std::array<int, 8>, 8>& board, int player);
extern Int2D AlphaBetaPlayerMove(std::array<std::array<int, 8>, 8>& board, int player);

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

int Player::getPlayerType() const {
    return playerType;
}

void Player::setPlayerType(int pt) {
    playerType = pt;
}

Int2D Player::move(std::array<std::array<int, 8>, 8>& board) const {
    std::vector<Int2D> possibleMoves = getLegalMoves(board, player);
    if (possibleMoves.size() == 0) return {-1, -1}; // no legal move

    switch (playerType) {
    case 1:
        return RandomPlayerMove(board, player);
    case 2:
        return AlphaBetaPlayerMove(board, player);
    default:
        return RandomPlayerMove(board, player);
    }
}