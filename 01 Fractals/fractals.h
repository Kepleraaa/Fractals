#pragma once

#include "gwindow.h"
#include "gobjects.h"

static const int SCREEN_WIDTH = 1000;
static const int SCREEN_HEIGHT = SCREEN_WIDTH;

/* Cantor Set Information */
GPoint getLoweredPoint(GPoint point);
void drawThickLine(GWindow &w, GPoint left, GPoint right);
void runCantorDemo();

/* Snowflake Information */
GPoint pointBetween(GPoint p1, GPoint p2, double fraction);
GPoint thirdEquilateralPoint(GPoint bottomLeft, GPoint otherPoint);
void runSnowflakeDemo();

/* Sierpinski Carpet Information */
void clear(GWindow& window);
void repaint(GWindow& window);
void runSierpinskiDemo();
