/*
 * File: Trees.cpp
 * ---------------
 * A program that generates trees using recursion!
 */

#include <iostream>
#include <string>
#include "gwindow.h"
#include "gobjects.h"
#include "gthread.h"
#include "fractals.h"
using namespace std;

/* Constants controlling the window size. */
const double kWindowWidth  = 1000;
const double kWindowHeight = 800;

/* Margin from window sides to content area. */
const double kMargin = 40;

/* Colors! */
const std::string kBackgroundColor = "white";
const std::string kRectangleColor  = "#400080";

/* Maximum order to draw. */
const int Sierpinski_Order = 5;

void drawSquare(GWindow& window, double x, double y, double size);

void drawSierpinskiCarpet(GWindow& window, double x, double y, double size, int order) {
    /* TODO: Implement the Sierpinski Carpet drawing function. */
    if (order==0)
    {
        drawSquare(window,x,y,size);
    }
    else
    {
        drawSierpinskiCarpet(window,x,y,size/3,order-1);
        drawSierpinskiCarpet(window,x,y+1.0/3*size,size/3,order-1);
        drawSierpinskiCarpet(window,x,y+2.0/3*size,size/3,order-1);
        drawSierpinskiCarpet(window,x+1.0/3*size,y,size/3,order-1);
        drawSierpinskiCarpet(window,x+1.0/3*size,y+2.0/3*size,size/3,order-1);
        drawSierpinskiCarpet(window,x+2.0/3*size,y,size/3,order-1);
        drawSierpinskiCarpet(window,x+2.0/3*size,y+1.0/3*size,size/3,order-1);
        drawSierpinskiCarpet(window,x+2.0/3*size,y+2.0/3*size,size/3,order-1);
    }
}

/* Main program */
void runSierpinskiDemo() {
    GWindow window(kWindowWidth, kWindowHeight);
    window.setExitOnClose(true);
    window.setTitle("Sierpinski Carpet of Order " + to_string(Sierpinski_Order));

    /* Determine the width and height of the square to draw. */
    double width  = window.getCanvasWidth()  - 2 * kMargin;
    double height = window.getCanvasHeight() - 2 * kMargin;
    double size = min(width, height);

    /* Determine position. */
    double x = (window.getCanvasWidth()  - size) / 2.0;
    double y = (window.getCanvasHeight() - size) / 2.0;

    drawSierpinskiCarpet(window, x, y, size, Sierpinski_Order);
}

void drawSquare(GWindow& window,
                double x, double y,
                double size) {
    window.setColor(kRectangleColor);
    window.fillRect(x, y, size, size);
}
