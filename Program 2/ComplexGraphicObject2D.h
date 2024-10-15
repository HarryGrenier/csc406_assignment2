#ifndef COMPLEXGRAPHICOBJECT2D_H
#define COMPLEXGRAPHICOBJECT2D_H

#include "GraphicObject2D.h"
#include <vector>
#include <memory>

/**
 * @class ComplexGraphicObject2D
 * @brief Represents a complex 2D graphic object composed of multiple parts.
 *
 * This class extends GraphicObject2D to represent a complex graphic object that can be composed of
 * multiple other GraphicObject2D objects. The parts can be added and rendered as a unified object.
 * The draw function is overridden to draw all the parts of the complex object.
 *
 * @note Parts are stored as shared pointers, allowing for flexible memory management.
 *
 * @author Harrison Grenier
 */
class ComplexGraphicObject2D : public GraphicObject2D {
public:
    /**
     * @brief Constructs an empty ComplexGraphicObject2D.
     *
     * Initializes the object with no parts. Parts can be added using the addPart method.
     */
    ComplexGraphicObject2D();

    /**
     * @brief Destructor for ComplexGraphicObject2D.
     *
     * Uses the default destructor as the shared pointers will automatically manage memory cleanup.
     */
    virtual ~ComplexGraphicObject2D() = default;

    /**
     * @brief Adds a part to the complex graphic object.
     *
     * The part must be a shared pointer to a GraphicObject2D. This allows for composition of multiple graphic objects.
     *
     * @param part A shared pointer to the part (a GraphicObject2D) to add to this complex object.
     */
    void addPart(std::shared_ptr<GraphicObject2D> part);

    /**
     * @brief Draws the complex graphic object.
     *
     * This method overrides the draw function from GraphicObject2D to render all the parts that
     * compose this complex object.
     */
    void draw() const override;

private:
    /**
     * @var parts
     * @brief List of parts that make up the complex graphic object.
     *
     * Each part is a shared pointer to a GraphicObject2D. These parts are drawn together as a single object.
     */
    std::vector<std::shared_ptr<GraphicObject2D>> parts;
};

#endif // COMPLEXGRAPHICOBJECT2D_H
