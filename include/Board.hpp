#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <iostream>

class Board {
    private:
        std::array<std::array<int, 8>, 8> board;
        int playersTurn;
    
    public:
        Board();
        ~Board();
    
        void newBoard();
        void printBoard() const;

        std::array<std::array<int, 8>, 8> Board::getBoard() const;
        int Board::getPlayersTurn() const;
        bool Board::gameComplete();
    };

#endif