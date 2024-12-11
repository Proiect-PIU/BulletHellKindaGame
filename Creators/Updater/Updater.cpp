//
// Created by francisc on 11/24/24.
//

#include "Updater.hpp"
#include "../Loader/Loader.hpp"

void Updater::update(Level &level) {
    Canvas *canvas = Loader::getInstance().getCanvas();
    CollisionMatrix *matrix = Loader::getInstance().getMatrix();
    for (auto& entity : level.waves[level.currentWave]->entities) {
        entity->update();

        matrix->addElement(*entity->self->getShape(), entity->self->state);
        canvas->addElement(std::move(std::make_unique<Element>(*entity->self->getElement())));
    }
    matrix->checkForCollision();
}
