#include "../include/Int2D.hpp"

Int2D::Int2D(int y, int x) : y(y), x(x) {}
Int2D::~Int2D() {}

void Int2D::add(Int2D value) {
    this->y += value.y;
    this->x += value.x;
}