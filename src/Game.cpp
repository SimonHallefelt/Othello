#include "../include/Game.hpp"
#include <iostream>
#include <vector>

void startGame(const std::shared_ptr<GameInfo>& gameInfo) {
    std::cout << "Start Game!" << std::endl;

    gameInfo -> printBoard();
    while (!gameInfo -> gameComplete()) {
        const Player& currentPlayer = gameInfo -> getCurrentPlayer();
        Int2D pos = currentPlayer.move(gameInfo -> getBoard());
        std::cout << "player " << (currentPlayer.getPlayer() == 1 ? "White" : "Black") << " selected move: " << pos << std::endl;
        gameInfo -> makeMove(pos);
        gameInfo -> printBoard();
    }
    gameInfo -> printWinner();

}