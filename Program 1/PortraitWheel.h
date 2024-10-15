#ifndef PORTRAITWHEEL_H
#define PORTRAITWHEEL_H

#include "ComplexGraphicObject2D.h"
#include "portrait.h"
#include <memory>

/**
 * @enum WheelType
 * @brief Enum to store different wheel types for portrait arrangement.
 *
 * Defines two types of portrait wheels:
 * - HEADS_ON_STICKS: Portraits oriented towards the center of the wheel.
 * - HEADS_ON_WHEEL: Portraits oriented upright around the wheel.
 */
enum class WheelType {
    HEADS_ON_STICKS,  /**< Portraits pointing towards the center */
    HEADS_ON_WHEEL    /**< Portraits oriented upright */
};

/**
 * @enum WheelSize
 * @brief Enum to store the size options for the portrait wheel.
 *
 * Defines three size options for the portrait wheel:
 * - LARGE: A large-sized wheel.
 * - MEDIUM: A medium-sized wheel.
 * - SMALL: A small-sized wheel.
 */
enum class WheelSize {
    LARGE,   /**< Large-sized wheel */
    MEDIUM,  /**< Medium-sized wheel */
    SMALL    /**< Small-sized wheel */
};

/**
 * @class PortraitWheel
 * @brief A complex graphic object representing a wheel of portraits.
 *
 * The PortraitWheel class inherits from ComplexGraphicObject2D and arranges a specified
 * number of portrait objects in a circular pattern. The portraits can be oriented based on
 * the selected WheelType and scaled according to the selected WheelSize.
 *
 * @note The class supports different configurations for the orientation and size of the portraits.
 *
 * @see ComplexGraphicObject2D
 * @see portrait
 *
 * @author Harrison Grenier
 */
class PortraitWheel : public ComplexGraphicObject2D {
public:
    /**
     * @brief Constructs a PortraitWheel object with specified type, size, and number of portraits.
     *
     * @param type The type of portrait wheel (e.g., HEADS_ON_STICKS, HEADS_ON_WHEEL).
     * @param size The size of the wheel (e.g., LARGE, MEDIUM, SMALL).
     * @param num The number of portraits on the wheel.
     * @param x The X-coordinate of the wheel's center.
     * @param y The Y-coordinate of the wheel's center.
     */
    PortraitWheel(WheelType type, WheelSize size, int num, float x, float y);

private:
    /**
     * @brief Initializes the portraits in the wheel based on the specified type, size, and number.
     *
     * @param type The type of portrait wheel (orientation of the portraits).
     * @param size The size of the wheel (scaling factor for the portraits).
     * @param num The number of portraits to arrange on the wheel.
     * @param x The X-coordinate of the wheel's center.
     * @param y The Y-coordinate of the wheel's center.
     */
    void initializePortraits(WheelType type, WheelSize size, int num, float x, float y);

    /**
     * @brief Returns the scale factor based on the selected wheel size.
     *
     * @param size The size of the wheel.
     * @return The scale factor corresponding to the wheel size.
     */
    float getScaleFromSize(WheelSize size);

    /**
     * @var wheelType
     * @brief Stores the type of the wheel (HEADS_ON_STICKS or HEADS_ON_WHEEL).
     */
    WheelType wheelType;

    /**
     * @var wheelSize
     * @brief Stores the size of the wheel (LARGE, MEDIUM, or SMALL).
     */
    WheelSize wheelSize;

    /**
     * @var numPortraits
     * @brief The number of portraits arranged on the wheel.
     */
    int numPortraits;
};

#endif // PORTRAITWHEEL_H
