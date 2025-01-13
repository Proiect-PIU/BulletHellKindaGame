
#include "Square.hpp"

Square::Square(){
    state = EMPTY;
    entities = {};
};

void Square::AddEntity(Entities &entity, SquareState newState) {
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

const std::vector<Entities*>& Square::GetEntities() const { return entities; }
SquareState Square::GetState() const { return state; }