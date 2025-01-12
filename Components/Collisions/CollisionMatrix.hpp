//
// Created by francisc on 11/27/24.
//

#ifndef CPPGAMEDARCUOPENGL_COLLISIONMATRIX_HPP
#define CPPGAMEDARCUOPENGL_COLLISIONMATRIX_HPP
#include <vector>
#include "Squares/Square.hpp"



class CollisionMatrix{
    float width;
    float height;
    size_t nrSqrWidth;
    size_t nrSqrHeight;
    float squareWidth;
    float squareHeight;
    std::vector<Square> grid;
public:

    CollisionMatrix() = default;
    CollisionMatrix(float width, float height, size_t nrSqrWidth, size_t nrSqrHeight);
    void addEntity(Entities &entity, SquareState state);
    void checkForCollision();
    void empty();
    ~CollisionMatrix() = default;
};


#endif //CPPGAMEDARCUOPENGL_COLLISIONMATRIX_HPP
