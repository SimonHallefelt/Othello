#include <../include/GameInfo.hpp>
#include <cassert>

GameInfo::GameInfo() : blackPlayer(-1, 1), whitePlayer(1, 0), manualMove(-1, -1), stopGame(0) {
    std::cout << "Created GameInfo" << std::endl;
}

GameInfo::~GameInfo() {
    std::cout << "Created GameInfo" << std::endl;
}

std::array<std::array<int, 8>, 8> GameInfo::getBoard() const {
    return board.getBoard();
}
void GameInfo::newBoard() {
    board.newBoard();
}
void GameInfo::printBoard() const {
    board.printBoard();
}
int GameInfo::getPlayersTurn() const {
    return board.getPlayersTurn();
}
bool GameInfo::gameComplete() {
    return board.gameComplete();
}
void GameInfo::makeMove(Int2D pos) {
    board.makeMove(pos);
}
void GameInfo::printWinner() {
    board.printWinner();
}

const Player& GameInfo::getCurrentPlayer() {
    return board.getPlayersTurn() == 1 ? whitePlayer : blackPlayer;
}

void GameInfo::setManualMove(Int2D pos) {
    assert(pos.x >= 0 && pos.x < 8 && pos.y >= 0 && pos.y < 8);
    if (!isMoveLegal(board.getBoard(), board.getPlayersTurn(), pos)) return;
    manualMove = pos;
    hasManualMove = true;
}

void GameInfo::setHasManualMove(bool b) {
    hasManualMove = b;
}

Int2D GameInfo::getManualMove() const {
    return manualMove;
}

bool GameInfo::getHasManualMove() const {
    return hasManualMove;
}

void GameInfo::setStopGame() {
    stopGame = true;
}
bool GameInfo::getStopGame() const {
    return stopGame;
}