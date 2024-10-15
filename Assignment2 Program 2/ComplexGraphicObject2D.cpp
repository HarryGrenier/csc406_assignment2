#include "ComplexGraphicObject2D.h"

ComplexGraphicObject2D::ComplexGraphicObject2D() : GraphicObject2D() {
}

// stores all the specifc graphic objects contained in the complex graphic object
void ComplexGraphicObject2D::addPart(std::shared_ptr<GraphicObject2D> part) {
    parts.push_back(part);
}

void ComplexGraphicObject2D::draw() const {
    // Iterate through the list of parts and call their draw methods
    for (const auto& part : parts) {
        if (part) {
            part->draw(); // Draw each part relative to this ComplexGraphicObject2D
        }
    }
}
