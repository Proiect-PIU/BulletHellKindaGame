//
// Created by francisc on 11/16/24.
//

#ifndef CPPGAMEDARCUOPENGL_ENTITY_HPP
#define CPPGAMEDARCUOPENGL_ENTITY_HPP

#include "../../../Renderer/Canvas/Element/Element.hpp"
#include "../Stats/BaseStats.hpp"
#include "../../../Components/Collisions/Squares/SquareState.hpp"

class Entity{
public:
    Element *element;
    Graphics *graphics;
    Shape *shape;
    BaseStats *stats;
    SquareState state;
    Entity(Graphics *graphics, BaseStats *stats, SquareState state): graphics(graphics), stats(stats), state(state){
        element = new Element(graphics);
        shape = new Shape(graphics->getVertices(), Shape::ShapeType::POLYGON);
    };
    ~Entity(){
        delete element;
        delete graphics;
        delete stats;
        delete shape;
    }
};

#endif //CPPGAMEDARCUOPENGL_ENTITY_HPP
