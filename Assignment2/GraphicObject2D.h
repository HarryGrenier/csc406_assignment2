#ifndef GRAPHICOBJECT2D_H
#define GRAPHICOBJECT2D_H

/**
 * @class GraphicObject2D
 * @brief Base class for 2D graphic objects with position, orientation, and scale properties.
 *
 * This abstract class defines a 2D object with a position in a coordinate system, an orientation
 * (rotation in degrees), and a scale. It provides basic functionality for manipulating these properties.
 * Derived classes must implement the `draw` method to handle the specific rendering of the object.
 *
 * @note Since this is an abstract class, the `draw` method must be implemented by derived classes.
 *
 * @see ComplexGraphicObject2D
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
     * @brief Orientation (rotation) of the object in degrees.
     */
    float orientation_;

    /**
     * @var scale_
     * @brief Scale factor of the object.
     */
    float scale_;

public:
    /**
     * @brief Constructs a GraphicObject2D with the given position, orientation, and scale.
     *
     * @param posX X-coordinate of the object's position. Default is 0.
     * @param posY Y-coordinate of the object's position. Default is 0.
     * @param orientation Initial orientation (rotation) in degrees. Default is 0.
     * @param scale Initial scale factor. Default is 1.0.
     */
    GraphicObject2D(float posX = 0, float posY = 0, float orientation = 0, float scale = 1.0f)
        : positionX_(posX), positionY_(posY), orientation_(orientation), scale_(scale) {}

    /**
     * @brief Sets the position of the object.
     *
     * @param x New X-coordinate of the object's position.
     * @param y New Y-coordinate of the object's position.
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
     * @param angle The new orientation angle in degrees.
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
     * @param scale The new scale factor.
     */
    void setScale(float scale) { scale_ = scale; }

    /**
     * @brief Gets the scale factor of the object.
     *
     * @return The current scale factor of the object.
     */
    float getScale() const { return scale_; }

    /**
     * @brief Pure virtual method to draw the object.
     *
     * This method must be implemented by any class that inherits from GraphicObject2D.
     * It is responsible for rendering the object based on its properties (position, orientation, scale).
     */
    virtual void draw() const = 0;
};

#endif // GRAPHICOBJECT2D_H
