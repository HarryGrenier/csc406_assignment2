#include "PortraitWheel.h"
#include "portrait.h"
#include <cmath>

// constructor for the portraitwheel class
PortraitWheel::PortraitWheel(WheelType type, WheelSize size, int num, float x, float y)
    : ComplexGraphicObject2D(), wheelType(type), wheelSize(size), numPortraits(num) {
    // Set the origin of the wheel
    setPosition(x, y);

    // Initialize the portraits based on the type, size, and number of heads
    initializePortraits(type, size, num, x, y);
}

void PortraitWheel::initializePortraits(WheelType type, WheelSize size, int num, float x, float y) {
    float scale = getScaleFromSize(size); // calls wheelsize enum to get the floating point size of the scale
    float baseRadius = 4.0f; // sets the base size of the wheel so its not the same size as the portraits

    // Increase the radius according to the size of the wheel
    float radius = baseRadius * scale; // calculates the radius of the wheel
    float angleIncrement = 360.0f / num; // for the whole circle divide it up acording to the number of heads needed

    // caculate the position for each of the portraits
    for (int i = 0; i < num; ++i) {
        float angle = i * angleIncrement;
        float radian = angle * (3.1415926f / 180.0f);
        float portraitX = x + cos(radian) * radius;
        float portraitY = y + sin(radian) * radius;

        // Create a new portrait object and add it directly to the ComplexGraphicObject2D parts list
        std::shared_ptr<portrait> portraitObject = std::make_shared<portrait>(portraitX, portraitY, scale, angle);
        portraitObject->setPosition(portraitX, portraitY);

        // Adjust the orientation based on the wheel type
        if (type == WheelType::HEADS_ON_STICKS) {
            portraitObject->setOrientation(angle - 90.0f); // Rotate to face the center
        }
        else if (type == WheelType::HEADS_ON_WHEEL) {
            portraitObject->setOrientation(0); // All faces point upright
        }

        // Add the portrait to the ComplexGraphicObject2D's parts list
        addPart(portraitObject);
    }
}

float PortraitWheel::getScaleFromSize(WheelSize size) {
    switch (size) {
    case WheelSize::LARGE: return 1.5f; // Larger scale
    case WheelSize::MEDIUM: return 1.0f; // Medium scale
    case WheelSize::SMALL: return 0.5f; // Smaller scale
    default: return 1.0f; // Default to medium if unknown
    }
}

