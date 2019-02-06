#ifndef BRESENHAM_CIRCLE_H
#define BRESENHAM_CIRCLE_H

#include "includes.h"
#include <string>

using namespace std;


// Functions defined in bresenham_circle.cpp
void plotCircle(GLint x0, GLint y0, GLint x, GLint y);
void plotSemiCircle(GLint x0, GLint y0, GLint x, GLint y, const string &type);
void plotCircleBresenham(GLint x0, GLint y0, GLint radius, const string &type);

#endif // BRESENHAM_CIRCLE_H
