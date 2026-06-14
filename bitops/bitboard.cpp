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

#include <iostream>
#include <cstdint>

using namespace std;

void set(uint64_t &board, int x, int y)
{
    board |= (1ULL << (y * 8 + x));
}

void clear(uint64_t &board, int x, int y)
{
    board &= ~(1ULL << (y * 8 + x));
}

//int read(uint64_t board, int x, int y)
//{
//    return (board & (1ULL << (y * 8 + x))) >> (y * 8 + x);
//}
//A more clever way
bool read(uint64_t board, int x, int y)
{
    return (board & (1ULL << (y * 8 + x)));
}

bool paireval(uint64_t board, int s, int t, int u, int v)
{
    return ((board & (1ULL << (t * 8 + s))) && (board & (1ULL << (v * 8 + u))));
}

int getpair (uint64_t board, int x , int y) 
{
    //return ((board & (1ULL << (y * 8 + x)) << ((y+1) * 8 + (x+1))); 
    //((y+1) * 8 + (x+1))
    return (board & (1ULL << (y * 8 + (x-1)))); //<< ((y+1) * 8 + (x+1)));
}   

//a simpler challenge: are there two consecutive 1s in a 64-bit integer (not a grid)
bool consecutive_ones(uint64_t number)
{
    return (number & (number >> 1));
}
//challenge 2: Make a function which determines if any two neighboring bits are both ones on that 8x8 grid
bool checkneighbor (uint64_t board)
{
    int horizontal = board & (board >> 1);
    int vertical = board & (board >> 8); //vertical neighbors are 8 bits apart
    return (horizontal | vertical);
}

void print(uint64_t index)
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
    
    uint64_t board = 0ULL; //initialize as empty
    //for (int y = 7; y >=0; y--){
    //    for (int x = 0; x < 8; x++){
    //        set(board, x, y);
    //    }
    //}
    set(board, 0, 0);
    set(board, 4, 4);
    set(board, 7, 7);
    set(board, 6, 7);
    print(board);
    //test
    //print(read(board, 7, 7));
    //print(paireval(board, 7, 7, 4, 4));
    //print(getpair(board, 7, 7));
    print(checkneighbor(board));
    return 0;
}
