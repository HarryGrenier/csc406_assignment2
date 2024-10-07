class GraphicObject2D {
private:
    float positionX_, positionY_;
    float orientation_;  // Rotation in degrees
    float scale_;

public:
    GraphicObject2D(float posX = 0, float posY = 0, float orientation = 0, float scale = 1.0f)
        : positionX_(posX), positionY_(posY), orientation_(orientation), scale_(scale) {}

    // Getter and Setter for Position
    void setPosition(float x, float y) { positionX_ = x; positionY_ = y; }

    // Add the missing getters
    float getPositionX() const { return positionX_; }
    float getPositionY() const { return positionY_; }

    // Getter and Setter for Orientation
    void setOrientation(float angle) { orientation_ = angle; }
    float getOrientation() const { return orientation_; }

    // Getter and Setter for Scale
    void setScale(float scale) { scale_ = scale; }
    float getScale() const { return scale_; }

    // Pure virtual draw method to be overridden
    virtual void draw() const = 0;
};