//
// Created by francisc on 11/27/24.
//

#ifndef CPPGAMEDARCUOPENGL_COLLISIONMATRIX_HPP
#define CPPGAMEDARCUOPENGL_COLLISIONMATRIX_HPP
#include <vector>
#include "Squares/Square.hpp"


class CollisionMatrix{
    size_t width;
    size_t height;
    size_t nrSqrWidth;
    size_t nrSqrHeight;
    float squareWidth;
    float squareHeight;
    std::vector<Square> grid;
public:

    CollisionMatrix() = default;
    CollisionMatrix(size_t width, size_t height, size_t nrSqrWidth, size_t nrSqrHeight);
    void addElement(Shape &shape, SquareState state);
    void checkForCollision();
    void empty();
    ~CollisionMatrix() = default;
};


#endif //CPPGAMEDARCUOPENGL_COLLISIONMATRIX_HPP
