#ifndef face_h
#define face_h

#include "GraphicObject2D.h"  // Assuming this class provides basic 2D object properties

class face : public GraphicObject2D {
private:
    // Face properties
    float size_;

    unsigned int idx_;
    static unsigned int count_;

public:
    // Constructor for specifying origin, orientation, and scale
    face(float cx, float cy, float size, float orientation = 0.0f);

    face() = delete;
    ~face() = default;

    // Overridden draw method
    void draw() const override;

    // Drawing helper methods
    void drawEllipse(float xc, float yc, float Semi_major, float Semi_minor, int segments, float r, float g, float b) const;
    void drawEyes() const;
    void drawNose() const;
    void drawMouth() const;
    void drawEars() const;
    void drawEyebrows() const;
    void drawPupils() const;
    void drawHat() const;

    // Getter and setter methods
    void setPosition(float x, float y);
    void setOrientation(float angle);
    void setScale(float scale);
    float getPositionX() const;
    float getPositionY() const;
    float getOrientation() const;
    float getScale() const;
};

#endif /* face_h */