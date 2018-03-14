/*
 *  Stanford's CS106b Programming Abstractions
 *          Marty Stepp
 *          Lecture 08
 *
 *  refs:
 *  https://www.youtube.com/watch?v=gCVzZDVDvvo&feature=youtu.be
 *  https://web.stanford.edu/class/cs106b/lectures.shtml
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "random.h"
#include "gwindow.h"
#include "gobjects.h"
#include "gevents.h"


using namespace std;
void cantorSet(GWindow& window, int x, int y, int length, int levels);
void kochSnowflake(GWindow& window, int x, int y, int size, int levels);
void boxyFractal(GWindow& gw, int x, int y, int size, int order);
int main_fractals() {
    GWindow window(800, 600);

    window.setWindowTitle("CS 106B/X Fractals");
//       boxyFractal(window, 200, 200, 300, 3);
        cantorSet(window, 50, 50, 700, 7);
    //   kochSnowflake(window, 200, 200, 400, 4);
    return 0;
}

void boxyFractal(GWindow& gw, int x, int y, int size, int order) {
    if ( order >= 0 ) {
        boxyFractal(gw, x-size/2, y-size/2, size/2, order-1);

        boxyFractal(gw, x+size/2, y+size/2, size/2, order-1);

        gw.fillRect(x, y, size, size);

        boxyFractal(gw, x+size/2, y-size/2, size/2, order-1);

        boxyFractal(gw, x-size/2, y+size/2, size/2, order-1);
    }
}


void cantorSet(GWindow& window, int x, int y, int length, int levels) {
    if ( levels > 0 ) {
        int d  = length /3;
        cantorSet(window, x, y + 30, d, levels-1);

        window.fillRect(x, y, length, 10);

        cantorSet(window, x + 2*d, y + 30, d, levels-1);

    }

}
