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
    Square();
    void AddEntity(Entities &entity, SquareState newState);
    [[nodiscard]] const std::vector<Entities*>& GetEntities() const;
    [[nodiscard]] SquareState GetState() const;
};


#endif //CPPGAMEDARCUOPENGL_SQUARE_HPP
