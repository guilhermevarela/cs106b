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

void printbinary(int digits);
void printbinaryRec(string binaries, int digits);

int main_printbinary() {
//    printbinary(4);
    return 0;
}

void printbinary(int digits) {
   string binary_sequence="";
   printbinaryRec(binary_sequence, digits);
}

void printbinaryRec(string binseq, int digits) {
    if (digits == 0) {
          cout << binseq  << endl;
    } else {
        printbinaryRec( binseq + "0", digits-1);
        printbinaryRec( binseq + "1", digits-1);
    }
}
