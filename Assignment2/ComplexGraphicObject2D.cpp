#include "ComplexGraphicObject2D.h"

ComplexGraphicObject2D::ComplexGraphicObject2D() {
    // Constructor implementation
}

ComplexGraphicObject2D::~ComplexGraphicObject2D() {
    // Destructor implementation
}

void ComplexGraphicObject2D::addPart(std::shared_ptr<GraphicObject2D> part) {
    parts.push_back(part);
}

void ComplexGraphicObject2D::draw() const {
    for (const auto& part : parts) {
        part->draw();
    }
}
