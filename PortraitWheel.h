#ifndef PORTRAITWHEEL_H
#define PORTRAITWHEEL_H

#include "GraphicObject2D.h"
#include "Face.h"  // Assuming Face class is defined in Face.h
#include <vector>
#include <cmath>

enum class WheelType {
    HEADS_ON_STICKS,
    HEADS_ON_WHEEL
};

enum class WheelSize {
    LARGE,
    MEDIUM,
    SMALL
};

class PortraitWheel : public GraphicObject2D {
public:
    PortraitWheel(WheelType type, WheelSize size, int num, float x, float y);
    ~PortraitWheel(); // Destructor to manage memory

    // Implement the draw method as required by the base class
    void draw() const override;

private:
    WheelType type_;
    WheelSize size_;
    int numHeads_;
    std::vector<face*> heads_; // Vector to store the head pointers

    void createHeads(); // Function to create the heads
};

#endif // PORTRAITWHEEL_H
