#include "../include/Game.hpp"
#include <iostream>
#include <vector>
#include <thread>

void startGame(const std::shared_ptr<GameInfo>& gameInfo) {
    std::cout << "Start Game!" << std::endl;

    Int2D pos(-1,-1);
    gameInfo -> printBoard();
    while (!gameInfo -> gameComplete() && !gameInfo -> getStopGame()) {
        const Player& currentPlayer = gameInfo -> getCurrentPlayer();
        if (!currentPlayer.getPlayerType()) { // human move
            if (getLegalMoves(gameInfo -> getBoard(), currentPlayer.getPlayer()).size()) {
                while (!gameInfo -> getHasManualMove()) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(10));
                    if (gameInfo -> getStopGame()) goto gameEnd;
                }
                pos = gameInfo -> getManualMove();
            } else {
                pos = {-1, -1};
            }
        } else { // bot move
            pos = currentPlayer.move(gameInfo -> getBoard());
        }
        std::cout << "player " << (currentPlayer.getPlayer() == 1 ? "White" : "Black") << " selected move: " << pos << std::endl;
        gameInfo -> makeMove(pos);
        gameInfo -> printBoard();
        gameInfo -> setHasManualMove(false);
    }
    gameEnd:
    gameInfo -> printWinner();
    
}