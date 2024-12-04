//
// Created by francisc on 11/27/24.
//

#include <iostream>
#include "CollisionMatrix.hpp"
#include "../../Core/Utility/Utils.hpp"

CollisionMatrix::CollisionMatrix(size_t width, size_t height, size_t nrSqrWidth, size_t nrSqrHeight)
        : width(width), height(height), nrSqrWidth(nrSqrWidth), nrSqrHeight(nrSqrHeight) {
    squareWidth = width / nrSqrWidth;
    squareHeight = height / nrSqrHeight;
    grid.resize(nrSqrWidth * nrSqrHeight);
}

void CollisionMatrix::AddElement(Shape &shape, SquareState state) {
    for (int i = 0; i < nrSqrHeight; ++i)
        for (int j = 0; j < nrSqrWidth; ++j)
            if ((j + 1) * squareWidth > shape.west && (j - 1) * squareWidth < shape.east &&
                    (i + 1) * squareHeight > shape.north && (i - 1) * squareHeight < shape.south)
                grid.at(i * nrSqrWidth + j) = Square(shape, state);
}

void CollisionMatrix::CheckForCollision() {
    for (int i = 0; i < nrSqrWidth * nrSqrHeight; ++i) {
        if (grid[i].GetState() == WARZONE)
            for (int j = 0; j < grid[i].GetShapes().size() - 1; ++j) {
                for (int k = 0; k < grid[i].GetShapes().size() - 1; ++k) {
                    if (j != k) {
                        if (Utils::shapesCollide(grid[i].GetShapes()[j], grid[i].GetShapes()[k]))
                            std::cout << "HIT\n";
                    }
                }
            }
    }
    Empty();
}

void CollisionMatrix::Empty() {
    grid.clear();
    grid.resize(nrSqrWidth * nrSqrHeight);
}



