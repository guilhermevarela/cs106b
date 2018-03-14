/*
 * cs106b - Programming Abstractions 2018 Winter
 *                  Martin Stepp
 *
 *          LECTURE 03 # streams vector grid
 * ref .:
 *  https://web.stanford.edu/class/cs106b/lectures.shtml
 *  https://www.youtube.com/watch?v=zy9kJvOGtGk
 *
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include "strlib.h"
#include "vector.h"
using namespace std;

int main() {
    ifstream input;

    // first pattern to read iterate line by line on a loop
    input.open("carrol.txt");
    if (input.fail()) {
     cout << "Lumpa lumpa";
    } else {
        string line;
        while (getline(input, line)) {
            cout <<  "here is a line " << endl;
            cout << line << endl;
        }
    }
    input.close();

    // second pattern to read pop those suckers out
    Vector<string> allWords;
    input.open("dias.txt");
    if (input.fail()) {
        cout << "Tchan tchan";
     } else {
        string token;
        while (input >>token ) {
            cout << token << endl;
            allWords.add(token);
        }
      }
      cout << "number of tokens is "<< allWords.size() << endl;
      cout << "tokens "<< allWords.toString() << endl;
     input.close();
    return 0;
}
