/*
 *      Stanford cs106b Programming Abstractions Winter 2018
 *               Lecture 09
 *              Martin Stepp
 *
 * refs
 *    https://web.stanford.edu/class/cs106b/lectures.shtml
 *    https://www.youtube.com/watch?v=Frr8U5_TTtg
 */
#include <iostream>
#include "console.h"
using namespace std;

void printBinary(int digits);
string printBinaryRec(string binaries, int digits);

int main() {
    printBinary(4);
    return 0;
}

void printBinary(int digits) {
    string prefix="";
    string sequence= printBinaryRec(prefix, digits-1);
    cout << sequence + "0" << endl;
    cout << sequence + "1" << endl;

}

void printBinaryRec(string binaries, int digits) {
    if (digits == 1) {
          return binaries;
    } else {
        cout << printBinaryRec( "0" + binaries, digits-1);
        cout << printBinaryRec( "1" + binaries, digits-1);
    }
}
