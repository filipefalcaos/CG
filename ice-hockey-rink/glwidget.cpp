#include <iostream>
#include <QMouseEvent>
#include "glwidget.h"
#include "includes.h"
#include "bresenham_circle.h"
#include "bresenham_line.h"
#include "circle_equation.h"
#include "line_equation.h"
#include "utils.h"

using namespace std;

// Gui variables
GLfloat color[3] = {0, 0, 0};
GLint point_size = 2;
GLint render_type = 0;
bool clear = false;

// New point calculation variables;
GLint x_max = 510, x_min = 140;
GLint y_max = 630, y_min = 20;
pair<int, int> curr_point = {-1, -1};

void drawRinkBresenham() {

    // Render the ice hockey rink
    plotLineBresenham(160, 75, 160, 575);
    plotLineBresenham(490, 75, 490, 575);
    plotLineBresenham(165, 60, 485, 60);
    plotLineBresenham(162, 585, 488, 585);

    plotLineBresenham(160, 325, 490, 325);
    plotLineBresenham(160, 250, 490, 250);
    plotLineBresenham(160, 400, 490, 400);

    plotCircleBresenham(325, 325, 45, "default");
    plotCircleBresenham(325, 325, 3, "default");

    plotCircleBresenham(245, 120, 45, "default");
    plotCircleBresenham(245, 120, 2, "default");
    plotCircleBresenham(405, 120, 45, "default");
    plotCircleBresenham(405, 120, 2, "default");

    plotCircleBresenham(245, 525, 45, "default");
    plotCircleBresenham(245, 525, 2, "default");
    plotCircleBresenham(405, 525, 45, "default");
    plotCircleBresenham(405, 525, 2, "default");

    plotCircleBresenham(245, 260, 2, "default");
    plotCircleBresenham(405, 260, 2, "default");
    plotCircleBresenham(245, 410, 2, "default");
    plotCircleBresenham(405, 410, 2, "default");

    plotCircleBresenham(325, 60, 30, "upper");
    plotCircleBresenham(325, 585, 30, "lower");

    plotCircleBresenham(215, 575, 55, "upper-left");
    plotLineBresenham(215, 630, 435, 630);
    plotCircleBresenham(435, 575, 55, "upper-right");

    plotCircleBresenham(220, 80, 60, "lower-left");
    plotLineBresenham(215, 20, 435, 20);
    plotCircleBresenham(430, 80, 60, "lower-right");

}

void drawRinkEquations() {

    // Render the ice hockey rink
    plotLineEquation(160, 75, 160, 575);
    plotLineEquation(490, 75, 490, 575);
    plotLineEquation(165, 60, 485, 60);
    plotLineEquation(162, 585, 488, 585);

    plotLineEquation(160, 325, 490, 325);
    plotLineEquation(160, 250, 490, 250);
    plotLineEquation(160, 400, 490, 400);

    plotCircleEquation(325, 325, 45, "default");
    plotCircleEquation(325, 325, 3, "default");

    plotCircleEquation(245, 120, 45, "default");
    plotCircleEquation(245, 120, 2, "default");
    plotCircleEquation(405, 120, 45, "default");
    plotCircleEquation(405, 120, 2, "default");

    plotCircleEquation(245, 525, 45, "default");
    plotCircleEquation(245, 525, 2, "default");
    plotCircleEquation(405, 525, 45, "default");
    plotCircleEquation(405, 525, 2, "default");

    plotCircleEquation(245, 260, 2, "default");
    plotCircleEquation(405, 260, 2, "default");
    plotCircleEquation(245, 410, 2, "default");
    plotCircleEquation(405, 410, 2, "default");

    plotCircleEquation(325, 60, 30, "upper");
    plotCircleEquation(325, 585, 30, "lower");

    plotCircleEquation(215, 575, 55, "upper-left");
    plotLineEquation(215, 630, 435, 630);
    plotCircleEquation(435, 575, 55, "upper-right");

    plotCircleEquation(220, 80, 60, "lower-left");
    plotLineBresenham(215, 20, 435, 20);
    plotCircleEquation(430, 80, 60, "lower-right");

}

GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent) {
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(50);
}

void GLWidget::initializeGL() {

    // Initialize OpenGL
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 650, 0, 650);
    glViewport(0, 0, 650, 650);

}

void GLWidget::paintGL() {

    // Viewport parameters
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(color[0], color[1], color[2]);
    glPointSize(point_size);

    // Set the curr pixel in red
    if (curr_point.first != -1 && curr_point.second != -1) {
        setPixel(curr_point.first, curr_point.second, 4, 1.0, 0.0, 0.0);
    }

    // Clear the screen drawings by clearing the points
    // Then, set it to draw again
    if (clear) {
        points_1.clear();
        points_2.clear();
        clear = false;
    }

    // Bresenham chosen
    if (render_type == 0){

        // Draw lines using Bresenham
        for (int i = 0; i < points_2.size(); i++) {
            plotLineBresenham(points_1[i].first, points_1[i].second, points_2[i].first, points_2[i].second);
        }

        // Draw rink using Bresenham
        drawRinkBresenham();

    // Equations chosen
    } else if (render_type == 1){

        // Draw lines using equations
        for (int i = 0; i < points_2.size(); i++){
            plotLineEquation(points_1[i].first, points_1[i].second, points_2[i].first, points_2[i].second);
        }

        // Draw rink using equations
        drawRinkEquations();
    }

    // Flush commands
    glFlush();

}

void GLWidget::resizeGL(int w, int h){}

void GLWidget::mousePressEvent(QMouseEvent *event) {

    // Get the click coordinates
    int x = event->x();
    int y = 650 - event->y();

    // Check if the point is not inside the rink
    if ((x >= x_max || x <= x_min) && (y <= y_max || y >= y_min)) {

        // Stores the curr point
        curr_point.first = x;
        curr_point.second = y;

        // First click
        if (first_click) {
            points_1.push_back(curr_point);
            first_click = false;
        }

        // Has already clicked before
        // Set for a new first click
        else {
            points_2.push_back(curr_point);
            first_click = true;
        }
    }



}
