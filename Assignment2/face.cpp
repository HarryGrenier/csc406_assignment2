#include <iostream>
#include "glPlatform.h"
#include "Face.h"

using namespace std;

// Initialize the static count variable
unsigned int face::count_ = 0;

// Constructor initializing the face with position, orientation, and scale
face::face(float cx, float cy, float size, float orientation)
    : GraphicObject2D(cx, cy, orientation, size), size_(size), idx_(count_++) {
    cout << "Face " << idx_ << " initialized at: (" << cx << "," << cy << "), orientation: " << orientation << " degrees, size: " << size << endl;
}

// Draw the face with transformations (applies position, scale, and orientation)
void face::draw() const {
    glPushMatrix();

    // Apply translation, rotation, and scaling transformations
    glTranslatef(getPositionX(), getPositionY(), 0);
    glRotatef(getOrientation(), 0, 0, 1);
    glScalef(getScale(), getScale(), 1);

    // Draw the face components
    drawEllipse(0, 0, size_, size_, 200, 0.878f, 0.694f, 0.517f);  // Face
    drawEyes();
    drawPupils();
    drawNose();
    drawMouth();
    drawEars();
    drawEyebrows();
    drawHat();

    glPopMatrix();
}

// Draws an ellipse with given center coordinates, semi-major and semi-minor axes, 
// number of segments (for smoothness), and RGB color
void face::drawEllipse(float xc, float yc, float Semi_major, float Semi_minor, int segments, float r, float g, float b) const {
    float theta, x, y;
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        theta = 2.0f * 3.1415926f * float(i) / float(segments);  // Angle in radians
        x = Semi_major * cosf(theta);  // x = a * cos(theta)
        y = Semi_minor * sinf(theta);  // y = b * sin(theta)
        glVertex2f(x + xc, y + yc);  // Translate to center (xc, yc)
    }
    glEnd();
}

// Drawing helper methods
void face::drawEyes() const {
    float eyeWidth = size_ * 0.2f;  // Eyes are 20% of face width
    float eyeHeight = size_ * 0.15f;  // Eyes are 15% of face height
    float eyeOffsetX = size_ * 0.3f;  // Distance of eyes from center horizontally
    float eyeOffsetY = size_ * 0.25f;  // Eyes positioned slightly above the face center

    drawEllipse(-eyeOffsetX, eyeOffsetY, eyeWidth, eyeHeight, 100, 1.0f, 1.0f, 1.0f); // Left eye
    drawEllipse(eyeOffsetX, eyeOffsetY, eyeWidth, eyeHeight, 100, 1.0f, 1.0f, 1.0f); // Right eye
}

void face::drawNose() const {
    float noseWidth = size_ * 0.1f;  // Nose is 10% of face width
    float noseHeight = size_ * 0.3f;  // Nose is 30% of face height
    drawEllipse(0, -noseHeight / 2.0f, noseWidth, noseHeight, 100, 0.8f, 0.5f, 0.4f);  // Nose
}

void face::drawMouth() const {
    float mouthWidth = size_ * 0.5f;  // Mouth is 50% of face width
    float mouthHeight = size_ * 0.1f;  // Mouth height is 10% of face height
    float mouthOffsetY = size_ * 0.6f;  // Mouth is slightly below the center of the face
    drawEllipse(0, -mouthOffsetY, mouthWidth, mouthHeight, 100, 1.0f, 0.0f, 0.0f);  // Mouth
}

void face::drawEars() const {
    float earWidth = size_ * 0.15f;  // Ears are 15% of face width
    float earHeight = size_ * 0.3f;  // Ears are 30% of face height
    float earOffsetX = size_;  // Distance of ears from center horizontally (outside the face)
    float earOffsetY = size_ * 0.25f;  // Ears are aligned with the eyes vertically

    // Left ear (slightly outside the face)
    drawEllipse(-earOffsetX, earOffsetY, earWidth, earHeight, 100, 0.878f, 0.694f, 0.517f);

    // Right ear (slightly outside the face)
    drawEllipse(earOffsetX, earOffsetY, earWidth, earHeight, 100, 0.878f, 0.694f, 0.517f);
}

