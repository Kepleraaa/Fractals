/*
 * FILE: CANTOR FRACTALS
 * ---------------------
 * This program draws a Cantor Fractal of a constant depth on the screen.
 * A Cantor fractal of depth N is a thick horizontal line on top, with
 * a depth N-1 Cantor fractal below the left third, and a depth N-1 Cantor
 * fractal below the right third, of the drawn line.
 */

#include <math.h>
#include "gwindow.h"
#include "gobjects.h"
#include "simpio.h"
#include "fractals.h"

using namespace std;

// display constants
static const int LEVEL_HEIGHT = 20;
static const int RECT_HEIGHT = 10;
static const int INSET = 20;
static const int CANTOR_ORDER = 6;

/* Function: Draw Cantor
 * ---------------------
 * A recursive function that draws a Cantor Fractal between points
 * "left" and "right." The fractal will have "level" numbers of levels.
 */
void drawCantor(GWindow &window, int order, GPoint left, GPoint right) {
    /* TODO: Implement the Cantor Set drawing function. */
    if (order==1)
    {
        drawThickLine(window,left,right);
    }
    else
    {
        drawThickLine(window,left,right);
        GPoint p1=getLoweredPoint(left);
        GPoint p2=getLoweredPoint(pointBetween(left,right,1.0/3));
        GPoint p3=getLoweredPoint(pointBetween(left,right,2.0/3));
        GPoint p4=getLoweredPoint(right);
        drawCantor(window,order-1,p1,p2);
        drawCantor(window,order-1,p3,p4);
    }
}

/* PROVIDED HELPER FUNCTIONS */

/* Function: pointBetween
 * ---------------------
 * Given two points and a franction (assumed to be in the range
 * [0, 1], the function returns the point "fraction" amount of the
 * way between p1 and p2.
 */
GPoint pointBetween(GPoint p1, GPoint p2, double fraction) {
    double deltaX = p2.x - p1.x;
    double deltaY = p2.y - p1.y;
    double x = p1.x + fraction * deltaX;
    double y = p1.y + fraction * deltaY;
    GPoint newPoint(x, y);
    return newPoint;
}


/* Function: Draw Thick Line
 * ---------------------
 * Because sometimes thin lines just don't look good enough in
 * a lecture demo. Actually draws a rectangle instead of a line :)
 */
void drawThickLine(GWindow &window, GPoint left, GPoint right) {
    double width = right.x - left.x;
    // this is called a pointer. We will learn about them later.
    GRect *rect = new GRect(0, 0, width, RECT_HEIGHT);
    rect->setFilled(true);
    cout << left << ", " << right << endl;
    window.add(rect, left.x, left.y);
}

/* Function: Get Lowered Point
 * ---------------------
 * Returns a GPoint which is LEVEL_HEIGHT pixels lower than the one
 * passed in (has a larger Y value).
 */
GPoint getLoweredPoint(GPoint point) {
    GPoint next(point.x, point.y + LEVEL_HEIGHT);
    return next;
}

void runCantorDemo() {
    GWindow window(SCREEN_WIDTH, SCREEN_HEIGHT);
    window.setTitle("Cantor Set of Order " + to_string(CANTOR_ORDER));
    GPoint left(INSET, INSET);
    GPoint right(SCREEN_WIDTH - INSET, INSET);
    drawCantor(window, CANTOR_ORDER, left, right);
}
