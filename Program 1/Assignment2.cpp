//
//  Assignment2.cpp
//  Assignment 2
//
//  Created by Harrison Grenier
//

#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <memory>
//
#include "glPlatform.h"
#include "portrait.h"
#include "PortraitWheel.h"

using namespace std;

// glut callback functions
void myDisplay(void);
void myResize(int w, int h);
void myInit(void);
void myTimerFunc(int value);
void handleKeyboard(unsigned char c, int x, int y);
void handleMouse(int button, int state, int x, int y);


// inital window perams
const int   INIT_WIN_X = 100,
INIT_WIN_Y = 40;

// const to store the precision the drawing screen here -10,-10 to 10, 10
const float X_MAX = 10.0f, X_MIN = -10.0f,
Y_MAX = 10.0f, Y_MIN = -10.0f;

// values to store the size of the window 600x600
int winWidth = 600,
winHeight = 600;

// vector to store all the graphic objects
std::vector<std::shared_ptr<GraphicObject2D>> drawableObjects;



// Global variables to store the current mode settings
WheelType currentWheelType = WheelType::HEADS_ON_WHEEL; // Default mode
WheelSize currentWheelSize = WheelSize::MEDIUM;         // Default size
int currentNumPortraits = 5;                           // Default number of portraits
bool isAnimationOn = false;  // Global variable to track the animation state


void myDisplay(void) {
	// Clear the buffer(s) we draw into
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set the model view to draw
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Iterate over all drawable objects and draw them
	for (const auto& obj : drawableObjects) {
		if (obj) {
			obj->draw();  // This will call the correct draw method based on the object's type
		}
	}

	// Switch the drawing on the back buffer to the front screen
	glutSwapBuffers();
}



void myResize(int w, int h) {
	glViewport(0, 0, w, h);
	winWidth = w;
	winHeight = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspectRatio = (float)w / (float)h;

	// Adjust the projection based on the aspect ratio
	if (aspectRatio > 1.0f) { // Wider than tall
		gluOrtho2D(X_MIN * aspectRatio, X_MAX * aspectRatio, Y_MIN, Y_MAX);
	}
	else { // Taller than wide
		gluOrtho2D(X_MIN, X_MAX, Y_MIN / aspectRatio, Y_MAX / aspectRatio);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); // Reset the model view matrix after changing projection

	// Request a refresh of the display
	glutPostRedisplay();
}

void myTimerFunc(int value) {
	if (isAnimationOn) {
		// Rotate each PortraitWheel object by 1 degree
		for (const auto& obj : drawableObjects) {
			// Check if the object is a PortraitWheel and rotate it
			std::shared_ptr<PortraitWheel> wheel = std::dynamic_pointer_cast<PortraitWheel>(obj);
			if (wheel) {
				float currentOrientation = wheel->getOrientation();
				wheel->setOrientation(currentOrientation + 1.0f);  // Rotate by 1 degree per frame
			}
		}
	}

	// Re-prime the timer to fire again in 16 milliseconds (roughly 60 frames per second)
	glutTimerFunc(16, myTimerFunc, 0);

	// Request a refresh of the display to see the updated animation
	glutPostRedisplay();
}


// check for user keyboard inputs
void handleKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's': // Switch to "head on stick" mode
		currentWheelType = WheelType::HEADS_ON_STICKS;
		break;
	case 'w': // Switch to "heads on wheel" mode
		currentWheelType = WheelType::HEADS_ON_WHEEL;
		break;
	case '3': case '4': case '5': case '6': case '7': case '8': case '9':
		currentNumPortraits = key - '0'; // Set number of portraits
		break;
	case '+': // Increase wheel size
		if (currentWheelSize == WheelSize::SMALL)
			currentWheelSize = WheelSize::MEDIUM;
		else if (currentWheelSize == WheelSize::MEDIUM)
			currentWheelSize = WheelSize::LARGE;
		break;
	case '-': // Decrease wheel size
		if (currentWheelSize == WheelSize::LARGE)
			currentWheelSize = WheelSize::MEDIUM;
		else if (currentWheelSize == WheelSize::MEDIUM)
			currentWheelSize = WheelSize::SMALL;
		break;
	case ' ': // Toggle animation mode on/off with space key
		isAnimationOn = !isAnimationOn;
		break;
	case 27: // Escape key to exit the program
		exit(0);
		break;
	}

	// Request a redisplay to update the screen
	glutPostRedisplay();
}


void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Convert the mouse click coordinates to the OpenGL coordinate system
		float mouseX = (x / (float)winWidth) * (X_MAX - X_MIN) + X_MIN;
		float mouseY = ((winHeight - y) / (float)winHeight) * (Y_MAX - Y_MIN) + Y_MIN;

		// Create a new PortraitWheel object at the mouse location using current global mode settings
		std::shared_ptr<GraphicObject2D> newWheel = std::make_shared<PortraitWheel>(
			currentWheelType, currentWheelSize, currentNumPortraits, mouseX, mouseY
		);

		// Add the new object to the list of drawable objects
		drawableObjects.push_back(newWheel);

		// Request a redisplay to update the screen
		glutPostRedisplay();
	}
}


void myInit(void)
{

	myDisplay();
}

int main(int argc, char** argv) {
	// Initialize glut and create a new window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition(INIT_WIN_X, INIT_WIN_Y);
	glutCreateWindow("Harry Grenier Assignment 2");

	// Set up the callbacks for display, resize, timer, keyboard, and mouse events
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myResize);
	glutTimerFunc(10, myTimerFunc, 0);
	glutKeyboardFunc(handleKeyboard);
	glutMouseFunc(handleMouse);


	myInit();
	glutMainLoop();

	return 0;
}