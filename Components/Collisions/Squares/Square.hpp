//
// Created by francisc on 11/27/24.
//

#ifndef CPPGAMEDARCUOPENGL_SQUARE_HPP
#define CPPGAMEDARCUOPENGL_SQUARE_HPP

#include "../../../Core/Utility/Collision/Shape.hpp"
#include "SquareState.hpp"


class Square{
    SquareState state;
    std::vector<Shape> shapes;
public:
    Square(){
        state = EMPTY;
        shapes = {};
    };
    void AddShape(const Shape &shape, SquareState newState) {
        switch (state) {
            case WARZONE:
                break;
            case EMPTY:
                state = newState;
                break;
            case ALLY:
                if(newState == ENEMY)
                    state = WARZONE;
                break;
            case ENEMY:
                if(newState == ALLY)
                    state = WARZONE;
                break;
        }
        shapes.push_back(shape);
    };
    [[nodiscard]] const std::vector<Shape>& GetShapes() const { return shapes; }
    [[nodiscard]] SquareState GetState() const { return state; }
};


#endif //CPPGAMEDARCUOPENGL_SQUARE_HPP
