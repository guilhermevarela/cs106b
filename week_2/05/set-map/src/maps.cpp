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
#include "map.h"
#include "hashmap.h"
#include "timer.h"
using namespace std;

//function prototype declarations
void occurenceCount(const string& filename);

int main() {
    occurenceCount("mobydick.txt");
    return 0;
}

/*
 * Reads all words from a file and counts how many are contained in the file
 * using set.
 *
 */


void occurenceCount(const string& filename) {
// MAP
//    Reading mobydick.txt ...
//    It took 423 ms.
//    File contains 18626 unique words
//    File contains 7018 times the word the

//    Map<string, int> map;
//    Reading mobydick.txt ...
//    It took 149 ms.
//    File contains 18626 unique words
//    File contains 7018 times the word the
    HashMap<string, int> map;
    ifstream input;
    string word;

    cout << "Reading " << filename << " ..." << endl;
    Timer timer;
    timer.start();


    input.open(filename);
    while(input >> word) {
        word = toLowerCase(word);
        map[word]++;
//        if (map.containsKey(word)){
//            map[word]+=1;
//        } else {
//            map[word]=1;
//        }
    }


    //TODO
    cout << "It took " << timer.stop() << " ms." << endl;
    cout << "File contains " << map.size() << " unique words" << endl;
    cout << "File contains " << map["the"] << " times the word """ << "the" << """"<< endl;

}
