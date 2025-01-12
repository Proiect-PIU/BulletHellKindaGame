//
// Created by francisc on 11/24/24.
//

#include "Updater.hpp"
#include "../Loader/Loader.hpp"
#include "../../Components/Pattern/ShootingPatterns/ClassicPattern.hpp"
#include "../../Components/Entities/Bullets/Weapons.h"

void createBullets(Entities* entity, std::vector<Bullet*>& mag) {
    float angleStep = entity->angle / (entity->nrOfBullets - 1);
    float startAngle = -entity->angle / 2.0f;
    float spacing = 0.04f;
    float totalWidth = (entity->nrOfBullets - 1) * spacing;
    float startPosX = entity->self->figure->getPosition().x - (totalWidth / 2.0f);

    for (int i = 0; i < entity->nrOfBullets; ++i) {
        auto bullet = Weapons::getBullet(entity->getType(), entity->self->state);

        if (entity->self->state == SquareState::ENEMY) {
            bullet->stats->speed *= -1;
            //bullet->self->figure->setRotation(90.0, glm::vec3(0.0, 0.0, 1.0));
            bullet->stats->currentAngle = glm::radians(-(startAngle + i * angleStep));
        } else {
            bullet->stats->currentAngle = glm::radians(startAngle + i * angleStep);
        }

        glm::vec3 pos(startPosX + i * spacing, entity->self->figure->getPosition().y, 0.0f);
        bullet->stats->setPosition(pos);
        bullet->stats->initPos = pos;
        bullet->stats->angle = entity->angle;
        mag.emplace_back(bullet);
    }
}

void Updater::update(Level &level) {
    Canvas *canvas = Loader::getInstance().getCanvas();
    CollisionMatrix *matrix = Loader::getInstance().getMatrix();
    auto& entities = level.waves[level.currentWave]->entities;
    for (auto ent = entities.begin(); ent < entities.end();) {
        auto entity = ent->first;
        auto& mag = ent->second;
        entity->update();
        if (entity->self->stats->health <= 0) {
            ent = entities.erase(ent);
            delete entity;
            continue;
        }
        if (entity->hasShoot()) {
            createBullets(entity, mag);
        }
        if (!mag.empty()) {
            BulletPattern* weapon = Weapons::getWeapon(entity->getType(), entity->nrOfBullets);
            for (auto it = mag.begin(); it != mag.end();) {
                auto bullet = *it;
                bullet->update();
                if (!bullet->isDead()) {
                    ++it;
                } else {
                    delete bullet;
                    it = mag.erase(it);
                }
            }
            weapon->updatePattern(mag);
        }
        matrix->addEntity(*entity, entity->self->state);
        canvas->addElement(std::move(std::make_unique<Element>(*entity->self->getElement())));

        ++ent;
    }
    if (!entities.empty()) {
        matrix->checkForCollision();
    }
}
