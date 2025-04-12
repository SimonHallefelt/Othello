#include "../include/Board.hpp"
#include "../include/LegalMoves.hpp"
#include <cassert>


// white is 1 and black is -1

Board::Board() {
    std::cout << "Board was Generated" << std::endl;
    newBoard();
}
Board::~Board() {
    std::cout << "Board was Destroyed" << std::endl;
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
            if (i == -1) std::cout << i << " ";
            else std::cout << " " << i << " ";
        }
        std::cout << std::endl;
    }
};

std::array<std::array<int, 8>, 8> Board::getBoard() const {
    return board;
}

int Board::getPlayersTurn() const {
    return playersTurn;
}

bool Board::gameComplete() {
    if (!getLegalMoves(board, playersTurn).size() && !getLegalMoves(board, playersTurn*-1).size()) return true;
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
    assert(isMoveLegal(board, playersTurn, pos) && !board[pos.y][pos.x]);
    board[pos.y][pos.x] = playersTurn;
    flipAllInBetween(pos);
    playersTurn *= -1;
}

void Board::printWinner() {
    if (!gameComplete()) {
        std::cout << "game is not finished" << std::endl;
        return;
    }
    int sum = 0;
    for (auto row : board) {
        for (auto i : row) {
            sum += i;
        }
    }
    if (sum > 0) std::cout << "White won!" << std::endl;
    else std::cout << "Black won!" << std::endl;
}

// --------------private functions------------------------

void Board::flipAllInBetween(Int2D pos) {
    std::vector<Int2D> positionsCaptured = getPositionsCaptured(board, playersTurn, pos);
    for (const auto& pc : positionsCaptured) {
        board[pc.y][pc.x] = playersTurn;
        std::cout << pc << " ";
    }
    std::cout << std::endl;
}