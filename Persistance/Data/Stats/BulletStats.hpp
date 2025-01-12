
#ifndef CPPGAMEDARCUOPENGL_BULLETSTATS_HPP
#define CPPGAMEDARCUOPENGL_BULLETSTATS_HPP

#include <glm/vec3.hpp>
#include "../Figure/Figure.hpp"

class BulletStats{
public:
    glm::vec3 pos;
    glm::vec3 initPos;
    float lifespan;
    float speed;
    float angle;
    float currentAngle;
    BulletStats(float lifespan, float speed, float angle):
        lifespan(lifespan), speed(speed), angle(angle) {
    };
    BulletStats(const BulletStats &b):
        lifespan(b.lifespan), speed(b.speed), angle(b.angle), pos(b.pos) {
    };
    void setPosition(glm::vec3 p) {
        pos = p;
    }
    ~BulletStats() = default;
};

#endif //CPPGAMEDARCUOPENGL_BULLETSTATS_HPP
