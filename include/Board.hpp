#ifndef BOARD_HPP
#define BOARD_HPP

#include <array>
#include <iostream>

class Board {
    private:
        std::array<std::array<int, 8>, 8> board;
    
    public:
        Board();
        ~Board();
    
        void newBoard();
        void printBoard() const;
    };

#endif