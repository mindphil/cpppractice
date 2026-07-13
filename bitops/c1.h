#ifndef C1_H
#define C1_H
#include <cstdint>

//Make a 64-bit bitboard representing an 8x8 grid, 
// and make functions to read and set a coordinate pair

//inline int read(uint64_t board, int x, int y)
//{
//    return (board & (1ULL << (y * 8 + x))) >> (y * 8 + x);
//}

//A more clever way to read
inline bool read(uint64_t board, int x, int y)
{
    return (board & (1ULL << (y * 8 + x)));
}

inline void set(uint64_t &board, int x, int y)
{
    board |= (1ULL << (y * 8 + x));
}

//not part of the challenge, but helpful practice
// inline void clear(uint64_t &board, int x, int y)
// {
//     board &= ~(1ULL << (y * 8 + x));
// }

#endif

