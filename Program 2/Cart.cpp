
#define _USE_MATH_DEFINES

#include "Cart.h"
#include "glPlatform.h"
#include <cmath>
#include <iostream>

// Constructor implementation
Cart::Cart(float posX, float posY, float orientation, float scale)
    : positionX_(posX), positionY_(posY), orientation_(orientation), scale_(scale),
    wheelRotationAngle_(0.0f), movingLeft_(false) {
    cartWidth_ = 3.0f * scale;
    cartHeight_ = 1.5f * scale;
    wheelRadius_ = 0.5f * scale;  // Initialize the wheel radius
}
void Cart::rotateWheels(float tangentialSpeed) {
    // Calculate the angular speed of the wheel based on the tangential speed
    float angularSpeed = (tangentialSpeed / wheelRadius_) * (180.0f / static_cast<float>(M_PI)); // Convert to degrees

    // Reverse the direction of the wheel rotation if the cart is moving left
    if (movingLeft_) {
        angularSpeed *= -1.0f;
    }

    // Update the rotation angle of the wheels
    wheelRotationAngle_ += angularSpeed;
    if (wheelRotationAngle_ >= 360.0f) {
        wheelRotationAngle_ -= 360.0f;  // Keep the angle within the 0-360 range
    }
    else if (wheelRotationAngle_ < 0.0f) {
        wheelRotationAngle_ += 360.0f;  // Keep the angle within the 0-360 range
    }
}


// Modified draw method to handle different appearances when moving left or right
void Cart::draw() const {
    glPushMatrix();  // Save the current transformation matrix

    // Translate to the cart's current position using the updated positionX_ and positionY_
    glTranslatef(positionX_, positionY_, 0.0f);

    // Apply rotation based on the cart's orientation
    glRotatef(orientation_, 0.0f, 0.0f, 1.0f);  // Rotate around the z-axis

    // If the cart is moving to the left, rotate it 180 degrees to face the other direction
    if (movingLeft_) {
        glRotatef(180.0f, 0.0f, 0.0f, 1.0f);  // Rotate the cart 180 degrees on the z-axis
    }

    // Draw the cart body (a simple rectangle)
    glColor3f(0.5f, 0.5f, 0.5f);  // Gray color for the cart body
    glBegin(GL_QUADS);
    glVertex2f(-cartWidth_ / 2, -cartHeight_ / 2);
    glVertex2f(cartWidth_ / 2, -cartHeight_ / 2);
    glVertex2f(cartWidth_ / 2, cartHeight_ / 2);
    glVertex2f(-cartWidth_ / 2, cartHeight_ / 2);
    glEnd();

    float triangleOffset = (movingLeft_) ? -cartWidth_ / 2 : cartWidth_ / 2;
    glBegin(GL_TRIANGLES);
    glVertex2f(triangleOffset, cartHeight_ / 2);
    glVertex2f(triangleOffset + 0.5f * (movingLeft_ ? -1 : 1), 0.0f);
    glVertex2f(triangleOffset, -cartHeight_ / 2);
    glEnd();

    // Draw the wheels with spokes
    for (int i = -1; i <= 1; i += 2) {  // Two wheels, one at each end
        glPushMatrix();
        glTranslatef(i * (cartWidth_ / 3), -cartHeight_ / 2, 0.0f);  // Move to the wheel position
        glRotatef(wheelRotationAngle_, 0.0f, 0.0f, 1.0f);  // Rotate the wheel according to its angle

        // Draw the wheel as a circle
        glColor3f(1.0f, 1.0f, 1.0f);  // White color for the wheel
        glBegin(GL_LINE_LOOP);
        for (int angle = 0; angle < 360; angle += 30) {
            float rad = angle * static_cast<float>(M_PI) / 180.0f;
            glVertex2f(wheelRadius_ * cos(rad), wheelRadius_ * sin(rad));
        }
        glEnd();

        // Draw the spokes for the wheel
        glBegin(GL_LINES);
        for (int angle = 0; angle < 360; angle += 90) {
            float rad = angle * static_cast<float>(M_PI) / 180.0f;
            glVertex2f(0, 0);
            glVertex2f(wheelRadius_ * cos(rad), wheelRadius_ * sin(rad));
        }
        glEnd();

        glPopMatrix();  // Restore the transformation matrix for each wheel
    }

    glPopMatrix();  // Restore the original transformation matrix
}

float Cart::getWheelRadius() const {
    return wheelRadius_;
}

// Getter for positionX
float Cart::getPositionX() const {
    return positionX_;
}

// Getter for positionY
float Cart::getPositionY() const {
    return positionY_;
}

// Setter for position
void Cart::setPosition(float x, float y) {
    positionX_ = x;
    positionY_ = y;
}

// Setter for orientation
void Cart::setOrientation(float angle) {
    orientation_ = angle;
}

// Setter for direction
void Cart::setDirection(bool isMovingLeft) {
    movingLeft_ = isMovingLeft;
}

// Getter for orientation (if needed)
float Cart::getOrientation() const {
    return orientation_;
}
