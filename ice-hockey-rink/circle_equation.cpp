#include <iostream>
#include <math.h>
#include "includes.h"
#include "utils.h"
#include "glwidget.h"

using namespace std;


// Plot a circle using the circle equation
// This approach works for all the quadrants
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
            setPixel(i, static_cast<int> (y0 + sqrt(pow(radius, 2) - pow((i - x0), 2))), point_size, color[0], color[1], color[2]);
            setPixel(i, static_cast<int> (y0 - sqrt(pow(radius, 2) - pow((i - x0), 2))), point_size, color[0], color[1], color[2]);
        } else if (type == "upper") {
            setPixel(i, static_cast<int> (y0 + sqrt(pow(radius, 2) - pow((i - x0), 2))), point_size, color[0], color[1], color[2]);
        } else if (type == "lower") {
            setPixel(i, static_cast<int> (y0 - sqrt(pow(radius, 2) - pow((i - x0), 2))), point_size, color[0], color[1], color[2]);
        } else if (type == "lower-left" || type == "lower-right") {
            setPixel(i, static_cast<int> (y0 - sqrt(pow(radius, 2) - pow((i - x0), 2))), point_size, color[0], color[1], color[2]);
        } else if (type == "upper-left" || type == "upper-right") {
            setPixel(i, static_cast<int> (y0 + sqrt(pow(radius, 2) - pow((i - x0), 2))), point_size, color[0], color[1], color[2]);
        }
    }

}
