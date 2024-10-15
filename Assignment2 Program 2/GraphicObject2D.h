#ifndef GRAPHICOBJECT2D_H
#define GRAPHICOBJECT2D_H

/**
 * @class GraphicObject2D
 * @brief Base class for 2D graphic objects with position, orientation, and scale properties.
 *
 * This abstract class defines a 2D object in a coordinate system, allowing the object to have a
 * position, an orientation (rotation), and a scale. Derived classes must implement the `draw` method
 * to handle the specific rendering of the object.
 *
 * @note This is an abstract class, and the `draw` method must be implemented by derived classes.
 *
 * @author Harrison Grenier
 */
class GraphicObject2D {
private:
    /**
     * @var positionX_
     * @brief X-coordinate of the object's position.
     */
    float positionX_;

    /**
     * @var positionY_
     * @brief Y-coordinate of the object's position.
     */
    float positionY_;

    /**
     * @var orientation_
     * @brief Orientation angle (rotation) of the object in degrees.
     */
    float orientation_;

    /**
     * @var scale_
     * @brief Scale factor of the object.
     */
    float scale_;

public:
    /**
     * @brief Constructs a 2D graphic object with specified position, orientation, and scale.
     *
     * @param posX Initial X-coordinate position. Default is 0.
     * @param posY Initial Y-coordinate position. Default is 0.
     * @param orientation Initial orientation angle in degrees. Default is 0.
     * @param scale Initial scale factor. Default is 1.0.
     */
    GraphicObject2D(float posX = 0, float posY = 0, float orientation = 0, float scale = 1.0f)
        : positionX_(posX), positionY_(posY), orientation_(orientation), scale_(scale) {}

    /**
     * @brief Sets the position of the object.
     *
     * @param x New X-coordinate position.
     * @param y New Y-coordinate position.
     */
    void setPosition(float x, float y) { positionX_ = x; positionY_ = y; }

    /**
     * @brief Gets the X-coordinate of the object's position.
     *
     * @return The current X-coordinate of the object.
     */
    float getPositionX() const { return positionX_; }

    /**
     * @brief Gets the Y-coordinate of the object's position.
     *
     * @return The current Y-coordinate of the object.
     */
    float getPositionY() const { return positionY_; }

    /**
     * @brief Sets the orientation (rotation) of the object.
     *
     * @param angle New orientation angle in degrees.
     */
    void setOrientation(float angle) { orientation_ = angle; }

    /**
     * @brief Gets the orientation (rotation) of the object.
     *
     * @return The current orientation angle of the object in degrees.
     */
    float getOrientation() const { return orientation_; }

    /**
     * @brief Sets the scale of the object.
     *
     * @param scale New scale factor.
     */
    void setScale(float scale) { scale_ = scale; }

    /**
     * @brief Gets the scale factor of the object.
     *
     * @return The current scale factor of the object.
     */
    float getScale() const { return scale_; }

    /**
     * @brief Pure virtual function to draw the object.
     *
     * This method must be overridden by derived classes to implement object-specific drawing functionality.
     */
    virtual void draw() const = 0;
};

#endif // GRAPHICOBJECT2D_H
