#include <iostream>

void printBits(unsigned char byte)
{
    for (int i = 7; i >= 0; i--)
    {
        std::cout << ((byte >> i) & 1);
    }
}

unsigned char set(unsigned char word, int n)
{
    unsigned char mask = 1 << n; // 00000001, shifted left by n
    
    std::cout << "Mask: ";
    printBits(mask);
    std::cout << std::endl;

    return word | mask; // [1] when a and/or b = one, otherwise [0]
}

unsigned char clear(unsigned char word, int n)
{
    unsigned char mask = 1 << n; // 00000001, shifted left by n
    mask = ~ mask; // Swap value

    std::cout << "Mask: ";
    printBits(mask);
    std::cout << std::endl;

    return word & mask; // [1] when a and b = one, otherwise [0]
}

unsigned char toggle(unsigned char word, int n)
{
    unsigned char mask = 1 << n; // 00000001 shifted left by n

    std::cout << "Mask: ";
    printBits(mask);
    std::cout << std::endl;

    return word ^ mask; //XOR: [1] when strictly a or b = one, otherwise [0]
}

unsigned char read(unsigned char word, int n)
{
    unsigned char mask = 1 << n; // shift 1 to target
    
    std::cout << "Mask:   ";
    printBits(mask);
    std::cout << std::endl;

    return (word & mask) >> n; // AND target with the 1, then shift back
}

int main()
{
    unsigned char word = 0b10110011; 
    std::cout << "Before: ";
    printBits(word);
    std::cout << std::endl;

    //word = set(word, 3);
    //word = clear(word, 4);
    //word = toggle(word, 1);
    unsigned char bit = read(word, 6);
    std::cout << "Bit 6:  ";
    printBits(bit);

    //std::cout << "After:  ";
    //printBits(word);
    std::cout << std::endl;

    return 0;
}

// & = Bitwise AND (1 if both bits are 1)
// | = Bitwise OR (1 if at least one bit is 1)
// ^ = Bitwise XOR (1 if bits are different)
// ~ = Bitwise NOT (Inverts bits)
// << = Left shift, filling vacancies with 0's
// >> = Right shift
// y * 8 + x index formula translates an 8x8 grid into a 1-dimensional sequence from 0 to 63
//remark: y*8 to jump to the right row, + x to move along that row.
// 1ULL << (y * 8 + x) mask: single 1 at target position
//https://tearth.dev/bitboard-viewer/