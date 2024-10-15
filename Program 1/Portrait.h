#ifndef PORTRAIT_H
#define PORTRAIT_H

#include "GraphicObject2D.h"  // Assuming this class provides basic 2D object properties

/**
 * @class portrait
 * @brief A class representing a portrait object that can be drawn with various features such as eyes, nose, mouth, etc.
 *
 * This class inherits from GraphicObject2D and provides functionality to draw a portrait with customizable features.
 * It includes helper methods to draw specific facial features like eyes, nose, and mouth. Additionally, the class
 * allows setting and getting the position, orientation, and scale of the portrait.
 *
 * @see GraphicObject2D
 *
 * @note This class includes static data members to track portrait instances.
 *
 * @author Harrison Grenier
 */
class portrait : public GraphicObject2D {
private:
    /**
     * @var size_
     * @brief Size of the portrait.
     */
    float size_;

    /**
     * @var idx_
     * @brief Unique index of the portrait instance.
     */
    unsigned int idx_;

    /**
     * @var count_
     * @brief Static variable to keep track of the total number of portrait instances.
     */
    static unsigned int count_;

public:
    /**
     * @brief Constructs a portrait with specified position, size, and orientation.
     *
     * @param cx X-coordinate of the portrait's position.
     * @param cy Y-coordinate of the portrait's position.
     * @param size Size of the portrait.
     * @param orientation Orientation (rotation) of the portrait in degrees. Default is 0.0f.
     */
    portrait(float cx, float cy, float size, float orientation = 0.0f);

    /**
     * @brief Deleted default constructor to prevent instantiation without parameters.
     */
    portrait() = delete;

    /**
     * @brief Default destructor for the portrait class.
     */
    ~portrait() = default;

    /**
     * @brief Overridden draw method to render the portrait.
     *
     * This method calls helper functions to draw different parts of the portrait.
     */
    void draw() const override;

    /**
     * @brief Helper method to draw an ellipse (used for facial features).
     *
     * @param xc X-coordinate of the ellipse center.
     * @param yc Y-coordinate of the ellipse center.
     * @param Semi_major Semi-major axis of the ellipse.
     * @param Semi_minor Semi-minor axis of the ellipse.
     * @param segments Number of segments for drawing the ellipse.
     * @param r Red color component.
     * @param g Green color component.
     * @param b Blue color component.
     */
    void drawEllipse(float xc, float yc, float Semi_major, float Semi_minor, int segments, float r, float g, float b) const;

    /**
     * @brief Helper method to draw the eyes of the portrait.
     */
    void drawEyes() const;

    /**
     * @brief Helper method to draw the nose of the portrait.
     */
    void drawNose() const;

    /**
     * @brief Helper method to draw the mouth of the portrait.
     */
    void drawMouth() const;

    /**
     * @brief Helper method to draw the ears of the portrait.
     */
    void drawEars() const;

    /**
     * @brief Helper method to draw the eyebrows of the portrait.
     */
    void drawEyebrows() const;

    /**
     * @brief Helper method to draw the pupils of the portrait.
     */
    void drawPupils() const;

    /**
     * @brief Helper method to draw a hat on the portrait.
     */
    void drawHat() const;

    /**
     * @brief Sets the position of the portrait.
     *
     * @param x X-coordinate of the portrait's new position.
     * @param y Y-coordinate of the portrait's new position.
     */
    void setPosition(float x, float y);

    /**
     * @brief Sets the orientation of the portrait.
     *
     * @param angle New orientation angle of the portrait in degrees.
     */
    void setOrientation(float angle);

    /**
     * @brief Sets the scale of the portrait.
     *
     * @param scale New scale factor of the portrait.
     */
    void setScale(float scale);

    /**
     * @brief Gets the X-coordinate of the portrait's position.
     *
     * @return The current X-coordinate of the portrait.
     */
    float getPositionX() const;

    /**
     * @brief Gets the Y-coordinate of the portrait's position.
     *
     * @return The current Y-coordinate of the portrait.
     */
    float getPositionY() const;

    /**
     * @brief Gets the orientation (rotation) of the portrait.
     *
     * @return The current orientation angle of the portrait in degrees.
     */
    float getOrientation() const;

    /**
     * @brief Gets the scale factor of the portrait.
     *
     * @return The current scale factor of the portrait.
     */
    float getScale() const;
};

#endif /* PORTRAIT_H */
