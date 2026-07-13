#ifndef C4_H
#define C4_H
#include <iostream>
#include <cstdint>
#include <random>

inline std::mt19937 gen(std::random_device{}());

//challenge 4: Use a bitboard to estimate the ans:
// "On an 8x8 chess board you randomly place a coin on each cell independently, with probability 1/2 or leave it empty.
//What is the probability that all rows and columns have an even number of coins placed on them?""


// first step will be to write a function that sets each cell on the board with p=1/2
inline uint64_t randomnumber(){
    std::uniform_int_distribution<uint64_t> d(0, 1);
    return d(gen);
}
//with unif[0,1] rng, best solution was just to build the board by using the random numbers generated
inline void randomset (uint64_t &board)
{
    for (int y = 7; y >= 0; y--) {
        for (int x = 0; x < 8; x++) {
            //uint64_t random_number = randomnumber();
            //std::cout << random_number << std::endl;
            board |= (randomnumber() << (y * 8 + x));
        }
    }
}
//same thing, just 1 index variable
// inline uint64_t randomset2 (uint64_t &board){
//     for (int i=0;i<64;i++){
//         board |= (randomnumber() << i);
//     }
//     return board;
// }

//part 2: I can estimate the answer via monte carlo simulation


#endif