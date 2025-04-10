#ifndef Int2D_hpp
#define Int2D_hpp

struct Int2D {
    int y;
    int x;

    Int2D(int y, int x);
    ~Int2D();

    void add(Int2D value);
};

#endif