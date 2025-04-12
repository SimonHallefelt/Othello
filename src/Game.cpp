#include "../include/Game.hpp"
#include <iostream>
#include <vector>
#include <thread>

void startGame(const std::shared_ptr<GameInfo>& gameInfo) {
    std::cout << "Start Game!" << std::endl;

    Int2D pos(-1,-1);
    gameInfo -> printBoard();
    while (!gameInfo -> gameComplete()) {
        const Player& currentPlayer = gameInfo -> getCurrentPlayer();
        if (!currentPlayer.getPlayerType()) { // human move
            while (!gameInfo -> getHasManualMove()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
            pos = gameInfo -> getManualMove();
        } else { // bot move
            pos = currentPlayer.move(gameInfo -> getBoard());
        }
        std::cout << "player " << (currentPlayer.getPlayer() == 1 ? "White" : "Black") << " selected move: " << pos << std::endl;
        gameInfo -> makeMove(pos);
        gameInfo -> printBoard();
        gameInfo -> setHasManualMove(false);
    }
    gameInfo -> printWinner();

}