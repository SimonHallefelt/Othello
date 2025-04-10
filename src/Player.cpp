#include "../include/Player.hpp"
#include <random>

Player::Player(const int player) : player(player) {
    std::cout << "Created Player " << player << std::endl;
}

Player::~Player() {
    std::cout << "Created Player " << player << std::endl;
}

int Player::getPlayer() const {
    return player;
}

Int2D Player::move(std::array<std::array<int, 8>, 8> board) {
    std::vector<Int2D> possibleMoves = getLegalMoves(board, player);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, possibleMoves.size() - 1);
    return possibleMoves[dis(gen)];
}