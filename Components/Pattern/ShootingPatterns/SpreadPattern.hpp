
#ifndef CPPGAMEDARCUOPENGL_SPREADPATTERN_HPP
#define CPPGAMEDARCUOPENGL_SPREADPATTERN_HPP

#include <iostream>
#include "Loader/Loader.hpp"
#include "../BulletPattern.hpp"
#include "../../Entities/Bullets/Bullet.hpp"

class SpreadPattern : public BulletPattern {
public:
    SpreadPattern(int nrOfBullets): BulletPattern(nrOfBullets) {}
    void updatePattern(std::vector<Bullet*>& bullets) override {
        Canvas* canvas = Loader::getInstance().getCanvas();
        CollisionMatrix* matrix = Loader::getInstance().getMatrix();
        float deltaTime = Loader::getInstance().getDeltaTime();

        for (Bullet* bullet : bullets) {
            float deltaX = glm::sin(bullet->stats->currentAngle) * bullet->stats->speed * deltaTime;
            float deltaY = glm::cos(bullet->stats->currentAngle) * bullet->stats->speed * deltaTime;

            bullet->stats->pos.x += deltaX;
            bullet->stats->pos.y += deltaY;

            bullet->self->figure->setPosition(bullet->stats->pos);
            matrix->addEntity(*bullet, bullet->self->state);
            canvas->addElement(std::make_unique<Element>(*bullet->self->getElement()));
        }
    }
};

#endif //CPPGAMEDARCUOPENGL_SPREADPATTERN_HPP
