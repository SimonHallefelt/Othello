#ifndef Int2D_hpp
#define Int2D_hpp

#include <iostream>

struct Int2D {
    int y;
    int x;

    Int2D(int y, int x);
    ~Int2D();

    void add(Int2D value);

};

std::ostream& operator<<(std::ostream& os, const Int2D& obj);

#endif