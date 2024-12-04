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

void CollisionMatrix::AddElement(Shape &shape, SquareState state) {
    for (int i = 0; i < nrSqrHeight; ++i) {
        for (int j = 0; j < nrSqrWidth; ++j) {
            float squareLeft = j * squareWidth;
            float squareRight = (j + 1) * squareWidth;
            float squareBottom = i * squareHeight;
            float squareTop = (i + 1) * squareHeight;

            if (shape.east > squareLeft && shape.west < squareRight &&
                shape.north > squareBottom && shape.south < squareTop) {
                grid[i * nrSqrWidth + j].AddShape(shape, state);
            }
        }
    }
}

void CollisionMatrix::CheckForCollision() {
    for (const auto &square : grid) {
        if (square.GetState() == WARZONE) {
            const auto &shapes = square.GetShapes();
            size_t numShapes = shapes.size();
            for (size_t j = 0; j < numShapes; ++j) {
                for (size_t k = j + 1; k < numShapes; ++k) {
                    if (Utils::shapesCollide(shapes[j], shapes[k])) {
                        std::cout << "HIT\n";
                    }
                }
            }
        }
    }
    Empty();
}

void CollisionMatrix::Empty() {
    for (auto &square : grid) {
        square = Square();
    }
}



