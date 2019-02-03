#include <iostream>
#include <string>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include "draw/ice_hockey_rink.h"
#include "utils/utils.h"
#include "bresenham/bresenham_line.h"
#include "equations/line_equation.h"

using namespace std;


// New point calculation variables;
// -1 means that a new point is not set
GLint first_x = -1, first_y = -1;
GLint curr_x = -1, curr_y = -1;
GLint last_x = -1, last_y = -1;
GLint x_max = 510, x_min = 140;
GLint y_max = 630, y_min = 20;

// Render type
string render_type = "bresenham";

// If to redisplay
bool redisplay = false;

void init() {

    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Init window
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(650, 650);
    glutCreateWindow("Ice Hockey Rink");

    // Set for 2D
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 650, 0, 650);

}

void render() {

    // True if new drawings are needed
    if (redisplay) {

        // Draw the clicked pixel
        setPixel(curr_x, curr_y, 2, 0.0, 0.0, 0.0);

        if (curr_x != -1 && curr_y != -1 && last_x != -1 && last_y != -1) {

            // Draw the bench line using Bresenham
            if (render_type == "bresenham") {
                plotLineBresenham(curr_x, curr_y, last_x, last_y);
            }

            // Draw the bench line using equations
            else if (render_type == "equations") {
                plotLineEquation(curr_x, curr_y, last_x, last_y);
            }

            // Reset the points
            // If the distance from the first to the last point is < 20, fully reset the points
            // Else, set for the next point
            if (euclidean_distance(first_x, first_y, last_x, last_y) <= 20) {
                first_x = curr_x = last_x = -1;
                first_y = curr_y = last_y = -1;
            } else {
                curr_x = last_x; curr_y = last_y;
                last_x = -1; last_y = -1;
            }
        }

    } else {
        glClear(GL_COLOR_BUFFER_BIT); // Clear the display
    }

    // Draw the ice hockey rink using Bresenham
    if (render_type == "bresenham") {
        drawRinkBresenham();
    }

    // Draw the ice hockey rink using equations
    else if (render_type == "equations") {
        drawHinkEquations();
    }

    // Flush commands
    glFlush();

}

void mouseHandler(int button, int state, int x, int y) {

    // Get the mouse click event
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        // Check if the point is not inside the rink
        if ((x >= x_max || x <= x_min) && (y <= y_max || y >= y_min)) {
            if (curr_x == -1 && curr_y == -1) {
                first_x = curr_x = x;
                first_y = curr_y = 650 - y;
                redisplay = true;
            } else {
                last_x = x;
                last_y = 650 - y;
                redisplay = true;
            }
        }
    }

    // Redisplay window
    glutPostRedisplay();

}

int main(int argc, char *argv[]) {

    // Init GLUT
    glutInit(&argc, argv);

    // Init the ViewPort
    init();

    // Callback to the function that display elements
    glutDisplayFunc(render);
    glutMouseFunc(mouseHandler);
    glutMainLoop();

    return 0;

}