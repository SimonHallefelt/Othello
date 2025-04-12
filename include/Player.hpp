#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include "Int2D.hpp"
#include "LegalMoves.hpp"

class Player
{
private:
    const int player;
    int playerType;

public:
    Player(const int player, int playerType);
    ~Player();

    int getPlayer() const;
    int getPlayerType() const;
    void setPlayerType(int pt);
    Int2D move(std::array<std::array<int, 8>, 8>& board) const;
};

#endif