/*
 * Flor.cpp
 * 
 * Implementar uma Flor de Abril que rotaciona, como
 * um catavento.
 *
 * Author: Filipe Falcao Batista dos Santos
 */

#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>


// Set rotation variables
int direction = 1;
int frames = 0;
int petals = 4;


void init(void) {

    // Set background black color
    glClearColor (0.0, 0.0, 0.0, 0.0);

    // Set for 2D
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glOrtho(0, 7, -1, 4, -1, 1);
    glMatrixMode(GL_MODELVIEW);

}

void keysCallbackDir(int key, int x, int y) {

    // Left click
    if (key == GLUT_KEY_LEFT) {
        direction = 1;
    }

    // Right click
	if (key == GLUT_KEY_RIGHT) {
        direction = -1;
    }

}

void displayFlower() {
	
	// Clear the display
	glClear(GL_COLOR_BUFFER_BIT);

    // Draw the flower "line"
	glColor3f (1.0, 1.0, .0);
    glBegin(GL_POLYGON);
   	    glVertex2f(-0.05f, 0);
		glVertex2f(0.05f, 0);
		glVertex2f(0.05f, 3);
		glVertex2f(-0.05f, 3);
    glEnd();

    // Translate and then rotate
    glTranslatef(0, 3, 0);
	glRotated((direction * (frames * (180.0 / 70))), 0, 0, 1);

    // Draw 4 red triangles
    glColor3f(1.0, 0.0, 0.0);

    for (int i = 0; i < petals; i++) {
		glRotated(72, 0, 0, 1);
		glBegin(GL_TRIANGLES);
			glVertex2f(0, 0);
			glVertex2f(0.5f, 0.4f);
			glVertex2f(1.0f, 0);
			glVertex2f(0.5f, -0.4f);
		glEnd();
	}

    // Render
	glFlush();

}

void display() {

    // Clear the display
    glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

    // Create a matrix to push the elements
    // This is needed for translation/rotation
	glPushMatrix();
	glTranslated(3.5, -1, 1);

    // Set the callback to move the petals when
    // clicking the keys
	glutSpecialFunc(keysCallbackDir);

    // Draw the flower itself
	displayFlower();
	glPopMatrix();
	glutSwapBuffers();

}

void step(int v) {
    
    // Increment the variables for moving
    frames += 1;
	petals += 1;

    // Redisplay and callback again
    glutPostRedisplay();
    glutTimerFunc(30, step, 0);
}

void exitPressed(unsigned char key, int x, int y) {

	if (key == 'q') {
		exit(0);
    }

}

int main(int argc, char *argv[]) {
	
	// Init GLUT
	glutInit(&argc, argv);									

    // Create a bew window
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(1120, 800);
    glutInitWindowPosition(100,100);						
	glutCreateWindow("Flor de Abril");	

	// Init the ViewPort
	init(); 
	
    // Callback to the function that display elements
	glutDisplayFunc(display);

    // Callback to the keyboard arrows
    // The callback that moves the flower petals
    glutTimerFunc(100, step, 0);
					
	// Callback to the function that quits when 'q' is pressed
	glutKeyboardFunc(exitPressed);		
			
	// Start main loop
	glutMainLoop();										

}
