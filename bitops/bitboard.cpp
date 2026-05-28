// & = Bitwise AND (1 if both bits are 1)
// | = Bitwise OR (1 if at least one bit is 1)
// ^ = Bitwise XOR (1 if bits are different)
// ~ = Bitwise NOT (Inverts bits)
// << = Left shift, filling vacancies with 0's
// >> = Right shift

#include <iostream>
#include <cstdint>

using namespace std;

typedef uint64_t Bitboard;

Bitboard grid(int k)
{

}

void print_board(Bitboard index) {
    for (int i = 7; i >= 0; i--) { //row 7 to row 0
        for (int j = 0; j < 8; j++) {
            if (index & (1ULL << (i * 8 + j))) { //The index formula translates an 8x8 grid into a 1-dimensional sequence from 0 to 63
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    
    //set some bits

    return 0;
}
