#include <iostream>
#include <math.h>
#include "includes.h"

using namespace std;

// Plots a point P(x,y)
void setPixel(GLint x, GLint y, GLint point_size, GLfloat c1, GLfloat c2, GLfloat c3) {

    glColor3f(c1, c2, c3);
    glPointSize(point_size);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

}
