//
// Created by francisc on 10/15/24.
//

#ifndef CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP
#define CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP

#include <iostream>
#include "../BulletPattern.hpp"

#define bulletGraphics weapon.getElement()->getGraphics()
class ClassicPattern: public BulletPattern{
public:
    ClassicPattern(int nrOfBullets, glm::vec3 distanceFromEntity):
    BulletPattern(nrOfBullets, distanceFromEntity){};
    void updatePattern(Weapon &weapon, glm::vec3 entityPos) override{
        Canvas *canvas = Loader::getInstance().getCanvas();
        float deltaTime = Loader::getInstance().getDeltaTime();
        CollisionMatrix *matrix = Loader::getInstance().getMatrix();


        float spacing = 0.01f;
        float totalWidth = (float)(nrOfBullets - 1) * (bulletGraphics->getWidth() + spacing);
        float startPosX = weapon.bullets->pos.x - (totalWidth / 2.0f);
        int reps = nrOfBullets;
        weapon.bullets->pos.y += weapon.bullets->speed * deltaTime;
        float nextPosY = weapon.bullets->pos.y;

        while (reps--) {
            glm::vec3 pos(startPosX, nextPosY, 0.0f);
            std::unique_ptr<Element> e;
            auto *w = new Weapon(weapon);
            w->figure->setPosition(pos);
            matrix->addElement(*w->getShape(), w->bullets->state);
            canvas->addElement(std::move(std::make_unique<Element>(*w->getElement())));
            startPosX += bulletGraphics->getWidth() + spacing;
        }
    };
};
#undef bulletGraphics

#endif //CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP
