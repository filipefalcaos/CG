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
#include <math.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "../utils/utils.h"

using namespace std;


void plotCircleEquation(GLint x0, GLint y0, GLint radius) {

    GLint x, y;
    GLdouble theta;
    GLint n_pixels = 500;

    for (int i = 0; i < n_pixels; i++) {

        // Get the current angle
        theta = 2 * M_PI * i / n_pixels;

        // Calculate the x and y components
        x = (int) (radius * cos(theta));
        y = (int) (radius * sin(theta));

        // Plot the pixel
        setPixel(x + x0, y + y0);
    }

}