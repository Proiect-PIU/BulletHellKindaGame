
#ifndef CPPGAMEDARCUOPENGL_CHAOTICPATTERN_HPP
#define CPPGAMEDARCUOPENGL_CHAOTICPATTERN_HPP

#include <iostream>
#include "Loader/Loader.hpp"
#include "../BulletPattern.hpp"
#include "../../Entities/Bullets/Bullet.hpp"
#include "../../../Core/Utility/Utils.hpp"

class ChaoticPattern : public BulletPattern {
public:
    ChaoticPattern(int nrOfBullets) : BulletPattern(nrOfBullets) {}

    void updatePattern(std::vector<Bullet*>& bullets) override {
        Canvas* canvas = Loader::getInstance().getCanvas();
        CollisionMatrix* matrix = Loader::getInstance().getMatrix();
        float deltaTime = Loader::getInstance().getDeltaTime();

        float amplitude = 0.1f;
        float frequency = 5.0f;

        // Store randomized speeds for this iteration
        std::vector<float> randomizedSpeeds(bullets.size(), 0.0f);

        // Precompute the randomized speeds
        for (size_t i = 0; i < bullets.size(); ++i) {
            if (randomizedSpeeds[i] == 0.0f) {
                randomizedSpeeds[i] = bullets[i]->stats->speed + Utils::randRange(-1.5f, 1.5f);
            }
        }

        // Update bullets
        for (size_t i = 0; i < bullets.size(); ++i) {
            Bullet* bullet = bullets[i];

            // Initialize bullet properties on the first update
            if (bullet->stats->currentAngle == 0.0f) {
                bullet->stats->currentAngle = (i % 4); // Assign motion type: 0=sin, 1=cos, 2=-sin, 3=-cos
            }

            // Use the precomputed randomized speed for this iteration
            float bulletSpeed = randomizedSpeeds[i];

            // Update vertical position
            bullet->stats->pos.y += bulletSpeed * deltaTime;

            // Calculate horizontal offset based on the motion type
            float offsetX = 0.0f;
            switch (i % 4) {
                case 0: offsetX = amplitude * glm::sin(frequency * bullet->stats->pos.y); break;   // sin
                case 1: offsetX = amplitude * glm::cos(frequency * bullet->stats->pos.y); break;   // cos
                case 2: offsetX = -amplitude * glm::sin(frequency * bullet->stats->pos.y); break;  // -sin
                case 3: offsetX = -amplitude * glm::cos(frequency * bullet->stats->pos.y); break;  // -cos
            }

            // Update horizontal position
            bullet->stats->pos.x = bullet->stats->initPos.x + offsetX;

            // Update the bullet's figure and render it
            bullet->self->figure->setPosition(bullet->stats->pos);
            matrix->addEntity(*bullet, bullet->self->state);
            canvas->addElement(std::make_unique<Element>(*bullet->self->getElement()));
        }
    }
};

#endif //CPPGAMEDARCUOPENGL_CHAOTICPATTERN_HPP
