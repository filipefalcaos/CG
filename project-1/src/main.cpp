#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "bresenham/bresenham_line.h"
#include "equations/line_equation.h"
#include "bresenham/bresenham_circle.h"
#include "equations/circle_equation.h"


void init() {

    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Init window
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Green Window");

    // Set for 2D
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    gluOrtho2D(0, 640, 0, 480);

}

void render() {

    // Clear the display
    glClear(GL_COLOR_BUFFER_BIT);
    plotCircleEquation(320, 240, 100);
    glFlush();

}

int main(int argc, char *argv[]) {

    // Init GLUT
    glutInit(&argc, argv);

    // Init the ViewPort
    init();

    // Callback to the function that display elements
    glutDisplayFunc(render);
    glutMainLoop();

    return 0;

}