
#ifndef CPPGAMEDARCUOPENGL_BULLETSTATS_HPP
#define CPPGAMEDARCUOPENGL_BULLETSTATS_HPP

#include <glm/vec3.hpp>
#include "../Figure/Figure.hpp"
#include "../../../Components/Collisions/Squares/SquareState.hpp"

class BulletStats{
public:
    glm::vec3 pos;
    SquareState state;
    float lifespan;
    float speed;
    float angle;
    BulletStats(SquareState state, float lifespan, float speed, float angle):
        state(state), lifespan(lifespan), speed(speed), angle(angle) {
    };
    BulletStats(const BulletStats &b):
        state(b.state), lifespan(b.lifespan), speed(b.speed), angle(b.angle), pos(b.pos) {
    };
    void setPosition(glm::vec3 p) {
        pos = p;
    }
    ~BulletStats() = default;
};

#endif //CPPGAMEDARCUOPENGL_BULLETSTATS_HPP
