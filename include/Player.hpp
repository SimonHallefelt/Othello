#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include "Int2D.hpp"
#include "LegalMoves.hpp"

class Player
{
private:
    const int player;

public:
    Player(const int player);
    ~Player();

    int getPlayer() const;
    Int2D move(std::array<std::array<int, 8>, 8> board);
};

#endif