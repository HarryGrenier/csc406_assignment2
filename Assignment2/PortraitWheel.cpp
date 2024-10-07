#include "PortraitWheel.h"

// Constructor for PortraitWheel
PortraitWheel::PortraitWheel(WheelType type, WheelSize size, int num, float x, float y)
    : type_(type), size_(size), numHeads_(num) {
    setPosition(x, y); // Set the position of the PortraitWheel
    createHeads(); // Create the face objects distributed along the circle
}

// Destructor to clean up dynamically allocated memory
PortraitWheel::~PortraitWheel() {
    for (face* head : heads_) {
        delete head;
    }
}

void PortraitWheel::draw() const {
    for (const face* head : heads_) {
        head->draw();  // Call the draw method for each face object
    }
}

// Method to create and position the face objects
void PortraitWheel::createHeads() {
    float scaleFactor;
    switch (size_) {
    case WheelSize::LARGE: scaleFactor = 1.5f; break;
    case WheelSize::MEDIUM: scaleFactor = 1.0f; break;
    case WheelSize::SMALL: scaleFactor = 0.5f; break;
    }

    float angleIncrement = 2 * 3.1415926f / numHeads_; // Calculate the angle between each head
    for (int i = 0; i < numHeads_; ++i) {
        float angle = i * angleIncrement;
        float headX = getPositionX() + cos(angle) * scaleFactor; // Calculate X position
        float headY = getPositionY() + sin(angle) * scaleFactor; // Calculate Y position

        // Create a new face object with the calculated position and scale
        face* newFace = new face(headX, headY, scaleFactor);
        heads_.push_back(newFace);

        // Adjust the orientation of the face based on the WheelType
        if (type_ == WheelType::HEADS_ON_STICKS) {
            newFace->setOrientation(angle * (180.0f / 3.1415926f)); // Orient to point toward the center
        }
    }
}