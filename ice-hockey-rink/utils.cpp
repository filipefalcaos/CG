#include <iostream>
#include <math.h>
#include "includes.h"

using namespace std;


// Plots a point P(x,y)
void setPixel(GLint x, GLint y, GLint point_size, GLdouble c1, GLdouble c2, GLdouble c3) {

    // Set the color, point size, and then plot
    glColor3d(c1, c2, c3);
    glPointSize(point_size);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

}
