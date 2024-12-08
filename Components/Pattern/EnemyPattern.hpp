//
// Created by francisc on 11/20/24.
//

#ifndef CPPGAMEDARCUOPENGL_ENEMYPATTERN_HPP
#define CPPGAMEDARCUOPENGL_ENEMYPATTERN_HPP


#include "../../Renderer/Canvas/Canvas.hpp"
#include "../Entities/Entities.hpp"

class EnemyPattern{
public:
    explicit EnemyPattern() = default;
    virtual void updatePattern(Entities &entity) = 0;
    virtual ~EnemyPattern() = default;
};



#endif //CPPGAMEDARCUOPENGL_ENEMYPATTERN_HPP
