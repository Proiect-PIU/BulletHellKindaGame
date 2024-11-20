//
// Created by francisc on 11/13/24.
//

#ifndef CPPGAMEDARCUOPENGL_COCCI_HPP
#define CPPGAMEDARCUOPENGL_COCCI_HPP


#include "../../../Entities.hpp"
#include "../../../../Pattern/EnemyPattern.hpp"
#include "../../../../Pattern/AiPatterns/CocciPattern.hpp"

class Cocci: public Entities{
    EnemyPattern *AI;
public:
    Cocci(Entity *e, Weapon *w): Entities(*e, *w){
        AI = new CocciPattern();
    };
    void update(Canvas &c, float deltaTime);
    ~Cocci(){
        if(!AI)
            delete AI;
        AI = nullptr;
    };
};


#endif //CPPGAMEDARCUOPENGL_COCCI_HPP
