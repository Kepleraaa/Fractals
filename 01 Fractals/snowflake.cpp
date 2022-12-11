/*
 * FILE: SNOWFLAKE FRACTALS
 * ---------------------
 * This program draws a Snowflake line of a constant depth on the screen.
 * A Snowflake line of depth N is 4 snowflake lines of depth N-1: two 1/3
 * of the length of the desired line (on the leftmost and rightmost sides),
 * and two forming a triangle in the middle 1/3 of the length of the
 * desired line.
 */

#include <math.h>
#include "gwindow.h"
#include "gobjects.h"
#include "fractals.h"

using namespace std;

// useful math constants
static const double COS_60 = 0.5;            //value of cos(60 degrees)
static const double SIN_60 = sqrt(3)*0.5;    //value of sin(60 degrees)

// display constants
static const int BASE_Y = SCREEN_HEIGHT - SCREEN_HEIGHT * .4;
static const int BASE_LEFT_X = 170;
static const int BASE_RIGHT_X = SCREEN_WIDTH - 170;
static const int SNOWFLAKE_ORDER = 6;

/* Function: Draw Snowflake Line
 * ---------------------
 * A recursive function that draws a Snowflake line between points
 * "start" and "end." The fractal will have "level" numbers of levels.
 */
void drawSnowflakeLine(GWindow &window, int level, GPoint start, GPoint end) {
    if (level == 0) {
        window.drawLine(start, end);
    } else {
        GPoint a = pointBetween(start, end, 1.0 / 3);
        GPoint b = pointBetween(start, end, 2.0 / 3);
        GPoint t = thirdEquilateralPoint(a, b);

        // TIP: reverse the order of these recursive calls to draw the line from R to L!
        drawSnowflakeLine(window, level - 1, start, a);
        drawSnowflakeLine(window, level - 1, a, t);
        drawSnowflakeLine(window, level - 1, t, b);
        drawSnowflakeLine(window, level - 1, b, end);
    }
}

/* PROVIDED HELPER FUNCTIONS */

/* Method: Third Equilateral Point
 * -----------------------
 * Given the bottom left point of an equilateral triangle, and one other point
 * (either the top or the bottom right), returns the third point in the triangle.
 */
GPoint thirdEquilateralPoint(GPoint bottomLeft, GPoint otherPoint) {
    double deltaX = (otherPoint.x - bottomLeft.x);
    double deltaY = (otherPoint.y - bottomLeft.y);
    double x = bottomLeft.x + (deltaX*COS_60 + deltaY*SIN_60);
    double y = bottomLeft.y + (deltaY*COS_60 - deltaX*SIN_60);
    GPoint tip(x, y);
    return tip;
}

void runSnowflakeDemo() {
    GWindow window(SCREEN_WIDTH, SCREEN_HEIGHT);
    window.setColor("black");
    window.setFillColor("black");
    window.setTitle("Snowflake of Order" + to_string(SNOWFLAKE_ORDER));
    GPoint bottomLeft(BASE_LEFT_X, BASE_Y);
    GPoint bottomRight(BASE_RIGHT_X, BASE_Y);
    drawSnowflakeLine(window, SNOWFLAKE_ORDER, bottomLeft, bottomRight);

    // TIP: we can draw snowflake lines at any angle!  Try this to experiment
//    GPoint top = thirdEquilateralPoint(bottomLeft, bottomRight);
//    drawSnowflakeLine(w, FRACTAL_DEPTH, bottomLeft, top);
}

