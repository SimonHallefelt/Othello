#include "../include/Player.hpp"

Player::Player(const int player) : player(player) {
    std::cout << "Created Player " << player << std::endl;
}

Player::~Player() {
    std::cout << "Created Player " << player << std::endl;
}

int Player::getPlayer() const {
    return player;
}