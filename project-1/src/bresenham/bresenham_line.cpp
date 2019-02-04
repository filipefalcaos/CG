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
#include "../includes.h"
#include "../utils/utils.h"

using namespace std;


// Plot a line using Bresenham's algorithm
// This approach works for all the octants
void plotLineBresenham(GLint x0, GLint y0, GLint x1, GLint y1) {

    // Plot the first point
    setPixel(x0, y0, 2, 0.0, 0.0, 0.0);

    // Calculate dx and dy
    GLint dx = abs(x1 - x0);
    GLint dy = abs(y1 - y0);

    // Error variables
    GLint xs, ys, d;

    if (x1 > x0) { xs = 1; }
    else { xs = -1; }

    if (y1 > y0) { ys = 1; }
    else { ys = -1; }

    // Driving axis is the X-axis
    if (dx >= dy) {
        d = 2 * (dy - dx);

        while (x0 != x1) {
            x0 += xs;

            if (d >= 0) {
                y0 += ys;
                d -= 2 * dx;
            }

            d += 2 * dy;
            setPixel(x0, y0, 2, 0.0, 0.0, 0.0);
        }
    }

    // Driving axis is the Y-axis
    if (dy >= dx) {
        d = 2 * (dx - dy);

        while (y0 != y1) {
            y0 += ys;

            if (d >= 0) {
                x0 += xs;
                d -= 2 * dy;
            }

            d += 2 * dx;
            setPixel(x0, y0, 2, 0.0, 0.0, 0.0);
        }
    }

}
