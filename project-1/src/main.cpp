#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "draw/ice_hockey_rink.h"


void init() {

    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Init window
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(650, 650);
    glutCreateWindow("Ice Hockey Rink");

    // Set for 2D
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2);
    gluOrtho2D(0, 650, 0, 650);

}

void render() {

    // Clear the display
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the ice hockey rink using Bresenham
    drawHinkBresenham();

    // Flush commands
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