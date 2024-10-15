//
//  Assignment2.cpp
//  Assignment 2
//
//  Created by Harrison Grenier
//

#define _USE_MATH_DEFINES
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <memory>
#include <iostream>
#include <cmath>
//
#include "glPlatform.h"
#include "Cart.h"
#include "Road.h"



using namespace std;

// glut callback functions
void myDisplay(void);
void myResize(int w, int h);
void myInit(void);
void myTimerFunc(int value);
void handleKeyboard(unsigned char c, int x, int y);

// inital window perams
const int   INIT_WIN_X = 100,
INIT_WIN_Y = 40;

// const to store the precision the drawing screen here 0,0 to 40, 40
const float X_MAX = 40.0f, X_MIN = 0.0f,
Y_MAX = 40.0f, Y_MIN = 0.0f;

// values to store the size of the window 600x600
int winWidth = 600,
winHeight = 600;

float cartSpeed = 0.05f;   // Initial speed of the cart
bool cartMoving = false;   // Flag to check if the cart is moving
int cartDirection = 1;     // 1 for moving right, -1 for moving left


// Create a road object of type 1 (sine wave)
Road road(1);

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	road.draw();    // Draw the road
	road.drawCart(); // Draw the cart using the road's method

	glutSwapBuffers();
}



void myResize(int w, int h) {
	glViewport(0, 0, w, h);
	winWidth = w;
	winHeight = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspectRatio = (float)w / (float)h;

	// Adjust the projection to cover the area where the road and cart are drawn
	if (aspectRatio > 1.0f) { // Wider than tall
		gluOrtho2D(0, 40 * aspectRatio, 0, 40);
	}
	else { // Taller than wide
		gluOrtho2D(0, 40, 0, 40 / aspectRatio);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); // Reset the model view matrix after changing projection

	// Request a refresh of the display
	glutPostRedisplay();
}

void myTimerFunc(int value) {
	if (cartMoving) {
		road.moveCart(cartSpeed);  // Move the cart via the road object
	}

	glutTimerFunc(16, myTimerFunc, 0);
	glutPostRedisplay();
}
// check for user keyboard inputs
void handleKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: exit(0); break;    // Escape key
	case ' ': cartMoving = !cartMoving; break; // Toggle cart movement
	case ',': if (cartSpeed > 0.01f) cartSpeed -= 0.01f; break;  // Decrease speed
	case '.': if(cartSpeed < 0.35f)cartSpeed += 0.01f; break;  // Increase speed
	}
	glutPostRedisplay();
}


void myInit(void)
{

	myDisplay();
}

int main(int argc, char** argv) {
	
	road.createCart(0.0f, road.getY(0.0f), 0.0f, 1.0f);
	// Initialize OpenGL and GLUT as before
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition(INIT_WIN_X, INIT_WIN_Y);
	glutCreateWindow("Harry Grenier Assignment 2 program 2");

	// Set up display and other callback functions
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myResize);
	glutTimerFunc(100, myTimerFunc, 0);  // Start the animation loop with a timer
	glutKeyboardFunc(handleKeyboard);

	myInit(); // Initialize any OpenGL settings
	glutMainLoop(); // Enter the main event-processing loop

	return 0;
}
