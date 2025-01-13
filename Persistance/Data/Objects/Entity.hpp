//
// Created by francisc on 11/16/24.
//

#ifndef CPPGAMEDARCUOPENGL_ENTITY_HPP
#define CPPGAMEDARCUOPENGL_ENTITY_HPP

#include "../../../Renderer/Canvas/Element/Element.hpp"
#include "../Stats/BaseStats.hpp"
#include "../../../Components/Collisions/Squares/SquareState.hpp"
#include "../Figure/Figure.hpp"

class Entity{
public:
    Figure *figure;
    BaseStats *stats;
    SquareState state;
    Entity(Graphics *graphics, BaseStats *stats, SquareState state): stats(stats), state(state){
        figure = new Figure(new Element(graphics), new Shape(graphics->getVertices(), Shape::ShapeType::POLYGON));
    };
    [[nodiscard]] Element *getElement() const{ return figure->getElement();};
    [[nodiscard]] Shape *getShape() const{ return figure->getShape();};
    ~Entity(){
        if (!stats) {
            delete stats;
        }
        if (!figure) {
            delete figure;
        }
        stats = nullptr;
        figure = nullptr;
    }
};

#endif //CPPGAMEDARCUOPENGL_ENTITY_HPP
