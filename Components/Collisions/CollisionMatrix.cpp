//
// Created by francisc on 11/27/24.
//

#include "CollisionMatrix.hpp"

CollisionMatrix::CollisionMatrix(size_t width, size_t height, size_t nrSqrWidth, size_t nrSqrHeight)
        : width(width), height(height), nrSqrWidth(nrSqrWidth), nrSqrHeight(nrSqrHeight) {
    squareWidth = width / nrSqrWidth;
    squareHeight = height / nrSqrHeight;
}

void CollisionMatrix::AddElement(Shape &shape, SquareState state) {
    for(int i = 0; i < nrSqrHeight; ++i)
        for(int j = 0; j < nrSqrWidth; ++j)
        {
            grid[i].emplace_back(shape, SquareState::ALLY);
        }
}

