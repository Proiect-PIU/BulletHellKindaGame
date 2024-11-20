//
// Created by francisc on 10/15/24.
//

#ifndef CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP
#define CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP

#include <iostream>
#include "../BulletPattern.hpp"


class ClassicPattern: public BulletPattern{
public:
    explicit ClassicPattern(int nrOfBullets): BulletPattern(nrOfBullets){};
    void updatePattern(float deltaTime, Canvas &canvas, Bullets &bullet) override {
        float spacing = 0.01f;
        float totalWidth = (float)(nrOfBullets - 1) * (bullet.element->getWidth() + spacing);
        float startPos = bullet.pos.x - (totalWidth / 2.0f);
        float initPos = bullet.pos.x;
        int reps = nrOfBullets;
        float posY = bullet.pos.y + bullet.speed * deltaTime;
        while (reps--) {
            bullet.pos = glm::vec3(startPos, posY, 0.0f);
            std::unique_ptr<Element> e;
            Graphics *g;
            if (bullet.element->hasIndices()) {
                g = new Graphics(bullet.element->getVertices(), bullet.element->getIndices());
                e = std::make_unique<Element>(g);
            } else {
                g = new Graphics(bullet.element->getVertices());
                e = std::make_unique<Element>(g);
            }
            if (!g) {
                delete g;
            }
            e->setPosition(bullet.pos);
            canvas.addElement(std::move(e));
            startPos += bullet.element->getWidth() + spacing;
        }
        bullet.pos.x = initPos;
    };
};

#endif //CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP
