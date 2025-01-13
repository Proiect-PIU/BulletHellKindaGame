
#ifndef CPPGAMEDARCUOPENGL_ZIGZAGPATTERN_HPP
#define CPPGAMEDARCUOPENGL_ZIGZAGPATTERN_HPP

#include <iostream>
#include "Loader/Loader.hpp"
#include "../BulletPattern.hpp"
#include "../../Entities/Bullets/Bullet.hpp"

class ZigzagPattern : public BulletPattern {
public:
    ZigzagPattern(int nrOfBullets): BulletPattern(nrOfBullets) {}
    void updatePattern(std::vector<Bullet*>& bullets) override {
        Canvas* canvas = Loader::getInstance().getCanvas();
        CollisionMatrix* matrix = Loader::getInstance().getMatrix();
        float deltaTime = Loader::getInstance().getDeltaTime();

        float amplitude = 0.1f;
        float frequency = 5.0f;
        for (Bullet* bullet : bullets) {
            bullet->stats->pos.y += bullet->stats->speed * deltaTime;

            bullet->stats->pos.x = bullet->stats->initPos.x +
                    amplitude * glm::sin(frequency * bullet->stats->pos.y) - 0.07;

            bullet->self->figure->setPosition(bullet->stats->pos);
            matrix->addEntity(*bullet, bullet->self->state);
            canvas->addElement(std::make_unique<Element>(*bullet->self->getElement()));
        }
    }
};

#endif //CPPGAMEDARCUOPENGL_ZIGZAGPATTERN_HPP
