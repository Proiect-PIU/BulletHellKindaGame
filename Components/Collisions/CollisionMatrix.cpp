//
// Created by francisc on 11/27/24.
//

#include <iostream>
#include "CollisionMatrix.hpp"
#include "../../Core/Utility/Utils.hpp"

CollisionMatrix::CollisionMatrix(size_t width, size_t height, size_t nrSqrWidth, size_t nrSqrHeight)
        : width(width), height(height), nrSqrWidth(nrSqrWidth), nrSqrHeight(nrSqrHeight) {
    squareWidth = (float)width / (float)nrSqrWidth;
    squareHeight = (float)height / (float)nrSqrHeight;
    grid.resize(nrSqrWidth * nrSqrHeight);
}

void CollisionMatrix::addEntity(Entities &entity, SquareState state) {
    for (int i = 0; i < nrSqrHeight; ++i) {
        for (int j = 0; j < nrSqrWidth; ++j) {
            float squareLeft = j * squareWidth;
            float squareRight = (j + 1) * squareWidth;
            float squareBottom = i * squareHeight;
            float squareTop = (i + 1) * squareHeight;

            if (entity.self->getShape()->east > squareLeft && entity.self->getShape()->west < squareRight &&
            entity.self->getShape()->north > squareBottom && entity.self->getShape()->south < squareTop) {
                grid[i * nrSqrWidth + j].AddEntity(entity, state);
            }
        }
    }
}

void CollisionMatrix::checkForCollision() {

    for (const auto &square : grid) {
        if (square.GetState() == WARZONE) {
            const std::vector<Entities*> &entities = square.GetEntities();
            size_t numShapes = entities.size();
            for (size_t j = 0; j < numShapes; ++j) {
                for (size_t k = j + 1; k < numShapes; ++k) {
                    if (Utils::shapesCollide(*entities[j]->self->getShape(),
                                             *entities[k]->self->getShape())) {
                        std::cout << "HIT\n";
                    }
                }
            }
        }
    }
    empty();
}

void CollisionMatrix::empty() {
    for (auto &square : grid) {
        square = Square();
    }
}



