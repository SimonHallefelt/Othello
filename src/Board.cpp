#include "../include/Board.hpp"

using namespace std;


// white is 1 and black is -1

Board::Board() {
    cout << "Board was Generated" << endl;
    newBoard();
}
Board::~Board() {
    cout << "Board was Destroyed" << endl;
}

void Board::newBoard() {
    board = {{0}};
    board[3][4] = -1;
    board[4][3] = -1;
    board[3][3] = 1;
    board[4][4] = 1;
    playersTurn = -1; // black moves first
};

void Board::printBoard() const {
    for (auto a : board) {
        for (auto i : a) {
            if (i == -1) cout << i << " ";
            else cout << " " << i << " ";
        }
        cout << endl;
    }
};

array<array<int, 8>, 8> Board::getBoard() const {
    return board;
}

int Board::getPlayersTurn() const {
    return playersTurn;
}