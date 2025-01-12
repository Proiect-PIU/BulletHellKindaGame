
#ifndef CPPGAMEDARCUOPENGL_BLOUTPATTERN_HPP
#define CPPGAMEDARCUOPENGL_BLOUTPATTERN_HPP

#include "../EnemyPattern.hpp"
#include "../../../Persistance/Data/Objects/Entity.hpp"
#include "../../../Creators/Loader/Loader.hpp"
#include "../../../Core/Utility/Utils.hpp"

class BloutPattern : public EnemyPattern {
    float shootReset = Utils::randRange(1.0, 1.5);
    float shootTime = shootReset;
    float angularSpeed = 1.0f;

public:
    explicit BloutPattern() = default;

    void updatePattern(Entities &entity) override {
        float deltaTime = Loader::getInstance().getDeltaTime();

        float horizontalRadius = 1.0f;
        float verticalRadius = 0.4f;

        glm::vec3 currentPosition = entity.self->figure->getPosition();
        float currentAngle = glm::atan(
                currentPosition.y / verticalRadius,
                currentPosition.x / horizontalRadius
        );

        currentAngle += angularSpeed * deltaTime;
        if (currentAngle > 2.0f * glm::pi<float>()) {
            currentAngle -= 2.0f * glm::pi<float>();
        }

        float x = horizontalRadius * glm::cos(currentAngle);
        float y = verticalRadius * glm::sin(currentAngle);

        entity.self->figure->setPosition(glm::vec3(x, y, 0.0f));

        if (shootTime >= 0.0f) {
            shootTime -= deltaTime;
            entity.shoot = false;
        } else {
            shootTime = Utils::randRange(1.0, 1.5);
            entity.shoot = true;
        }
    }
};

#endif //CPPGAMEDARCUOPENGL_BLOUTPATTERN_HPP
