#ifndef C2_H
#define C2_H
#include <cstdint>

//Make a function which determines if any two neighboring bits are both ones on that 8x8 grid

//attempt to eval two distinct coordinate pairs, I can't remember if this worked as intended.
//bool paireval(uint64_t board, int s, int t, int u, int v)
// {
//     return ((board & (1ULL << (t * 8 + s))) && (board & (1ULL << (v * 8 + u))));
// }

//helped get an understanding of navigating the board iirc
// inline int getpair (uint64_t board, int x , int y) 
// {
//     //return ((board & (1ULL << (y * 8 + x)) << ((y+1) * 8 + (x+1))); 
//     //((y+1) * 8 + (x+1))
//     return (board & (1ULL << (y * 8 + (x-1)))); //<< ((y+1) * 8 + (x+1)));
// }   

//broke it down into a simpler challenge: are there two consecutive 1s in a 64-bit integer (not a grid)
// inline bool consecutive_ones(uint64_t number)
// {
//     return (number & (number >> 1));
// }

//final challenge 2 function
inline bool checkneighbor (uint64_t board)
{
    uint64_t horizontal = board & (board >> 1);
    uint64_t vertical = board & (board >> 8); //vertical neighbors are 8 bits apart
    return (horizontal | vertical);
}

#endif