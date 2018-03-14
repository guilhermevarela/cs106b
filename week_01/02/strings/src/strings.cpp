#include <iostream>
#include <string>
#include "console.h"
#include "strlib.h"
#include "simpio.h"
using namespace std;

/*
 * V
 * VA
 * VAR
 * VARE
 * VAREL
 * VARELA
 *  ARELA
 *   RELA
 *    ELA
 *     LA
 *      A
 */
void nameDiamond(string name) {
    for (int i=0; i < name.length(); i++)
        cout << name.substr(0,i+1) <<  endl;
    for (int i=0; i < name.length(); i++){
        for (int j=0; j < i+1; j++)
            cout << " ";
        cout << name.substr(i+1) << endl;
    }
}
int main() {
    string name= "Guilherme Varela";
    cout << name  << "\n" << endl;
    cout <<  "npos is " << string::npos << "\n" << endl;

    cout << toUpperCase(name) << endl;

    string ageStr = "37";
    cout << "plus ten years " << (stringToInteger(ageStr) + 10 )  << "\n" << endl;


    name= getLine("What's your name ?\n");
    if (name.compare( "Guilherme")==0) {
        cout << "You're the best\n" << endl;
    }else{
        cout << "Got nothing else to ask\n" << endl;
    }
    nameDiamond("VARELA");
    return 0;
}
