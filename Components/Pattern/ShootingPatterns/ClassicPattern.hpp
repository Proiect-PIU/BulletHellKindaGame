//
// Created by francisc on 10/15/24.
//

#ifndef CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP
#define CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP

#include <iostream>
#include "Loader/Loader.hpp"
#include "../BulletPattern.hpp"
#include "../../Entities/Bullets/Bullet.hpp"


class ClassicPattern: public BulletPattern{
public:
    ClassicPattern(int nrOfBullets): BulletPattern(nrOfBullets){};
    void updatePattern(std::vector<Bullet*>& bullets) override {
        Canvas* canvas = Loader::getInstance().getCanvas();
        CollisionMatrix* matrix = Loader::getInstance().getMatrix();
        float deltaTime = Loader::getInstance().getDeltaTime();

        for (Bullet* bullet : bullets) {
            bullet->stats->pos.y += bullet->stats->speed * deltaTime;
            bullet->self->figure->setPosition(bullet->stats->pos);

            matrix->addEntity(*bullet, bullet->self->state);
            canvas->addElement(std::make_unique<Element>(*bullet->self->getElement()));
        }
    }
};

#endif //CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP
