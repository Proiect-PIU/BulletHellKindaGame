//
// Created by francisc on 11/20/24.
//

#ifndef CPPGAMEDARCUOPENGL_ENEMYPATTERN_HPP
#define CPPGAMEDARCUOPENGL_ENEMYPATTERN_HPP


#include "../../Renderer/Canvas/Canvas.hpp"

class EnemyPattern{
public:
    explicit EnemyPattern()= default;
    virtual void updatePattern(float deltaTime, Canvas &canvas) = 0;
    ~EnemyPattern() = default;
};



#endif //CPPGAMEDARCUOPENGL_ENEMYPATTERN_HPP
