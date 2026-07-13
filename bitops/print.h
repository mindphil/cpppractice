#ifndef PRINT_H
#define PRINT_H
#include <cstdint>
#include <iostream>

inline void print(uint64_t index)
{
    for (int y = 7; y >= 0; y--) { //row 7 to row 0
        for (int x = 0; x < 8; x++) { //col 0 to 7
            if (index & (1ULL << (y * 8 + x))) {
                std::cout << "1 ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
#endif