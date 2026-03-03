#include <iostream>
// #include <cstdlib>

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