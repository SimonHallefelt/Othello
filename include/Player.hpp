#ifndef Player_hpp
#define Player_hpp

#include <iostream>

class Player
{
private:
    const int player;

public:
    Player(const int player);
    ~Player();

    int getPlayer() const;
};

#endif