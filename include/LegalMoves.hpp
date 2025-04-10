#ifndef LegalMoves_hpp
#define LegalMoves_hpp

#include <array>
#include <vector>
#include "../include/Int2D.hpp"

bool isMoveLegal(const std::array<std::array<int, 8>, 8>& board, const int player , const Int2D startPos);

std::vector<Int2D> getLegalMoves(const std::array<std::array<int, 8>, 8>& board, int player);

#endif
