#include <iostream>
#include "includes.h"
#include "utils.h"
#include "glwidget.h"

using namespace std;


void plotCircle(GLint x0, GLint y0, GLint x, GLint y) {

    setPixel(x0 + x, y0 + y, point_size, color[0], color[1], color[2]);
    setPixel(x0 - x, y0 + y, point_size, color[0], color[1], color[2]);
    setPixel(x0 + x, y0 - y, point_size, color[0], color[1], color[2]);
    setPixel(x0 - x, y0 - y, point_size, color[0], color[1], color[2]);

    setPixel(x0 + y, y0 + x, point_size, color[0], color[1], color[2]);
    setPixel(x0 - y, y0 + x, point_size, color[0], color[1], color[2]);
    setPixel(x0 + y, y0 - x, point_size, color[0], color[1], color[2]);
    setPixel(x0 - y, y0 - x, point_size, color[0], color[1], color[2]);

}

void plotSemiCircle(GLint x0, GLint y0, GLint x, GLint y, const string &type) {

    // If type is "upper", upper semi circle
    // If type is "lower", lower semi circle
    // If type is "upper-left", upper-left quarter circle
    // If type is "upper-right", upper-right quarter circle
    // If type is "lower-left", lower-left quarter circle
    // If type is "lower-right", lower-right quarter circle
    if (type == "upper") {
        setPixel(x0 + x, y0 + y, point_size, color[0], color[1], color[2]);
        setPixel(x0 - x, y0 + y, point_size, color[0], color[1], color[2]);
        setPixel(x0 + y, y0 + x, point_size, color[0], color[1], color[2]);
        setPixel(x0 - y, y0 + x, point_size, color[0], color[1], color[2]);
    } else if (type == "lower") {
        setPixel(x0 + x, y0 - y, point_size, color[0], color[1], color[2]);
        setPixel(x0 - x, y0 - y, point_size, color[0], color[1], color[2]);
        setPixel(x0 + y, y0 - x, point_size, color[0], color[1], color[2]);
        setPixel(x0 - y, y0 - x, point_size, color[0], color[1], color[2]);
    }

    if (type == "upper-left") {
        setPixel(x0 - x, y0 + y, point_size, color[0], color[1], color[2]);
        setPixel(x0 - y, y0 + x, point_size, color[0], color[1], color[2]);
    } else if (type == "upper-right") {
        setPixel(x0 + x, y0 + y, point_size, color[0], color[1], color[2]);
        setPixel(x0 + y, y0 + x, point_size, color[0], color[1], color[2]);
    } else if (type == "lower-left") {
        setPixel(x0 - x, y0 - y, point_size, color[0], color[1], color[2]);
        setPixel(x0 - y, y0 - x, point_size, color[0], color[1], color[2]);
    } else if (type == "lower-right") {
        setPixel(x0 + x, y0 - y, point_size, color[0], color[1], color[2]);
        setPixel(x0 + y, y0 - x, point_size, color[0], color[1], color[2]);
    }

}

void plotCircleBresenham(GLint x0, GLint y0, GLint radius, const string &type) {

    GLint x = 0, y = radius;
    GLint d_start = 3 - 2 * radius;

    // Initial plot
    if (type != "default") {
        plotSemiCircle(x0, y0, x, y, type);
    } else {
        plotCircle(x0, y0, x, y);
    }

    while (y >= x) {

        // Go to the next pixel
        x++;

        // Update the d_start
        if (d_start > 0) {
            y--;
            d_start = d_start + 4 * (x - y) + 10;
        } else {
            d_start = d_start + 4 * x + 6;
        }

        // Plot the new pixels
        if (type != "default") {
            plotSemiCircle(x0, y0, x, y, type);
        } else {
            plotCircle(x0, y0, x, y);
        }
    }

}
