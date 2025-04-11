#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <iostream>
#include <Int2D.hpp>

class Board {
    private:
        std::array<std::array<int, 8>, 8> board;
        int playersTurn;
    
        void Board::flipAllInBetween(Int2D pos);
    public:
        Board();
        ~Board();
    
        void newBoard();
        void printBoard() const;

        std::array<std::array<int, 8>, 8> Board::getBoard() const;
        int Board::getPlayersTurn() const;
        bool Board::gameComplete();
        void Board::makeMove(Int2D pos);
        void Board::printWinner();
    };

#endif