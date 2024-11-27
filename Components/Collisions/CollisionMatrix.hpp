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
    size_t squareWidth;
    size_t squareHeight;
    std::vector<std::vector<Square>> grid;
public:
    CollisionMatrix(size_t width, size_t height, size_t nrSqrWidth, size_t nrSqrHeight);
    void AddElement(Shape &shape, SquareState state);
    ~CollisionMatrix();
};


#endif //CPPGAMEDARCUOPENGL_COLLISIONMATRIX_HPP
