#ifndef LegalMoves.hpp
#define LegalMoves.hpp

#include <array>

std::array<std::array<bool, 8>, 8> getLegalMoves(const std::array<std::array<bool, 8Ui64>, 8Ui64> board, int player);

bool isMoveLegal(const std::array<std::array<int, 8>, 8>& board, const int player , const int y, const int x);

#endif
