#include <cmath>
#include <iostream>
#include "console.h"

using namespace std;

//default parameters
void printLine(int width= 10, char letter='*') {
    for (int i=0 ; i< width ; i++) {
        cout << letter;
    }
}
//value semantics: primitive types are passed by values (not effective)
void swapByValue(int a, int b);
//reference semantics: & after types will link the functions to the same place in memory
void swapByRef(int& a, int& b);
//output params
void datingRange(int age, int& min, int& max);

void quadratic(int a, int b, int c, double& r1, double& r2);
int main() {
    cout << "Hello, world!" << endl;
    printLine(1);

    int a= 32, b=17;
    cout << "a= " << a << "b= " << b << "\n" << endl;
    swapByValue(a, b);
    cout << "swapByValue(a,b)\n" << endl;
    cout << "a= " << a << " b= " << b << "\n" << endl;

    cout << "a= " << a << " b= " << b << "\n" << endl;
    cout << "swapByRef(a,b)\n" << endl;
    swapByRef(a, b);
    cout << "a= " << a << " b= " << b << "\n" << endl;

    //Output parameters
    int young;
    int old;
    datingRange(38, young, old);
    cout << "A 38 year-old coukd date someone from"
         << young << " to " << old << " years old." << endl;
    //quadratic
    double root1, root2 ;
    quadratic(1, -3, -4, root1, root2);
    cout << "The roots are " << root1 << " and " << root2 << endl;
    return 0;
}


//value semantics: primitive types are passed by values
//not effective
void swapByValue(int a, int b) {
    int temp=a;
    a=b;
    b=temp;
}
//reference semantics: & after types will link the functions to the same place in memory
void swapByRef(int& a, int& b) {
    int temp=a;
    a=b;
    b=temp;
}

//output params
void datingRange(int age, int& min, int& max) {
    min= age/2 + 7;
    max= (age-7)*2;
}

void quadratic(int a, int b, int c, double& r1, double& r2) {
    double b2 = double(b*b);
    double ac4= double(4*a*c);
    double d=sqrt(b2 - ac4);
    r1 = (-double(b) + d)/ 2.0 * double(a);
    r2 = (-double(b) - d)/ 2.0 * double(a);
}
