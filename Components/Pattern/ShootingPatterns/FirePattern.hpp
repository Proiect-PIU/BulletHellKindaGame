
#ifndef CPPGAMEDARCUOPENGL_FIREPATTERN_HPP
#define CPPGAMEDARCUOPENGL_FIREPATTERN_HPP

#include <iostream>
#include "Loader/Loader.hpp"
#include "../BulletPattern.hpp"
#include "../../Entities/Bullets/Bullet.hpp"

class FirePattern : public BulletPattern {
public:
    FirePattern(int nrOfBullets): BulletPattern(nrOfBullets) {}
    void updatePattern(std::vector<Bullet*>& bullets) override {
        Canvas* canvas = Loader::getInstance().getCanvas();
        CollisionMatrix* matrix = Loader::getInstance().getMatrix();
        float deltaTime = Loader::getInstance().getDeltaTime();

        float spreadAngle = glm::radians(45.0f);
        float angleStep = bullets.size() > 1 ? spreadAngle / (bullets.size() - 1) : 0.0f;
        float startAngle = -spreadAngle / 2.0f;

        float zigzagAmplitude = 0.005f;
        float zigzagFrequency = 1.0f;

        for (size_t i = 0; i < bullets.size(); ++i) {
            Bullet* bullet = bullets[i];

            if (bullet->stats->currentAngle == 0.0f) {
                bullet->stats->currentAngle = startAngle + i * angleStep;
            }

            bullet->stats->pos.x += -glm::sin(bullet->stats->currentAngle) * bullet->stats->speed * deltaTime;
            bullet->stats->pos.y += glm::cos(bullet->stats->currentAngle) * bullet->stats->speed * deltaTime;

            float zigzagOffset = zigzagAmplitude * glm::sin(zigzagFrequency * bullet->stats->pos.y);
            bullet->stats->pos.x += zigzagOffset;

            bullet->self->figure->setPosition(bullet->stats->pos);
            matrix->addEntity(*bullet, bullet->self->state);
            canvas->addElement(std::make_unique<Element>(*bullet->self->getElement()));
        }
    }
};

#endif //CPPGAMEDARCUOPENGL_FIREPATTERN_HPP
