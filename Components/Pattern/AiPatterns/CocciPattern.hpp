//
// Created by francisc on 11/20/24.
//

#ifndef CPPGAMEDARCUOPENGL_COCCIPATTERN_HPP
#define CPPGAMEDARCUOPENGL_COCCIPATTERN_HPP

#include "../EnemyPattern.hpp"
#include "../../../Persistance/Data/Objects/Entity.hpp"
#include "../../../Creators/Loader/Loader.hpp"
#include "../../../Core/Utility/Utils.hpp"

class CocciPattern: public EnemyPattern{
    float shootReset = Utils::randRange(1.5, 2.0);
    float shootTime = shootReset;
    bool swDir = Utils::randRange(-1, 1) >= 0;
public:
    explicit CocciPattern() = default;
    void updatePattern(Entities &entity) override {
        float deltaTime = Loader::getInstance().getDeltaTime();
        if (entity.self->figure->getPosition().x < -0.9) {
            swDir = true;
        } else if (entity.self->figure->getPosition().x > 0.9) {
            swDir = false;
        }
        if (swDir) {
            entity.move(RIGHT);
        } else {
            entity.move(LEFT);
        }
        if (shootTime >= 0.0) {
            shootTime -= deltaTime;
            entity.shoot = false;
        } else {
            shootTime = Utils::randRange(1.5, 2.0);
            entity.shoot = true;
            float x = entity.self->figure->getPosition().x;
            x += Utils::randRange(-0.01, 0.01);
            float y = entity.self->figure->getPosition().y;
            y += Utils::randRange(-0.03, 0.01);
            entity.self->figure->setPosition(glm::vec3(x, y, 0.0));
        }

    };
    //~CocciPattern()override = default;
};


#endif //CPPGAMEDARCUOPENGL_COCCIPATTERN_HPP
