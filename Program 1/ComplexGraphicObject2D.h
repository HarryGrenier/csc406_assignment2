#ifndef COMPLEXGRAPHICOBJECT2D_H
#define COMPLEXGRAPHICOBJECT2D_H

#include "GraphicObject2D.h"
#include <vector>
#include <memory>

/**
 * @class ComplexGraphicObject2D
 * @brief A complex 2D graphic object composed of multiple parts.
 *
 * This class extends GraphicObject2D to allow the creation of complex graphic objects
 * made up of multiple parts. These parts are stored as shared pointers to other
 * GraphicObject2D objects. The object can be drawn by rendering all its parts.
 *
 * @note This class manages the composition of parts, enabling objects to be built from smaller components.
 *
 * @see GraphicObject2D
 *
 * @author Harrison Grenier
 */
class ComplexGraphicObject2D : public GraphicObject2D {
public:
    /**
     * @brief Constructs a new ComplexGraphicObject2D object.
     *
     * Initializes an empty complex graphic object. Additional parts can be added using `addPart`.
     */
    ComplexGraphicObject2D();

    /**
     * @brief Default virtual destructor for ComplexGraphicObject2D.
     *
     * Ensures proper destruction of the object and its parts through shared pointer management.
     */
    virtual ~ComplexGraphicObject2D() = default;

    /**
     * @brief Adds a part to the complex graphic object.
     *
     * Each part is a shared pointer to a GraphicObject2D, allowing for flexibility in composing
     * the overall object from multiple components.
     *
     * @param part A shared pointer to a GraphicObject2D object that is part of the complex object.
     */
    void addPart(std::shared_ptr<GraphicObject2D> part);

    /**
     * @brief Draws the complex graphic object by rendering all its parts.
     *
     * This method overrides the base class's draw method and draws each part of the complex object.
     */
    void draw() const override;

private:
    /**
     * @var parts
     * @brief A list of parts that make up the complex graphic object.
     *
     * Each part is a shared pointer to a GraphicObject2D object. These parts are drawn together
     * to form the complete complex object.
     */
    std::vector<std::shared_ptr<GraphicObject2D>> parts;
};

#endif // COMPLEXGRAPHICOBJECT2D_H
