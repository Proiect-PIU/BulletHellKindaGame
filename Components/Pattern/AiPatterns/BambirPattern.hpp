
#ifndef CPPGAMEDARCUOPENGL_BAMBIRPATTERN_HPP
#define CPPGAMEDARCUOPENGL_BAMBIRPATTERN_HPP

#include "../EnemyPattern.hpp"
#include "../../../Persistance/Data/Objects/Entity.hpp"
#include "../../../Creators/Loader/Loader.hpp"
#include "../../../Core/Utility/Utils.hpp"

class BambirPattern: public EnemyPattern{
    float shootReset = Utils::randRange(1.5, 2.0);
    float shootTime = shootReset;
public:
    explicit BambirPattern() = default;
    void updatePattern(Entities &entity) override {
        float deltaTime = Loader::getInstance().getDeltaTime();
        static float direction = 1.0f;

        float amplitude = 0.3f;
        float frequency = 10.0f;
        float horizontalSpeed = 0.2f;
        float verticalOffset = 0.6f;

        float x = entity.self->figure->getPosition().x;
        float y = entity.self->figure->getPosition().y;

        x += direction * horizontalSpeed * deltaTime;

        if (x >= 0.9f) {
            x = 0.9f;
            direction = -1.0f;
        } else if (x <= -0.9f) {
            x = -0.9f;
            direction = 1.0f;
        }
        y = amplitude * glm::sin(frequency * x) + verticalOffset;
        entity.self->figure->setPosition(glm::vec3(x, y, 0.0f));

        if (shootTime >= 0.0f) {
            shootTime -= deltaTime;
            entity.shoot = false;
        } else {
            shootTime = Utils::randRange(1.5f, 2.0f);
            entity.shoot = true;
        }
    }
};

#endif //CPPGAMEDARCUOPENGL_BAMBIRPATTERN_HPP
