#include "../include/Board.hpp"
#include "../include/LegalMoves.hpp"
#include <cassert>

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
    for (auto row : board) {
        for (auto i : row) {
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

bool Board::gameComplete() {
    for (auto row : board) {
        for (auto i : row) {
            if (!i) return false;
        }
    }
    return true;
}

void Board::makeMove(const Int2D pos) {
    if (pos.y == -1 && pos.x == -1) { // cant make a move
        playersTurn *= -1;
        return;
    }
    assert(isMoveLegal(board, playersTurn, pos));
    board[pos.y][pos.x] = playersTurn;
    flipAllInBetween(pos);
    playersTurn *= -1;
}

void Board::printWinningPlayer() {
    if (!gameComplete()) {
        cout << "game is not finished" << endl;
        return;
    }
    int sum = 0;
    for (auto row : board) {
        for (auto i : row) {
            sum += i;
        }
    }
    if (sum > 0) cout << "White won!" << endl;
    else cout << "Black won!" << endl;
}

// --------------private functions------------------------

void Board::flipAllInBetween(Int2D pos) {
    vector<Int2D> positionsCaptured = getPositionsCaptured(board, playersTurn, pos);
    for (const auto& pc : positionsCaptured) {
        board[pc.y][pc.x] = playersTurn;
        cout << pc << " ";
    }
    cout << endl;
}