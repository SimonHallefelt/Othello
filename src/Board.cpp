#include "../include/Board.hpp"

using namespace std;

Board::Board() {
    cout << "Board was Generated" << endl;
    newBoard();
}
Board::~Board() {
    cout << "Board was Destroyed" << endl;
}

void Board::newBoard() {
    board = {{0}};
};

void Board::printBoard() const {
    for (auto a : board) {
        for (auto i : a) {
            cout << i << " ";
        }
        cout << endl;
    }
};
