//
// Created by ADI on AZI.
//

#ifndef CPPGAMEDARCUOPENGL_PYLORIPATTERN_HPP
#define CPPGAMEDARCUOPENGL_PYLORIPATTERN_HPP

#include "../EnemyPattern.hpp"
#include "../../../Persistance/Data/Objects/Entity.hpp"
#include "../../../Creators/Loader/Loader.hpp"
#include "../../../Core/Utility/Utils.hpp"
#include <cmath>

class PyloriPattern: public EnemyPattern{
    float shootReset = Utils::randRange(1.5, 2.0);
    float shootTime = shootReset;
    float angle = 0.0f;
    const float a = 0.5f;
    const float b = 0.3f;
    const float speed = 1.0f;

    bool initialized = false;
    float centerX = 0.0f;
    float centerY = 0.0f;
public:
    explicit PyloriPattern() = default;

    void updatePattern(Entities &entity) override {
        float deltaTime = Loader::getInstance().getDeltaTime();

        if (!initialized) {
            centerX = entity.self->figure->getPosition().x;
            centerY = entity.self->figure->getPosition().y;
            initialized = true;
        }

        angle += speed * deltaTime;
        if (angle > 2 * M_PI) {
            angle -= 2 * M_PI;
        }

        float newX = centerX + a * cos(angle);
        float newY = centerY + b * sin(angle);

        entity.self->figure->setPosition(glm::vec3(newX, newY, 0.0));

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

    //~PyloriPattern() override = default;
};

#endif //CPPGAMEDARCUOPENGL_PYLORIPATTERN_HPP
