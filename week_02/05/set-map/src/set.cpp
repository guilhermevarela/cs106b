/*
 *                  Stanford CS106b
 *          Programming Abstractions - Winter 2018
 *              Lecture 05 - Sets and Maps
 *                  Martin Stepp
 *
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include "vector.h"
#include "timer.h"
#include "set.h"
#include "hashset.h"
using namespace std;

//function prototype declarations
//bool contains(const Vector<string>& v, const string& s);
void wordCount(const string& filename);
void occurenceCount(const string& filename);

int main_set() {
    wordCount("mobydick.txt");
    return 0;
}

/*
 * Reads all words from a file and counts how many are contained in the file
 * using set.
 *
 */


void wordCount(const string& filename) {
    //    mobydick.txt
    //    It took 6458 ms. File contains 18626 unique words
    //    Vector<string> vector;

    //    mobydick.txt
    //    It took 277 ms. File contains 18626 unique words
    //    Set<string> set;

    //    mobydick.txt
    //    It took 138 ms. File contains 18626 unique words
    //    HashSet<string> set;
    HashSet<string> set;
    ifstream input;
    string word;


    cout << "Reading " << filename << " ..." << endl;
    Timer timer;
    timer.start();

    //TODO
    //read unique words from file into a collection
    input.open(filename);
    while(input >> word) {
        word = toLowerCase(word);
        set.add(word);
    }


    //TODO
    cout << "It took " << timer.stop() << " ms." << endl;
    cout << "File contains " << set.size() << " unique words" << endl;
//    loop over a set
//    for (word :: set) {
//    }

}
