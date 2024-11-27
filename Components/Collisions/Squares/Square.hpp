//
// Created by francisc on 11/27/24.
//

#ifndef CPPGAMEDARCUOPENGL_SQUARE_HPP
#define CPPGAMEDARCUOPENGL_SQUARE_HPP

#include "../../../Core/Utility/Collision/Shape.hpp"

enum SquareState{EMPTY, ALLY, ENEMY, WARZONE};

class Square{
    SquareState state = EMPTY;
    std::vector<Shape> shapes = {};
public:
    Square(Shape &shape, SquareState state){
        switch (this->state) {
            case WARZONE:
                break;
            case EMPTY:
                this->state = state;
                break;
            case ALLY:
                if(state == ENEMY)
                    this->state = WARZONE;
                break;
            case ENEMY:
                if(state == ALLY)
                    this->state = WARZONE;
                break;
        }
        shapes.push_back(shape);
    };
};


#endif //CPPGAMEDARCUOPENGL_SQUARE_HPP
