//
// Created by francisc on 11/16/24.
//

#ifndef CPPGAMEDARCUOPENGL_ENTITY_HPP
#define CPPGAMEDARCUOPENGL_ENTITY_HPP

#include "../../../Renderer/Canvas/Element/Element.hpp"
#include "../Stats/BaseStats.hpp"

class Entity{
public:
    Element *element;
    Graphics *graphics;
    Shape *shape;
    BaseStats *stats;
    Entity(Graphics *graphics, BaseStats *stats): graphics(graphics), stats(stats){
        element = new Element(graphics);
        shape = new Shape(graphics->getVertices(), Shape::ShapeType::POLYGON);
    };
    ~Entity(){
        delete element;
        delete graphics;
        delete stats;
    }
};

#endif //CPPGAMEDARCUOPENGL_ENTITY_HPP
