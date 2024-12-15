//
// Created by francisc on 10/15/24.
//

#ifndef CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP
#define CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP

#include <iostream>
#include "../BulletPattern.hpp"

#define bulletGraphics bullet->self.getElement()->getGraphics()
class ClassicPattern: public BulletPattern{
public:
    ClassicPattern(int nrOfBullets):
    BulletPattern(nrOfBullets){};
    void updatePattern(Bullet &bullet) override{
        Canvas *canvas = Loader::getInstance().getCanvas();
        float deltaTime = Loader::getInstance().getDeltaTime();
        CollisionMatrix *matrix = Loader::getInstance().getMatrix();


        float spacing = 0.01f;
        float totalWidth = (float)(nrOfBullets - 1) * (bullet.self->figure->getWidth() + spacing);
        float startPosX = bullet.stats->pos.x - (totalWidth / 2.0f);
        int reps = nrOfBullets;
        bullet.stats->pos.y += bullet.stats->speed * deltaTime;
        float nextPosY = bullet.stats->pos.y;

        while (reps--) {
            glm::vec3 pos(startPosX, nextPosY, 0.0f);
            std::unique_ptr<Element> e;
            Entities *bulletCopy = new Bullet(bullet);
            bulletCopy->self->figure->setPosition(pos);
            matrix->addEntity(bulletCopy, bulletCopy->self->state);
            canvas->addElement(std::move(std::make_unique<Element>(*bulletCopy->self->getElement())));
            startPosX += bullet.self->figure->getWidth() + spacing;
        }
    };
};
#undef bulletGraphics

#endif //CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP
