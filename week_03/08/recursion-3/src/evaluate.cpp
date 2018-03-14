/*
 *  Stanford's CS106b Programming Abstractions
 *          Marty Stepp
 *          Lecture 08 - evaluate exercise
 *
 *  refs:
 *  https://www.youtube.com/watch?v=gCVzZDVDvvo&feature=youtu.be
 *  https://web.stanford.edu/class/cs106b/lectures.shtml
 *
 */

#include <iostream>
#include "strlib.h"
using namespace std;
//evaluate("7") --> 7
//evaluate("(2+2)") --> 4
//evaluate("(1+(2*4))") --> 9
//evaluate("((1+3)+((2*4)*5))") --> 9
int evaluate(string expression);
int evaluate_rec(const string& expression, int& index);

int main() {
    cout << "evaluate(\"7\") : " << evaluate("7")  << endl;
    cout << "evaluate(\"(2+2)\") : " << evaluate("(2+2)")  << endl;
    cout << "evaluate(\"(1+(2*4))\") : " << evaluate("(1+(2*4))")  << endl;
    cout << "evaluate(\"((1+3)+((2*4)*5))\") : " << evaluate("((1+3)+((2*4)*5))")  << endl;
    return 0;
}

int evaluate(string expression) {
    int index= 0;
    return evaluate_rec(expression, index);
}


int evaluate_rec(const string& expression, int& index) {
    char ch= expression[index];
    if  (ch == '(') {
        index++; //move past (
        int left= evaluate_rec(expression, index);
        char opr = expression[index];
        index++;
        int right= evaluate_rec(expression, index);
        index++; //move from ) character
        if (opr == '+') {
            return left + right;
        } else {
            return left * right;
        }
    } else  {
        index++;
        return charToInteger(ch);
    }
}







