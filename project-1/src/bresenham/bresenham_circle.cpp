/*
 * Copyright <2/2/19> <Filipe Falcao>
 *
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the 
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, sublicense, and/or sell copies of the Software, and to 
 * permit persons to whom the Software is furnished to do so, subject to 
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "../utils/utils.h"

using namespace std;


void plotCircle(GLint x0, GLint y0, GLint x, GLint y) {

    setPixel(x0 + x, y0 + y, 2, 0.0, 0.0, 0.0);
    setPixel(x0 - x, y0 + y, 2, 0.0, 0.0, 0.0);
    setPixel(x0 + x, y0 - y, 2, 0.0, 0.0, 0.0);
    setPixel(x0 - x, y0 - y, 2, 0.0, 0.0, 0.0);

    setPixel(x0 + y, y0 + x, 2, 0.0, 0.0, 0.0);
    setPixel(x0 - y, y0 + x, 2, 0.0, 0.0, 0.0);
    setPixel(x0 + y, y0 - x, 2, 0.0, 0.0, 0.0);
    setPixel(x0 - y, y0 - x, 2, 0.0, 0.0, 0.0);

}

void plotSemiCircle(GLint x0, GLint y0, GLint x, GLint y, const string &type) {

    // If type is "upper", upper semi circle
    // If type is "lower", lower semi circle
    // If type is "upper-left", upper-left quarter circle
    // If type is "upper-right", upper-right quarter circle
    // If type is "lower-left", lower-left quarter circle
    // If type is "lower-right", lower-right quarter circle
    if (type == "upper") {
        setPixel(x0 + x, y0 + y, 2, 0.0, 0.0, 0.0);
        setPixel(x0 - x, y0 + y, 2, 0.0, 0.0, 0.0);
        setPixel(x0 + y, y0 + x, 2, 0.0, 0.0, 0.0);
        setPixel(x0 - y, y0 + x, 2, 0.0, 0.0, 0.0);
    } else if (type == "lower") {
        setPixel(x0 + x, y0 - y, 2, 0.0, 0.0, 0.0);
        setPixel(x0 - x, y0 - y, 2, 0.0, 0.0, 0.0);
        setPixel(x0 + y, y0 - x, 2, 0.0, 0.0, 0.0);
        setPixel(x0 - y, y0 - x, 2, 0.0, 0.0, 0.0);
    }

    if (type == "upper-left") {
        setPixel(x0 - x, y0 + y, 2, 0.0, 0.0, 0.0);
        setPixel(x0 - y, y0 + x, 2, 0.0, 0.0, 0.0);
    } else if (type == "upper-right") {
        setPixel(x0 + x, y0 + y, 2, 0.0, 0.0, 0.0);
        setPixel(x0 + y, y0 + x, 2, 0.0, 0.0, 0.0);
    } else if (type == "lower-left") {
        setPixel(x0 - x, y0 - y, 2, 0.0, 0.0, 0.0);
        setPixel(x0 - y, y0 - x, 2, 0.0, 0.0, 0.0);
    } else if (type == "lower-right") {
        setPixel(x0 + x, y0 - y, 2, 0.0, 0.0, 0.0);
        setPixel(x0 + y, y0 - x, 2, 0.0, 0.0, 0.0);
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
