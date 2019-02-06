#include <iostream>
#include "includes.h"
#include "utils.h"
#include "glwidget.h"

using namespace std;


// Plot a line using Bresenham's algorithm
// This approach works for all the octants
void plotLineBresenham(GLint x0, GLint y0, GLint x1, GLint y1) {

    // List of points in the line
    vector<pair<int,int>> line_points;
    pair<int, int> curr_point;

    // Plot the first point
    setPixel(x0, y0, point_size, color[0], color[1], color[2]);
    curr_point.first = x0; curr_point.second = y0;
    line_points.push_back(curr_point);

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
            curr_point.first = x0; curr_point.second = y0;
            line_points.push_back(curr_point);
            //setPixel(x0, y0, point_size, color[0], color[1], color[2]);
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
            curr_point.first = x0; curr_point.second = y0;
            line_points.push_back(curr_point);
            setPixel(x0, y0, point_size, color[0], color[1], color[2]);
        }
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
