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
#include <cmath>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "../utils/utils.h"

using namespace std;


// Plot a line the line equation
// This approach works for all the quadrants
void plotLineEquation(GLint x0, GLint y0, GLint x1, GLint y1) {

    GLint x, y;
    GLint s1, s2, swap = 0, temp;
    GLfloat coeff;

    // Change the quadrant
    if (x1 < x0) { temp = x0; x0 = x1; x1 = temp; temp = y0; y0 = y1; y1 = temp; }
    if (y1 < y0) { y0 = -y0; y1 = -y1; swap = 1; }

    if (abs(y1 - y0) < abs(x1 - x0)) {

        // Calculate the line coefficient
        coeff = (float) ((y1 - y0) / (x1 - x0));

        // Calculate x and y
        for (x = (int) x0 + 1; x < x1; x++) {
            y = (int) (y0 + coeff * (x - x0));

            if (swap) {
                setPixel(x, -y, 2, 0.0, 0.0, 0.0);
            } else {
                setPixel(x, y, 2, 0.0, 0.0, 0.0);
            }
        }
    } else {

        // Calculate the line coefficient
        coeff = (float) ((x1 - x0) / (y1 - y0));

        // Calculate x and y
        for (y = (int) y0 + 1; y < y1; y++) {
            x = (int) (x0 + coeff * (y - y0));

            if (swap) {
                setPixel(x, -y, 2, 0.0, 0.0, 0.0);
            } else {
                setPixel(x, y, 2, 0.0, 0.0, 0.0);
            }
        }
    }

}
