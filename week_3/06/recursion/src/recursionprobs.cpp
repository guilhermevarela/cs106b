/*
 *  Stanford's CS106b Programming Abstractions
 *          Marty Stepp
 *          Lecture 06
 *
 *  refs:
 *  https://www.youtube.com/watch?v=xkoZY2sXo_c&feature=youtu.be
 *  https://web.stanford.edu/class/cs106b/lectures.shtml
 */

#include <iostream>
#include "console.h"
#include "strlib.h"

using namespace std;
//function prototypes declarations
void printStars(int n);
int power(int base, int exp);
bool isPalindrome(string s);
void printBinary(int n);
int mystery(int n);
int mystery2(int n);

void test_power(int base, int exp);
void test_isPalindrome(string s);
int factorial(int n);

int main() {

    int f = factorial(5);
    cout << "factorial(5): " << f << endl;

    int m = mystery(348);
    cout << "mystery(348): " << m << endl;

    cout << "isPalindrome('madam'): "   << isPalindrome("madam") << endl;
    cout << "isPalindrome('racecar'): " << isPalindrome("racecar") <<  endl;
    cout << "isPalindrome('byebye'): "  << isPalindrome("byebye") <<  endl;

    return 0;
}

int factorial(int n) {
    if ((n == 0 ) || (n == 1)) {
        //base case
        return 1;
    } else {
        // recursive case
        return n* factorial(n-1);
    }
}
//SPOILER: sturtter digits
int mystery(int n) {
    if (n < 10) {
        return (10*n) +n;
    } else {
        int a = mystery(n /10);
        int b = mystery(n % 10);
        return (100 * a) + b;
    }
}

bool isPalindrome(string s) {
    long l = s.length();
    if ( l == 1 ||  l == 0) {
        return true;
    } else {

        char first= s[0];
        char last=  s[l-1];
        return (first == last && isPalindrome(s.substr(1,l-2)));
    }
}



