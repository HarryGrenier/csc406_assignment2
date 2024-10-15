#include "PortraitWheel.h"
#include "portrait.h" // Ensure this is the correct header with the lowercase class name
#include <cmath>

PortraitWheel::PortraitWheel(WheelType type, WheelSize size, int num, float x, float y)
    : wheelType(type), wheelSize(size), numPortraits(num) {
    // Set the origin of the wheel
    setPosition(x, y);

    // Initialize the portraits based on the type, size, and number of heads
    initializePortraits(type, size, num, x, y);
}

void PortraitWheel::initializePortraits(WheelType type, WheelSize size, int num, float x, float y) {
    float scale = getScaleFromSize(size);
    float baseRadius = 4.0f; // Adjust this value to control the base size of the circle

    // Increase the radius according to the size of the wheel
    float radius = baseRadius * scale;

    float angleIncrement = 360.0f / num;

    for (int i = 0; i < num; ++i) {
        float angle = i * angleIncrement;
        float radian = angle * (3.1415926f / 180.0f);
        float portraitX = x + cos(radian) * radius;
        float portraitY = y + sin(radian) * radius;

        // Create a new portrait object and store it in the vector
        std::shared_ptr<portrait> portraitObject = std::make_shared<portrait>(portraitX, portraitY, scale, angle);
        portraitObject->setPosition(portraitX, portraitY);

        // Adjust the orientation based on the wheel type
        if (type == WheelType::HEADS_ON_STICKS) {
            portraitObject->setOrientation(angle - 90.0f); // Rotate to face the center
        }
        else if (type == WheelType::HEADS_ON_WHEEL) {
            portraitObject->setOrientation(0); // All faces point upright
        }

        // Add the portrait to the vector and to the ComplexGraphicObject2D parts list
        portraits.push_back(portraitObject);
        addPart(portraitObject);
    }
}

float PortraitWheel::getScaleFromSize(WheelSize size) {
    switch (size) {
    case WheelSize::LARGE: return 1.5f; // Larger scale
    case WheelSize::MEDIUM: return 1.0f; // Medium scale
    case WheelSize::SMALL: return 0.5f; // Smaller scale
    default: return 1.0f; // Default to small if unknown
    }
}
