
#ifndef CPPGAMEDARCUOPENGL_BLOUT_HPP
#define CPPGAMEDARCUOPENGL_BLOUT_HPP


#include "../../../Entities.hpp"
#include "../../../../Pattern/EnemyPattern.hpp"
#include "../../../../Pattern/AiPatterns/BloutPattern.hpp"

class Blout: public Entities{
    EnemyPattern *AI;
public:
    Blout(Entity &e, BulletType bt, Timer &t): Entities(e, bt, t){
        AI = new BloutPattern();
    };
    void update()override;
    ~Blout() override {
        if(!AI)
            delete AI;
        AI = nullptr;
    };
};


#endif //CPPGAMEDARCUOPENGL_BLOUT_HPP
