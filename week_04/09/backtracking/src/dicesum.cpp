/*
 *      Stanford cs106b Programming Abstractions Winter 2018
 *               Lecture 09
 *              Martin Stepp
 *
 * refs
 *    https://web.stanford.edu/class/cs106b/lectures.shtml
 *    https://www.youtube.com/watch?v=Frr8U5_TTtg
 */

#include <iostream>
#include "vector.h"
using namespace std;
//This returns the number of combinations of targetSum within numDice
//Ex: diceSum(2, 7) = 6 --> {1, 6}, {2, 5}, {3, 4}, {4, 3}, {5, 2}, {6, 1}
int diceSum(int numDice, int targetSum);
int diceSumRec(int currentSum, int targetSum, int index, Vector<int>& dice);

int main() {
    cout << diceSum(2, 7) << endl;
    return 0;
}

int diceSum(int numDice, int targetSum) {
    Vector<int> dice;
    for (int i=0; i < numDice ;i++)
        dice.add(1);
    return diceSumRec(numDice, targetSum, numDice-1, dice);
}

int diceSumRec(int currentSum, int targetSum, int index, Vector<int>& dice) {
    if (index== 0) {
        if ((currentSum < targetSum) && (currentSum + 6 > targetSum))
            return 1;
        else
            return 0;
    } else {
        if (currentSum == targetSum) {

        }
        if (dice[index]<6) {
            dice[index]++;
            currentSum++;
//            if (currentSum == targetSum)
//                return 1+ diceSumRec(currentSum, targetSum, index, dice);
//            else
//                return 0+ diceSumRec(currentSum, targetSum, index, dice);
        } else {
            index--;
            return 0+ diceSumRec(currentSum, targetSum, index, dice);
        }
    }
}







