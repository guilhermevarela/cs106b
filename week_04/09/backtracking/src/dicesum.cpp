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
//Ex: diceSum(3, 7) = 15
int diceSum(int numDice, int targetSum);
int diceSum2(int numDice, int targetSum);
int diceSumRec(int targetSum, int index, Vector<int> dices);
void diceSumRec2(int targetSum, int index, Vector<int>& dices, int& result);
int sumDiceRolls(Vector<int> dices);

int main() {
    cout << diceSum2(2, 3) << endl;
    return 0;
}

int diceSum(int numDice, int targetSum) {
    Vector<int> dices;
    for (int i=0; i < numDice ;i++)
        dices.add(1);
    return diceSumRec(targetSum, numDice-1, dices);
}

int diceSum2(int numDice, int targetSum) {
    Vector<int> dices;
    int result=0;

    for (int i=0; i < numDice ;i++)
        dices.add(1);
    diceSumRec2(targetSum-numDice, numDice-1, dices, result);
    return result;
}

int sumDiceRolls(Vector<int> dices) {
    int sum=0;
    for (int i=0; i < dices.size(); i++)
        sum+= dices[i];
    return sum;
}
//No backtracking needed actually
int diceSumRec(int targetSum, int index, Vector<int> dices) {
    int sum = sumDiceRolls(dices);
    int victory = (sum == targetSum) ? 1 : 0;
    int c1, c2, c3, c4, c5, c6;
    //standard recursion: explore
    if ((index > -1)  && (victory == 0)) {
            //first time it comes over here test configuration
            c1 =  victory + diceSumRec(targetSum, index-1, dices);
            dices[index]++;
            c2 =  victory + diceSumRec(targetSum, index-1, dices);
            dices[index]++;
            c3 =  victory + diceSumRec(targetSum, index-1, dices);
            dices[index]++;
            c4 =  victory + diceSumRec(targetSum, index-1, dices);
            dices[index]++;
            c5 =  victory + diceSumRec(targetSum, index-1, dices);
            dices[index]++;
            c6 =  victory + diceSumRec(targetSum, index-1, dices);

    } else {
        //base case nothing else to do
        return victory;
    }
    return c1 + c2 + c3 + c4 + c5 + c6;
}


void diceSumRec2(int targetSum, int index, Vector<int>& dices, int& result) {
    if (index < 0) {
     //Stop everything
    } else  {
        if ((dices[index] > 0) && (dices[index] < 6)){
            cout << dices << endl;
            if (targetSum ==0)
                result++;

            dices[index]++;
            diceSumRec2(targetSum-1,index, dices, result);
            dices[index]--;
        }
        index--;
        diceSumRec2(targetSum, index,  dices, result);
    }
}