void face::drawEyebrows() const {
    float eyebrowWidth = size_ * 0.3f;  // Eyebrows are slightly wider than the eyes (30% of face width)
    float eyebrowHeight = size_ * 0.05f;  // Thin rectangles for the eyebrows (5% of face height)
    float eyeOffsetX = size_ * 0.3f;  // Distance of eyes from center horizontally
    float eyebrowOffsetY = size_ * 0.35f;  // Eyebrows positioned above the eyes

    // Draw left eyebrow
    glColor3f(0.3f, 0.2f, 0.1f);  // Dark brown color for eyebrows
    glBegin(GL_QUADS);
    glVertex2f(-eyeOffsetX - eyebrowWidth / 2, eyebrowOffsetY);
    glVertex2f(-eyeOffsetX + eyebrowWidth / 2, eyebrowOffsetY);
    glVertex2f(-eyeOffsetX + eyebrowWidth / 2, eyebrowOffsetY + eyebrowHeight);
    glVertex2f(-eyeOffsetX - eyebrowWidth / 2, eyebrowOffsetY + eyebrowHeight);
    glEnd();

    // Draw right eyebrow
    glBegin(GL_QUADS);
    glVertex2f(eyeOffsetX - eyebrowWidth / 2, eyebrowOffsetY);
    glVertex2f(eyeOffsetX + eyebrowWidth / 2, eyebrowOffsetY);
    glVertex2f(eyeOffsetX + eyebrowWidth / 2, eyebrowOffsetY + eyebrowHeight);
    glVertex2f(eyeOffsetX - eyebrowWidth / 2, eyebrowOffsetY + eyebrowHeight);
    glEnd();
}

void face::drawPupils() const {
    float pupilWidth = size_ * 0.07f;  // Pupils are smaller than the eyes (7% of face width)
    float pupilHeight = size_ * 0.07f;  // Pupils are circular
    float eyeOffsetX = size_ * 0.3f;  // Distance of eyes from center horizontally
    float eyeOffsetY = size_ * 0.25f;  // Eyes positioned slightly above the face center

    // Draw left pupil
    drawEllipse(-eyeOffsetX, eyeOffsetY, pupilWidth, pupilHeight, 100, 0.0f, 0.0f, 0.0f);  // Black pupils

    // Draw right pupil
    drawEllipse(eyeOffsetX, eyeOffsetY, pupilWidth, pupilHeight, 100, 0.0f, 0.0f, 0.0f);  // Black pupils
}

void face::drawHat() const {
    // Hat brim: A wide, flat ellipse slightly larger than the face
    float brimWidth = size_ * 1.2f;  // Hat brim is 120% of face width
    float brimHeight = size_ * 0.05f;  // Hat brim is 10% of face height
    float brimOffsetY = size_ * 0.7f;  // The brim sits just above the face

    // Draw the brim of the hat as an ellipse
    drawEllipse(0.0f, brimOffsetY, brimWidth, brimHeight, 100, 0.3f, 0.2f, 0.1f);  // Dark color for the brim

    // Hat body: A tall rectangle above the brim
    float hatWidth = size_ * 1.3f;  // Hat body is 150% of face width
    float hatHeight = size_ * 1.6f;  // Hat body height is smaller than face height
    float hatOffsetY = brimOffsetY + (brimHeight - 0.05);  // Position the hat body above the brim

    // Draw the body of the hat as a rectangle
    glColor3f(0.3f, 0.2f, 0.1f);  // Blue color for the hat
    glBegin(GL_QUADS);
    glVertex2f(-hatWidth / 2, hatOffsetY);              // Bottom left
    glVertex2f(hatWidth / 2, hatOffsetY);               // Bottom right
    glVertex2f(hatWidth / 2, hatOffsetY + hatHeight);  // Top right
    glVertex2f(-hatWidth / 2, hatOffsetY + hatHeight);  // Top left
    glEnd();
}


// Setter and getter methods
void face::setPosition(float x, float y) {
    GraphicObject2D::setPosition(x, y);  // Call parent class method
}

void face::setOrientation(float angle) {
    GraphicObject2D::setOrientation(angle);  // Call parent class method
}

void face::setScale(float scale) {
    GraphicObject2D::setScale(scale);  // Call parent class method
}

float face::getPositionX() const {
    return GraphicObject2D::getPositionX();  // Get position from parent class
}

float face::getPositionY() const {
    return GraphicObject2D::getPositionY();  // Get position from parent class
}

float face::getOrientation() const {
    return GraphicObject2D::getOrientation();  // Get orientation from parent class
}

float face::getScale() const {
    return GraphicObject2D::getScale();  // Get scale from parent class
}

