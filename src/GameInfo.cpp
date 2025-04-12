#include <../include/GameInfo.hpp>

GameInfo::GameInfo() : blackPlayer(-1, 1), whitePlayer(1, 1), manualMove(-1, -1) {
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