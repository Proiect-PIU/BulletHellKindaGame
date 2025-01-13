
#ifndef CPPGAMEDARCUOPENGL_DNAPATTERN_HPP
#define CPPGAMEDARCUOPENGL_DNAPATTERN_HPP

#include <iostream>
#include "Loader/Loader.hpp"
#include "../BulletPattern.hpp"
#include "../../Entities/Bullets/Bullet.hpp"

class DnaPattern : public BulletPattern {
public:
    DnaPattern(int nrOfBullets): BulletPattern(nrOfBullets) {}
    void updatePattern(std::vector<Bullet*>& bullets) override {
        Canvas* canvas = Loader::getInstance().getCanvas();
        CollisionMatrix* matrix = Loader::getInstance().getMatrix();
        float deltaTime = Loader::getInstance().getDeltaTime();

        float amplitude = 0.2f;
        float frequency = 4.0f;
        bool flip = false;
        for (Bullet* bullet : bullets) {
            bullet->stats->pos.y += bullet->stats->speed * deltaTime;

            if(flip) {
                bullet->stats->pos.x = bullet->stats->initPos.x +
                                       amplitude * glm::cos(frequency * bullet->stats->pos.y) + 0.1;
                flip = false;
            } else {
                bullet->stats->pos.x = bullet->stats->initPos.x +
                                       amplitude * glm::sin(frequency * bullet->stats->pos.y) + 0.1 ;
                flip = true;
            }

            bullet->self->figure->setPosition(bullet->stats->pos);
            matrix->addEntity(*bullet, bullet->self->state);
            canvas->addElement(std::make_unique<Element>(*bullet->self->getElement()));
        }
    }
};

#endif //CPPGAMEDARCUOPENGL_DNAPATTERN_HPP
