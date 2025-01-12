
#ifndef CPPGAMEDARCUOPENGL_FIGURE_HPP
#define CPPGAMEDARCUOPENGL_FIGURE_HPP

#include "../../../Renderer/Canvas/Element/Element.hpp"
#include "../../../Core/Utility/Collision/Shape.hpp"

class Figure{
    Element *element;
    Shape *shape;
public:
    Figure(Element *e, Shape *s): element(e), shape(s){};
    [[nodiscard]] glm::vec3 getPosition() const { return element->getPosition();};
    void setPosition(const glm::vec3& newPos) {
        element->setPosition(newPos);
        shape->update(element->getGraphics()->getVertices(), element->getModelMatrix());
    };
    void setRotation(float angle, const glm::vec3& axis) {
        element->setRotation(angle, axis);
        shape->update(element->getGraphics()->getVertices(), element->getModelMatrix());
    };
    void setScale(const glm::vec3& newScale) {
        element->setScale(newScale);
        shape->update(element->getGraphics()->getVertices(), element->getModelMatrix());
    };
    Element *getElement(){ return element;};
    Shape *getShape(){ return shape;};
    [[nodiscard]] float getWidth() const{ return element->getGraphics()->getWidth(); };
    [[nodiscard]] float getHeight() const{ return element->getGraphics()->getHeight(); };
    ~Figure(){
        if (!element) {
            delete element;
        }
        if (!shape) {
            delete shape;
        }
        element = nullptr;
        shape = nullptr;
    };
};

#endif //CPPGAMEDARCUOPENGL_FIGURE_HPP
