#include <iostream>
#include <cmath>
#include "includes.h"
#include "utils.h"
#include "glwidget.h"

using namespace std;


// Plot a line using the line equation
// This approach works for all the quadrants
void plotLineEquation(GLint x0, GLint y0, GLint x1, GLint y1) {

    GLint x, y;
    vector<pair<int,int>> line_points;

    for (double t = 0.; t < 1.; t += .001) {
        pair<int, int> curr_point;
        curr_point.first = x = (int) (x0 + (x1 - x0) * t);
        curr_point.second = y = (int) (y0 + (y1 - y0) * t);
        line_points.push_back(curr_point);
        //setPixel(x, y, point_size, color[0], color[1], color[2]);
    }

    for (int i = 0; i < line_points.size(); i++) {
        if ((line_points[0].first < x_min || line_points[0].first > x_max) &&
                (line_points[i].first > x_min && line_points[i].first < x_max)) {
            return;
        }
    }

    for (int i = 0; i < line_points.size(); i++) {
        setPixel(line_points[i].first, line_points[i].second, point_size, color[0], color[1], color[2]);
    }

}
