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


void plotCircleEquation(GLint x0, GLint y0, GLint radius, const string &type) {

    GLint x_start = x0 - radius;
    GLint x_end = x0 + radius;

    if (type == "default") {
        x_start = x0 - radius;
        x_end = x0 + radius;
    } else if (type == "lower-left" || type == "upper-left") {
        x_start = x0 - radius;
        x_end = x0;
    } else if (type == "lower-right" || type == "upper-right") {
        x_start = x0;
        x_end = x0 + radius;
    }

    for (int i = x_start; i < x_end; i++) {
        if (type == "default") {
            setPixel(i, (int) y0 + sqrt(pow(radius, 2) - pow((i - x0), 2)), 2, 0.0, 0.0, 0.0);
            setPixel(i, (int) y0 - sqrt(pow(radius, 2) - pow((i - x0), 2)), 2, 0.0, 0.0, 0.0);
        } else if (type == "upper") {
            setPixel(i, (int) y0 + sqrt(pow(radius, 2) - pow((i - x0), 2)), 2, 0.0, 0.0, 0.0);
        } else if (type == "lower") {
            setPixel(i, (int) y0 - sqrt(pow(radius, 2) - pow((i - x0), 2)), 2, 0.0, 0.0, 0.0);
        } else if (type == "lower-left" || type == "lower-right") {
            setPixel(i, (int) y0 - sqrt(pow(radius, 2) - pow((i - x0), 2)), 2, 0.0, 0.0, 0.0);
        } else if (type == "upper-left" || type == "upper-right") {
            setPixel(i, (int) y0 + sqrt(pow(radius, 2) - pow((i - x0), 2)), 2, 0.0, 0.0, 0.0);
        }
    }

}