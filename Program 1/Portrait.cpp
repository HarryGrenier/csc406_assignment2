#include <iostream>
#include "glPlatform.h"
#include "portrait.h"

using namespace std;

// Initialize the static count variable
unsigned int portrait::count_ = 0;

// Constructor initializing the portrait with position, orientation, and scale
portrait::portrait(float cx, float cy, float size, float orientation)
    : GraphicObject2D(cx, cy, orientation, size), size_(size), idx_(count_++) {
    cout << "portrait " << idx_ << " initialized at: (" << cx << "," << cy << "), orientation: " << orientation << " degrees, size: " << size << endl;
}

// Draw the portrait with transformations (applies position, scale, and orientation)
void portrait::draw() const {
    glPushMatrix();

    // Apply translation, rotation, and scaling transformations
    glTranslatef(getPositionX(), getPositionY(), 0);
    glRotatef(getOrientation(), 0, 0, 1);
    glScalef(getScale(), getScale(), 1);

    // Draw the portrait components
    drawEllipse(0, 0, size_, size_, 200, 0.878f, 0.694f, 0.517f);  // portrait
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
void portrait::drawEllipse(float xc, float yc, float Semi_major, float Semi_minor, int segments, float r, float g, float b) const {
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
void portrait::drawEyes() const {
    float eyeWidth = size_ * 0.2f;  // Eyes are 20% of portrait width
    float eyeHeight = size_ * 0.15f;  // Eyes are 15% of portrait height
    float eyeOffsetX = size_ * 0.3f;  // Distance of eyes from center horizontally
    float eyeOffsetY = size_ * 0.25f;  // Eyes positioned slightly above the portrait center

    drawEllipse(-eyeOffsetX, eyeOffsetY, eyeWidth, eyeHeight, 100, 1.0f, 1.0f, 1.0f); // Left eye
    drawEllipse(eyeOffsetX, eyeOffsetY, eyeWidth, eyeHeight, 100, 1.0f, 1.0f, 1.0f); // Right eye
}

void portrait::drawNose() const {
    float noseWidth = size_ * 0.1f;  // Nose is 10% of portrait width
    float noseHeight = size_ * 0.3f;  // Nose is 30% of portrait height
    drawEllipse(0, -noseHeight / 2.0f, noseWidth, noseHeight, 100, 0.8f, 0.5f, 0.4f);  // Nose
}

void portrait::drawMouth() const {
    float mouthWidth = size_ * 0.5f;  // Mouth is 50% of portrait width
    float mouthHeight = size_ * 0.1f;  // Mouth height is 10% of portrait height
    float mouthOffsetY = size_ * 0.6f;  // Mouth is slightly below the center of the portrait
    drawEllipse(0, -mouthOffsetY, mouthWidth, mouthHeight, 100, 1.0f, 0.0f, 0.0f);  // Mouth
}

void portrait::drawEars() const {
    float earWidth = size_ * 0.15f;  // Ears are 15% of portrait width
    float earHeight = size_ * 0.3f;  // Ears are 30% of portrait height
    float earOffsetX = size_;  // Distance of ears from center horizontally (outside the portrait)
    float earOffsetY = size_ * 0.25f;  // Ears are aligned with the eyes vertically

    // Left ear (slightly outside the portrait)
    drawEllipse(-earOffsetX, earOffsetY, earWidth, earHeight, 100, 0.878f, 0.694f, 0.517f);

    // Right ear (slightly outside the portrait)
    drawEllipse(earOffsetX, earOffsetY, earWidth, earHeight, 100, 0.878f, 0.694f, 0.517f);
}

void portrait::drawEyebrows() const {
    float eyebrowWidth = size_ * 0.3f;  // Eyebrows are slightly wider than the eyes (30% of portrait width)
    float eyebrowHeight = size_ * 0.05f;  // Thin rectangles for the eyebrows (5% of portrait height)
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

void portrait::drawPupils() const {
    float pupilWidth = size_ * 0.07f;  // Pupils are smaller than the eyes (7% of portrait width)
    float pupilHeight = size_ * 0.07f;  // Pupils are circular
    float eyeOffsetX = size_ * 0.3f;  // Distance of eyes from center horizontally
    float eyeOffsetY = size_ * 0.25f;  // Eyes positioned slightly above the portrait center

    // Draw left pupil
    drawEllipse(-eyeOffsetX, eyeOffsetY, pupilWidth, pupilHeight, 100, 0.0f, 0.0f, 0.0f);  // Black pupils

    // Draw right pupil
    drawEllipse(eyeOffsetX, eyeOffsetY, pupilWidth, pupilHeight, 100, 0.0f, 0.0f, 0.0f);  // Black pupils
}

void portrait::drawHat() const {
    // Hat brim: A wide, flat ellipse slightly larger than the portrait
    float brimWidth = size_ * 1.2f;  // Hat brim is 120% of portrait width
    float brimHeight = size_ * 0.05f;  // Hat brim is 5% of portrait height
    float brimOffsetY = size_ * 0.7f;  // The brim sits just above the portrait

    // Draw the brim of the hat as an ellipse
    drawEllipse(0.0f, brimOffsetY, brimWidth, brimHeight, 100, 0.3f, 0.2f, 0.1f);  // Dark color for the brim

    // Hat body: A tall rectangle above the brim
    float hatWidth = size_ * 1.3f;  // Hat body is 130% of portrait width
    float hatHeight = size_ * 1.6f; // set the portraits hat height
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
void portrait::setPosition(float x, float y) {
    GraphicObject2D::setPosition(x, y);  
}

void portrait::setOrientation(float angle) {
    GraphicObject2D::setOrientation(angle);  
}

void portrait::setScale(float scale) {
    GraphicObject2D::setScale(scale);  
}

float portrait::getPositionX() const {
    return GraphicObject2D::getPositionX();  
}

float portrait::getPositionY() const {
    return GraphicObject2D::getPositionY();  
}

float portrait::getOrientation() const {
    return GraphicObject2D::getOrientation();  
}

float portrait::getScale() const {
    return GraphicObject2D::getScale(); 
}

