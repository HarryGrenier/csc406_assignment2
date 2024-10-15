#ifndef CART_H
#define CART_H

#include "ComplexGraphicObject2D.h"

/**
 * @class Cart
 * @brief Represents a cart object with wheels, position, orientation, and scale.
 *
 * This class models a cart that inherits from ComplexGraphicObject2D. It includes properties for position,
 * orientation, and wheel rotation, and provides methods for updating these properties as well as drawing
 * the cart. It also tracks the movement direction of the cart.
 *
 * @author Harrison Grenier
 */
class Cart : public ComplexGraphicObject2D {
private:
    /**
     * @var positionX_
     * @brief X-coordinate of the cart's position.
     */
    float positionX_;

    /**
     * @var positionY_
     * @brief Y-coordinate of the cart's position.
     */
    float positionY_;

    /**
     * @var orientation_
     * @brief Orientation angle of the cart.
     */
    float orientation_;

    /**
     * @var scale_
     * @brief Scale factor of the cart.
     */
    float scale_;

    /**
     * @var wheelRotationAngle_
     * @brief Rotation angle of the cart's wheels.
     */
    float wheelRotationAngle_;

    /**
     * @var cartWidth_
     * @brief Width of the cart.
     */
    float cartWidth_;

    /**
     * @var cartHeight_
     * @brief Height of the cart.
     */
    float cartHeight_;

    /**
     * @var wheelRadius_
     * @brief Radius of the cart's wheels.
     */
    float wheelRadius_;

    /**
     * @var movingLeft_
     * @brief Indicates the direction of the cart's movement (left or right).
     */
    bool movingLeft_;

public:
    /**
     * @brief Constructs a Cart object with specified position, orientation, and scale.
     *
     * @param posX Initial X-coordinate position of the cart. Default is 0.
     * @param posY Initial Y-coordinate position of the cart. Default is 0.
     * @param orientation Initial orientation angle of the cart. Default is 0.
     * @param scale Initial scale factor of the cart. Default is 1.0.
     */
    Cart(float posX = 0.f, float posY = 0.f, float orientation = 0.f, float scale = 1.0f);

    /**
     * @brief Sets the position of the cart.
     *
     * @param x New X-coordinate position.
     * @param y New Y-coordinate position.
     */
    void setPosition(float x, float y);

    /**
     * @brief Sets the orientation of the cart.
     *
     * @param angle New orientation angle.
     */
    void setOrientation(float angle);

    /**
     * @brief Sets the movement direction of the cart.
     *
     * @param isMovingLeft Boolean value indicating if the cart is moving to the left (true) or right (false).
     */
    void setDirection(bool isMovingLeft);

    /**
     * @brief Gets the X-coordinate of the cart's position.
     *
     * @return The current X-coordinate of the cart.
     */
    float getPositionX() const;

    /**
     * @brief Gets the Y-coordinate of the cart's position.
     *
     * @return The current Y-coordinate of the cart.
     */
    float getPositionY() const;

    /**
     * @brief Gets the orientation angle of the cart.
     *
     * @return The current orientation angle of the cart.
     */
    float getOrientation() const;

    /**
     * @brief Gets the radius of the cart's wheels.
     *
     * @return The radius of the wheels.
     */
    float getWheelRadius() const;

    /**
     * @brief Draws the cart and its components on the screen.
     *
     * Overrides the draw method from ComplexGraphicObject2D to render the cart.
     */
    void draw() const override;

    /**
     * @brief Rotates the wheels of the cart based on the given speed.
     *
     * @param speed The speed at which the wheels should rotate.
     */
    void rotateWheels(float speed);
};

#endif // CART_H
