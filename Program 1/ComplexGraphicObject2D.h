#ifndef COMPLEXGRAPHICOBJECT2D_H
#define COMPLEXGRAPHICOBJECT2D_H

#include "GraphicObject2D.h"
#include <vector>
#include <memory>

class ComplexGraphicObject2D : public GraphicObject2D {
public:
    ComplexGraphicObject2D();
    virtual ~ComplexGraphicObject2D();

    void addPart(std::shared_ptr<GraphicObject2D> part);
    virtual void draw() const override;

private:
    std::vector<std::shared_ptr<GraphicObject2D>> parts;
};

#endif // COMPLEXGRAPHICOBJECT2D_H


