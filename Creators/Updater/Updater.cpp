//
// Created by francisc on 11/24/24.
//

#include "Updater.hpp"

void Updater::update(Level &level, Canvas &canvas, CollisionMatrix &matrix, float deltaTime, GLFWwindow &window) {
    for (auto& entity : level.waves[level.currentWave]->entities) {
        entity->update(canvas, deltaTime, window);
        matrix.AddElement(*entity->self->shape, SquareState::ENEMY);
        matrix.CheckForCollision();
        canvas.addElement(std::move(std::make_unique<Element>(*entity->self->element)));
    }
}
