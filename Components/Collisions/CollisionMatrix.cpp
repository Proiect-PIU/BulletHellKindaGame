//
// Created by francisc on 11/27/24.
//

#include <iostream>
#include "CollisionMatrix.hpp"
#include "../../Core/Utility/Utils.hpp"
#include "../../Renderer/Canvas/Canvas.hpp"
#include "Loader/Loader.hpp"

CollisionMatrix::CollisionMatrix(float width, float height, size_t nrSqrWidth, size_t nrSqrHeight)
        : width(width), height(height), nrSqrWidth(nrSqrWidth), nrSqrHeight(nrSqrHeight) {
    squareWidth = (float)width / (float)nrSqrWidth;
    squareHeight = (float)height / (float)nrSqrHeight;
    grid.resize(nrSqrWidth * nrSqrHeight);
}
void printGrid(bool print, bool hit, float squareWidth, float squareHeight) {
    static float x = -1.0, y = -1.0, val = 1.0;
    Canvas *canvas = Loader::getInstance().getCanvas();
    std::vector<float> vertices = {
            0, 0, 0, val, 0, 0,
            1, 0, 0, val, 0, 0,
            1, 1, 0, val, 0, 0,
            0, 1, 0, val, 0, 0
    };
    std::vector<unsigned int > indices = {
            0, 1, 2,
            0, 2, 3
    };
    if (print) {
        auto e = std::make_unique<Element>(new Graphics(vertices, indices));
        if (hit) {
            e->setPosition(glm::vec3(x, y, 0));
        }
        canvas->addElement(std::move(e));
        x += squareWidth;
        val = -val;
        if (x > 1.0) {
            x = -1.0;
            y += squareHeight;
            val = -val;
        }
    }
    if (y > 1.0) {
        x = -1.0;
        y = -1.0;
        val = -1.0;
    }
}

void CollisionMatrix::addEntity(Entities &entity, SquareState state) {
    int i = 0, j = 0;
    for (float x = -1.0; x < 1.0; x += squareWidth) {
        j = 0;
        for (float y = -1.0; y < 1.0; y += squareHeight) {
            float squareLeft = x;
            float squareRight = x + squareWidth;
            float squareBottom = y;
            float squareTop = y + squareHeight;
            //std::cout << entity.self->figure->getPosition().x << '\n';
            if (entity.self->getShape()->east > squareLeft && entity.self->getShape()->west < squareRight &&
                entity.self->getShape()->north > squareBottom && entity.self->getShape()->south < squareTop) {
                grid[i * nrSqrWidth + j].AddEntity(entity, state);
                //printGrid(true, true, squareWidth, squareHeight);
            }
            ++j;
        }
        ++i;
    }
}

void CollisionMatrix::checkForCollision() {
    bool hit = false;
    for (const auto &square : grid) {
        if (square.GetState() == WARZONE) {
            // std::cout << "WAAAR\n";
            const std::vector<Entities*> &entities = square.GetEntities();
            size_t numShapes = entities.size();
            for (size_t j = 0; j < numShapes; ++j)  {
                for (size_t k = j + 1; k < numShapes; ++k) {
                    if ((entities[j]->self->state != entities[k]->self->state) &&
                            !(entities[j]->isBullet && entities[k]->isBullet) &&
                            Utils::shapesCollide(*entities[j]->self->getShape(),
                                             *entities[k]->self->getShape())) {
                        entities[j]->self->stats->health -= entities[k]->self->stats->damage;
                        entities[k]->self->stats->health -= entities[j]->self->stats->damage;
                        //std::cout << "HIT\n";
                        hit = true;
                    }
                }
            }
        }
        //printGrid(true, true, squareWidth, squareHeight);
        hit = false;
    }
    empty();
}


void CollisionMatrix::empty() {
    for (auto &square : grid) {
        square = Square();
    }
}



