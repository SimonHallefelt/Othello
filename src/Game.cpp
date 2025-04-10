#include "../include/Board.hpp"
#include "../include/LegalMoves.hpp"
#include "../include/Player.hpp"
#include "../include/Int2D.hpp"
#include <iostream>
#include <vector>
using namespace std;

void startGame() {
    cout << "Start Game!" << endl;
    Board board;
    board.printBoard();
    vector<Int2D> possibleMoves = getLegalMoves(board.getBoard(), board.getPlayersTurn());
    cout << "possibleMoves" << endl;
    for (Int2D& pos : possibleMoves) {
        cout << pos << ", ";
    }
    cout << endl;
    Player playerBlack(-1), playerWhite(1);
    cout << "playerBlack " << playerBlack.getPlayer() << endl;
    cout << "playerWhite " << playerWhite.getPlayer() << endl;

    while (!board.gameComplete()) {
        Int2D pos = board.getPlayersTurn() == 1 ? playerWhite.move(board.getBoard()) : playerBlack.move(board.getBoard());
        cout << "player " << board.getPlayersTurn() << " selected move: " << pos << endl;
        break;
    }
    
}