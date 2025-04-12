#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <iostream>
#include <Int2D.hpp>

class Board {
    private:
        std::array<std::array<int, 8>, 8> board;
        int playersTurn;
    
        void flipAllInBetween(Int2D pos);
    public:
        Board();
        ~Board();
    
        void newBoard();
        void printBoard() const;

        std::array<std::array<int, 8>, 8> getBoard() const;
        int getPlayersTurn() const;
        bool gameComplete();
        void makeMove(Int2D pos);
        void printWinner();
    };

#endif