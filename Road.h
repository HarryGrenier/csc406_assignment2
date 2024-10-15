#ifndef ROAD_H
#define ROAD_H

#include <memory>
#include "Cart.h"

/**
 * @class Road
 * @brief Represents a road with a cart moving on it and provides functionality for managing the cart's movement.
 *
 * The Road class contains different road equations, allows for the creation and movement of a cart,
 * and supports rendering the road and cart on the screen. The cart can move left or right, and the slope of
 * the road can be calculated using predefined road functions.
 *
 * @author Harrison Grenier
 */
class Road {
private:
    /**
     * @var roadType_
     * @brief Determines which road equation to use for rendering and slope calculation.
     */
    int roadType_;

    /**
     * @var cart_
     * @brief Smart pointer to a Cart object.
     */
    std::shared_ptr<Cart> cart_;

    /**
     * @var cartDirection_
     * @brief Direction of the cart's movement: 1 for right, -1 for left.
     */
    int cartDirection_;

    /**
     * @brief Road equation for the first type of road.
     *
     * @param x X-coordinate input for the equation.
     * @return The corresponding Y-coordinate for the given X, according to road equation 1.
     */
    float roadFunc1(float x) const;

    /**
     * @brief Road equation for the second type of road.
     *
     * @param x X-coordinate input for the equation.
     * @return The corresponding Y-coordinate for the given X, according to road equation 2.
     */
    float roadFunc2(float x) const;

    /**
     * @brief First derivative of the first road equation for slope calculation.
     *
     * @param x X-coordinate input for the derivative.
     * @return The slope of road equation 1 at the given X.
     */
    float roadFunc1Derivative(float x) const;

    /**
     * @brief First derivative of the second road equation for slope calculation.
     *
     * @param x X-coordinate input for the derivative.
     * @return The slope of road equation 2 at the given X.
     */
    float roadFunc2Derivative(float x) const;

public:
    /**
     * @brief Constructs a Road object with a specified road type.
     *
     * @param roadType Type of road equation to use (default is 1).
     */
    Road(int roadType = 1);

    /**
     * @brief Returns the Y-coordinate value for a given X-coordinate using the selected road equation.
     *
     * @param x X-coordinate for which to calculate the corresponding Y-coordinate.
     * @return The Y-coordinate on the road at the given X.
     */
    float getY(float x) const;

    /**
     * @brief Calculates the slope of the road at the given X-coordinate using the road's derivative.
     *
     * @param x X-coordinate for which to calculate the slope.
     * @return The slope of the road at the given X.
     */
    float getSlope(float x) const;

    /**
     * @brief Draws the road on the screen.
     *
     * This method is responsible for rendering the road according to its type.
     */
    void draw() const;

    /**
     * @brief Creates a cart on the road at the specified position, orientation, and scale.
     *
     * @param posX Initial X-coordinate position of the cart.
     * @param posY Initial Y-coordinate position of the cart.
     * @param orientation Initial orientation of the cart.
     * @param scale Initial scale of the cart.
     */
    void createCart(float posX, float posY, float orientation, float scale);

    /**
     * @brief Moves the cart along the road at the given speed.
     *
     * @param speed Speed at which the cart should move.
     */
    void moveCart(float speed);

    /**
     * @brief Draws the cart on the screen.
     *
     * This method is responsible for rendering the cart on the road.
     */
    void drawCart() const;

    /**
     * @brief Flips the direction of the cart's movement.
     *
     * Changes the cart's movement direction from left to right or vice versa.
     */
    void flipCartDirection();
};

#endif // ROAD_H
