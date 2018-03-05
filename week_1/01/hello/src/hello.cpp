#include <iostream>
#include "console.h"
#include "simpio.h"
using namespace std;

int main() {
    cout << "Hello, world!" << endl;
    int age = getInteger("What's your age again?\n");
    cout << "So you're " << age << " years old?! How cool is it?" << endl;
    return 0;
}
