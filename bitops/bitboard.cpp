// & = Bitwise AND (1 if both bits are 1)
// | = Bitwise OR (1 if at least one bit is 1)
// ^ = Bitwise XOR (1 if bits are different)
// ~ = Bitwise NOT (Inverts bits)
// << = Left shift, filling vacancies with 0's
// >> = Right shift
// y * 8 + x index formula translates an 8x8 grid into a 1-dimensional sequence from 0 to 63
//remark: y*8 to jump to the right row, + x to move along that row.
// 1ULL << (y * 8 + x) mask: single 1 at target position

#include <iostream>
#include <cstdint>

using namespace std;

typedef uint64_t Bitboard;

void set(Bitboard &board, int x, int y)
{
    board |= (1ULL << (y * 8 + x));
}

void clear(Bitboard &board, int x, int y)
{
    board &= ~(1ULL << (y * 8 + x));
}

int read(Bitboard board, int x, int y)
{
    return (board & (1ULL << (y * 8 + x))) >> (y * 8 + x);
}


void print(Bitboard index)
{
    for (int y = 7; y >= 0; y--) { //row 7 to row 0
        for (int x = 0; x < 8; x++) { //col 0 to 7
            if (index & (1ULL << (y * 8 + x))) {
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
    
    Bitboard board = 0ULL; //initalize as empty

    set(board, 0, 0);
    set(board, 3, 4);
    set(board, 8, 9);
    print(board);
    return 0;
}
