/*
 *     cs106b Programming Abstractions - lecture 04 - Winter 2018
 *
 *     Abstract Data types (ADT): Vectors, LinkedLists, Stacks and Queues
 *     ref
 *      https://www.youtube.com/watch?v=_ImwLa34d9I&feature=youtu.be
 */


#include <iostream>
#include "console.h"
#include "stack.h"
using namespace std;

//Balances parenthesis and brackets
//returns the index where it happens -1 otherwise

int checkBalance(string expression);
int main_stacks() {
    cout << "if (a(4)>4) { foo(a(2));}" << endl;
    cout << checkBalance("if (a(4)>4) { foo(a(2));}") << endl;

    cout << "if (a(4)>4) { foo)a(2));}" << endl;
    cout << checkBalance("if (a(4)>4) { foo)a(2));}") << endl;
    return 0;
}

int checkBalance(string expression) {
    Stack<char> stack_p, stack_b;
    int result=-1;
    for (int i=0; i < expression.length(); i++) {
        switch (expression[i]) {
        case '(':
            stack_p.push('(');
            break;
        case ')':
            if (stack_p.isEmpty())
                result=i;
            else
                stack_p.pop();
            break;
        case '{':
            stack_b.push('{');
            break;
        case '}':

            if (stack_b.isEmpty())
                result=i;
            else
                stack_b.pop();
            break;
        default:
            break;
        }
        if (result > -1)
            break;
    }
    if ((result == -1) && (!(stack_b.isEmpty() && stack_p.isEmpty())))
        result=expression.length()-1;
    return result;
}
