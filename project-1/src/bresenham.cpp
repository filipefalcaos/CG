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


// Returns -1, 0, 1 depending on whether x
// is < 0, == 0, > 0 respectively
int sign(GLint x) {

    if (x < 0) { return -1;}
    else if (x == 0) { return 0;}
    else { return 1;}

}

// Plots a point P(x,y)
void setPixel(GLint x, GLint y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Plot a line using Bresenham's algorithm
// This approach works for all the octants (-1 to 1)
void plotLine(GLint x0, GLint y0, GLint x1, GLint y1) {

    GLint dx, dy, x, y;
    GLint d_start;
    GLint s1, s2, swap = 0, temp;

    // Set the dx and dy variables
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);

    // Get the current octant
    s1 = sign(x1 - x0);
    s2 = sign(y1 - y0);

    // Check if dx or dy has a greater range
    // if dy has a greater range than dx swap dx and dy
    if (dy > dx) { temp = dx; dx = dy; dy = temp; swap = 1; }

    // Set the d_start parameter and the initial point
    d_start = 2 * (dy - dx);
    x = x0;
    y = y0;

    for (int i = 0; i < dx; i++) {

        // Plot the current pixel
        setPixel(x, y);

        // Decides whether to go to E or NE
        while (d_start >= 0) {
            if (swap) {
                x = x + s1;
            } else {
                y = y + s2;
                d_start = d_start - (2 * dx);
            }
        }

        if (swap) {
            y = y + s2;
        } else {
            x = x + s1;
        }

        // Update the d_start
        d_start = d_start + 2 * dy;
    }

    glFlush();

}
