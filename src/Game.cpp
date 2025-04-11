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
    Player playerBlack(-1, 0), playerWhite(1, 0);

    board.printBoard();
    while (!board.gameComplete()) {
        Int2D pos = board.getPlayersTurn() == 1 ? playerWhite.move(board.getBoard()) : playerBlack.move(board.getBoard());
        cout << "player " << (board.getPlayersTurn() == 1 ? "White" : "Black") << " selected move: " << pos << endl;
        board.makeMove(pos);
        board.printBoard();
    }
    
}