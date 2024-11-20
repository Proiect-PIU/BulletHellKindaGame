//
// Created by francisc on 10/15/24.
//

#ifndef CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP
#define CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP

#include <iostream>
#include "../Pattern.hpp"


class ClassicPattern: public Pattern{
public:
    ClassicPattern(int nrOfBullets): Pattern(nrOfBullets){};
    void updatePattern(float deltaTime, Canvas &canvas, Bullets &bullet, Element *w) override {
        float spacing = 0.1f;
        float totalWidth = (nrOfBullets - 1) * (w->getWidth() + spacing);
        float startPos = bullet.pos.x - (totalWidth / 2.0f);
        float initPos = bullet.pos.x;
        int reps = nrOfBullets;
        float posY = bullet.pos.y + bullet.speed * deltaTime;
        while (reps--) {
            bullet.pos = glm::vec3(startPos, posY, 0.0f);
            std::unique_ptr<Element> e;
            Graphics *g;
            if (w->hasIndices()) {
                g = new Graphics(w->getVertices(), w->getIndices());
                e = std::make_unique<Element>(g);
            } else {
                g = new Graphics(w->getVertices());
                e = std::make_unique<Element>(g);
            }
            if (!g) {
                delete g;
            }
            e->setPosition(bullet.pos);
            canvas.addElement(std::move(e));
            startPos += w->getWidth() + spacing;
        }
        bullet.pos.x = initPos;
    };
};

#endif //CPPGAMEDARCUOPENGL_CLASSICPATTERN_HPP
