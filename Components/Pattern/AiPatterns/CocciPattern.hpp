//
// Created by francisc on 11/20/24.
//

#ifndef CPPGAMEDARCUOPENGL_COCCIPATTERN_HPP
#define CPPGAMEDARCUOPENGL_COCCIPATTERN_HPP


#include "../EnemyPattern.hpp"
#include "../../../Persistance/Data/Objects/Entity.hpp"

class CocciPattern: public EnemyPattern{
public:
    explicit CocciPattern() = default;
    void updatePattern(float deltaTime, Canvas &canvas, Entities &entity) override {
        entity.move(RIGHT, deltaTime);
    };
};


#endif //CPPGAMEDARCUOPENGL_COCCIPATTERN_HPP
