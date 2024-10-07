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

// inital window perams
const int   INIT_WIN_X = 100,
INIT_WIN_Y = 40;

// const to store the precision the drawing screen here -10,-10 to 10, 10
const float X_MAX = 10.0f, X_MIN = -10.0f,
Y_MAX = 10.0f, Y_MIN = -10.0f;

// values to store the size of the window 600x600
int winWidth = 600,
winHeight = 600;

// vector of shared pointers to manage portrait instances
vector<shared_ptr<portrait> > portraitList;

void myDisplay(void)
{
	//	This clears the buffer(s) we draw into.  
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// setr the "model view" in order to draw
	glMatrixMode(GL_MODELVIEW);

	//	This says that we start from the lower-left corner of the screen
	glLoadIdentity();

	// itterates for every element in the portrait list vector calling
	// ever instance of the portrait class created
	for (auto portrait : portraitList)
		portrait->draw();
	PortraitWheel myWheel(WheelType::HEADS_ON_WHEEL, WheelSize::LARGE, 5, 0, 0);

	myWheel.draw();

	// switches the drawing on the back buffer to the front screen
	glutSwapBuffers();
}

void myResize(int w, int h) {
	glViewport(0, 0, w, h);
	winWidth = w;
	winHeight = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspectRatio = (float)w / (float)h;

	// Adjust the orthographic projection based on the aspect ratio
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

void myTimerFunc(int value)
{
	// re-prime the timer
	glutTimerFunc(10, myTimerFunc, value);

	// perform the rendering
	glutPostRedisplay();
}


void myInit(void)
{

	myDisplay();
}

int main(int argc, char** argv)
{
	//	Initialize glut and create a new window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// initates the window size and position 
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition(INIT_WIN_X, INIT_WIN_Y);
	// adds a title to the window
	glutCreateWindow("Harry Grenier Assignment 2");

	//	set up the callbacks
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myResize);
	glutTimerFunc(10, myTimerFunc, 0);

	myInit();

	//pushs differnt portrait sizes and locations that we want displayed to the 
	// portraitlist vector creating a new instance of the portrait class each time
	portraitList.push_back(make_shared<portrait>(-7.0f, 1.0f, 0.7f,45.f));
	//portraitlist.push_back(make_shared<portrait>(6.0f, 6.0f, 3.0f));
	//portraitlist.push_back(make_shared<portrait>(-8.0f, 8.0f, 1.0f));
	//portraitlist.push_back(make_shared<portrait>(-8.0f, 0.0f, 0.75f));
	//portraitlist.push_back(make_shared<portrait>(8.0f, -8.0f, 2.5f));
	//portraitlist.push_back(make_shared<portrait>(0.0f, 0.0f, 3.5f));


	glutMainLoop();

	return 0;
}