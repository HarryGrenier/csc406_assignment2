#define _USE_MATH_DEFINES

#include "Road.h"
#include "glPlatform.h"  // OpenGL Utility Toolkit for rendering
#include <cmath>  // For mathematical functions like sin, cos, atan2, etc.

// Constructor to initialize road type
Road::Road(int roadType) : roadType_(roadType), cart_(nullptr), cartDirection_(1) {}

// Implementation of the hard-coded road equations
float Road::roadFunc1(float x) const {
    return 1.0f * std::sin(x) + 2.0f;  // Sine wave road equation
}

float Road::roadFunc2(float x) const {
    return -0.05f * (x - 20.0f) * (x - 20.0f) + 20.0f;  // Big hill equation
}

float Road::roadFunc2Derivative(float x) const {
    return -0.1f * (x - 20.0f);  // Derivative of the big hill equation
}

// First derivative of the road equations to get the slope (dy/dx)
float Road::roadFunc1Derivative(float x) const {
    return 1.0f * std::cos(x);  // Derivative of the sine wave road
}


// Public method to get the y value for a given x based on road type
float Road::getY(float x) const {
    switch (roadType_) {
    case 1:
        return roadFunc1(x);
    case 2:
        return roadFunc2(x);
    default:
        return 0.0f;  // Default flat road if no valid road type is specified
    }
}

// Method to calculate the slope using the derivative of the road function
float Road::getSlope(float x) const {
    switch (roadType_) {
    case 1:
        return roadFunc1Derivative(x);
    case 2:
        return roadFunc2Derivative(x);
    default:
        return 0.0f;  // Default flat slope if no valid road type is specified
    }
}

// Method to create the cart
void Road::createCart(float posX, float posY, float orientation, float scale) {
    cart_ = std::make_shared<Cart>(posX, posY, orientation, scale);
    cartDirection_ = 1;  // Set initial direction to right
}

// Method to move the cart
void Road::moveCart(float speed) {
    if (cart_) {
        float currentX = cart_->getPositionX();
        float slope = getSlope(currentX);  // Get the slope of the road at the current position

        // Calculate the normalized direction vector (tangential to the road)
        float dx = 1.0f / std::sqrt(1.0f + slope * slope);  // Normalized x-component
        float dy = slope * dx;  // Normalized y-component

        // Update the position of the cart using the tangential speed
        float newX = currentX + cartDirection_ * speed * dx;
        float newY = getY(newX);  // Use the road equation to determine the exact y-position

        // Compute the angle of the cart's orientation based on the slope using atan2
        float orientationAngle = std::atan2(dy, dx) * (180.0f / static_cast<float>(M_PI));
        if (cartDirection_ == -1) {  // Moving left
            orientationAngle += 180.0f;  // Keep the cart upright but facing left
        }

        cart_->setPosition(newX, newY);
        cart_->setOrientation(orientationAngle);

        float wheelAngularSpeed = speed / cart_->getWheelRadius();  // Convert tangential speed to angular speed
        cart_->rotateWheels(wheelAngularSpeed);


        // Check if the cart has reached the right or left edge of the world
        if (newX >= 40.0f || newX <= 0.0f) {  // Assuming the world range is 0 to 40
            flipCartDirection();
        }
    }
}


// Method to flip the cart's direction when it reaches the edge
void Road::flipCartDirection() {
    cartDirection_ *= -1;  // Reverse the cart's direction
    if (cart_) {
        cart_->setDirection(cartDirection_ == -1);  // Update the cart's direction
    }
}


// Method to draw the cart
void Road::drawCart() const {
    if (cart_) {
        cart_->draw();
    }
}

// Method to draw the road as a curve using a line strip
void Road::draw() const {
    glColor3f(0.0f, 0.0f, 1.0f);  // Set road color to blue
    glBegin(GL_LINE_STRIP);
    for (float x = 0.0f; x <= 40.0f; x += 0.1f) {  // Adjust range and step size as needed
        float y = getY(x);
        glVertex2f(x, y);
    }
    glEnd();
}
