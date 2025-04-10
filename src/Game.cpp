#include "../include/Board.hpp"
#include "../include/LegalMoves.hpp"
#include "../include/Player.hpp"
#include <iostream>
using namespace std;

void startGame() {
    cout << "Start Game!" << endl;
    Board board;
    board.printBoard();
    array<array<bool, 8>, 8> possibleMoves = getLegalMoves(board.getBoard(), board.getPlayersTurn());
    cout << "possibleMoves" << endl;
    for (auto row : possibleMoves) {
        for (auto b : row) {
            cout << b << " ";
        }
        cout << endl;
    }
    Player playerBlack(-1), playerWhite(1);
    cout << "playerBlack " << playerBlack.getPlayer() << endl;
    cout << "playerWhite " << playerWhite.getPlayer() << endl;
}