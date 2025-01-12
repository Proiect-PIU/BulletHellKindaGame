//
// Created by francisc on 11/20/24.
//

#ifndef CPPGAMEDARCUOPENGL_COCCIPATTERN_HPP
#define CPPGAMEDARCUOPENGL_COCCIPATTERN_HPP


#include "../EnemyPattern.hpp"
#include "../../../Persistance/Data/Objects/Entity.hpp"
#include "../../../Creators/Loader/Loader.hpp"

class CocciPattern: public EnemyPattern{
    float reset = 0.0f;
    float shootReset = 1.0f;
    float shootTime = 1.0f;
    float cooldown = 3.0f;
    float time = 0.0f;
    bool swDir = false;
public:
    explicit CocciPattern() = default;
    void updatePattern(Entities &entity) override {
        float deltaTime = Loader::getInstance().getDeltaTime();
        if (time <= reset) {
            time = cooldown;
            swDir = !swDir;
        }
        if (shootTime >= 0.0) {
            shootTime -= deltaTime;
            entity.shoot = false;
        } else {
            shootTime = shootReset;
            entity.shoot = true;
        }
        if (time > reset) {
            time -= deltaTime;
        }
        if (swDir) {
            entity.move(RIGHT);
        } else {
            entity.move(LEFT);
        }
    };
    //~CocciPattern()override = default;
};


#endif //CPPGAMEDARCUOPENGL_COCCIPATTERN_HPP
