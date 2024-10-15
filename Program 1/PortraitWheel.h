#ifndef PORTRAITWHEEL_H
#define PORTRAITWHEEL_H

#include "ComplexGraphicObject2D.h"
#include "portrait.h" // Correct header file for the lowercase portrait class
#include <vector>
#include <memory>

enum class WheelType {
    HEADS_ON_STICKS,
    HEADS_ON_WHEEL
};

enum class WheelSize {
    LARGE,
    MEDIUM,
    SMALL
};

class PortraitWheel : public ComplexGraphicObject2D {
public:
    PortraitWheel(WheelType type, WheelSize size, int num, float x, float y);

private:
    void initializePortraits(WheelType type, WheelSize size, int num, float x, float y);
    float getScaleFromSize(WheelSize size);

    WheelType wheelType;
    WheelSize wheelSize;
    int numPortraits;

    std::vector<std::shared_ptr<portrait>> portraits; // Vector to store portraits
};

#endif // PORTRAITWHEEL_H
