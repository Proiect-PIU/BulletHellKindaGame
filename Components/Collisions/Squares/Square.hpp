//
// Created by francisc on 11/27/24.
//

#ifndef CPPGAMEDARCUOPENGL_SQUARE_HPP
#define CPPGAMEDARCUOPENGL_SQUARE_HPP


#include "SquareState.hpp"
#include "../../Entities/Entities.hpp"

class Square{
    SquareState state;

    std::vector<Entities*> entities;
public:
    Square(){
        state = EMPTY;
        entities = {};
    };
    void AddEntity(Entities &entity, SquareState newState) {
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
        entities.push_back(&entity);
    };
    [[nodiscard]] const std::vector<Entities*>& GetEntities() const { return entities; }
    [[nodiscard]] SquareState GetState() const { return state; }
};


#endif //CPPGAMEDARCUOPENGL_SQUARE_HPP
