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
int evaluate_rec(string expression, int index);

int main() {
    cout << "evaluate(\"7\") : " << evaluate("7")  << endl;
    cout << "evaluate(\"(2+2)\") : " << evaluate("(2+2)")  << endl;
    cout << "evaluate(\"(1+(2*4))\") : " << evaluate("(1+(2*4))")  << endl;
    cout << "evaluate(\"((1+3)+((2*4)*5))\") : " << evaluate("((1+3)+((2*4)*5))")  << endl;
    return 0;
}

int evaluate(string expression) {

}

int findClosingParanthesis(string exp, int index) {
    int l = exp.length();
    int pos = l;
    for (int i=index+1 ; i < l; i++) {
        if (expression[i] == ')') {
            pos=i;
            break
        }
    }
    return pos
}
int evaluate_rec(string expression, int index) {
    if (ch == '+'){
        return evaluate_rec(expression.substr(0,index-1), index/2) +
                evaluate_rec(expression.substr(index+1,l),(l-index)/2);
    } else if (ch == 'x') {
        return evaluate_rec(expression.substr(0,index-1), index/2) +
                evaluate_rec(expression.substr(index+1,l),(l-index)/2);
    }
   // must be an opening parenthesis
   int pos=findClosingParanthesis(expression, index)
   return evaluate_rec(expression.substr(index, pos) ,(index + pos)/2);
}

//int evaluate_sum(string expression) {
//    if
//    return 0
//}
//int evaluate_multiplication(string expression) {
//    return 0
//}









