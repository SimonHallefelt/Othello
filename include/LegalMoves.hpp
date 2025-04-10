#ifndef LegalMoves_hpp
#define LegalMoves_hpp

#include <array>

bool isMoveLegal(const std::array<std::array<int, 8>, 8>& board, const int player , const int y, const int x);

std::array<std::array<bool, 8>, 8> getLegalMoves(const std::array<std::array<int, 8>, 8>& board, int player);

#endif
