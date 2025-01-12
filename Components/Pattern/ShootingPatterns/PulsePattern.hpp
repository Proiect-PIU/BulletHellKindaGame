
#ifndef CPPGAMEDARCUOPENGL_PULSEPATTERN_HPP
#define CPPGAMEDARCUOPENGL_PULSEPATTERN_HPP

#include <iostream>
#include "Loader/Loader.hpp"
#include "../BulletPattern.hpp"
#include "../../Entities/Bullets/Bullet.hpp"
#include "../../../Core/Utility/Utils.hpp"

class PulsePattern : public BulletPattern {
public:
    PulsePattern(int nrOfBullets) : BulletPattern(nrOfBullets) {}

    void updatePattern(std::vector<Bullet*>& bullets) override {
        Canvas* canvas = Loader::getInstance().getCanvas();
        CollisionMatrix* matrix = Loader::getInstance().getMatrix();
        float deltaTime = Loader::getInstance().getDeltaTime();

        float amplitude = 0.4f;
        float frequency = 5.0f;

        for (Bullet* bullet : bullets) {
            if (bullet->stats->currentAngle == 0.0f) {
                bullet->stats->currentAngle = Utils::randRange(-1.0f, 1.0f);
            }

            bullet->stats->pos.y += bullet->stats->speed * deltaTime;

            float randomFactor = bullet->stats->currentAngle;
            bullet->stats->pos.x = bullet->stats->initPos.x +
                                   randomFactor * amplitude * glm::sin(frequency * bullet->stats->pos.y);

            bullet->self->figure->setPosition(bullet->stats->pos);
            matrix->addEntity(*bullet, bullet->self->state);
            canvas->addElement(std::make_unique<Element>(*bullet->self->getElement()));
        }
    }
};

#endif //CPPGAMEDARCUOPENGL_PULSEPATTERN_HPP
