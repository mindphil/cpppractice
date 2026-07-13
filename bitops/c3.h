#ifndef C3_H
#define C3_H
#include <cstdint>

//challenge 3: Make a function which determines if there is a one in every row on that 8x8 grid
inline int checkrow (uint64_t board)
{   
    for (int y = 7; y>= 0; y--){
        uint64_t mask = 0ULL;
        for (int x = 0; x < 8; x++){
            mask |= 1ULL << (y * 8 + x);
        }
        if ((mask & board) == 0ULL){
            return (0ULL);}
    }
    return(1ULL);
}

#endif