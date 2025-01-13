//
// Created by francisc on 11/24/24.
//

#ifndef CPPGAMEDARCUOPENGL_LEVEL_HPP
#define CPPGAMEDARCUOPENGL_LEVEL_HPP


#include <vector>
#include "Wave.hpp"
#include "../Components/Entities/Bullets/Bullet.hpp"
#include "Loader/Loader.hpp"

class Level{
public:
    size_t nrWaves;
    std::vector<Wave*> waves;
    int currentWave = 0;
    Level()= default;
    explicit Level(const std::vector<Wave*> &waves): waves(waves){
        nrWaves = waves.size();
    };
    void isCleared(){
        float deltaTime = Loader::getInstance().getDeltaTime();
        if(waves[currentWave]->entities[0].first->self->stats->health <= 0) {
            currentWave = 99;
        } else {
            switch(waves[currentWave]->condition)
            {
                case Wave::KILL_ALL:
                    if(waves[currentWave]->entities.size() == 1)
                    {
                        currentWave++;
                    }
                    break;
                case Wave::SURVIVE:
                    if(waves[currentWave]->timer > 0.0f)
                    {
                        waves[currentWave]->timer -= deltaTime;
                    } else
                    {
                        delete waves[currentWave++];
                    }
                    break;
                case Wave::UNSET:
                    break;
            }
        }
    };
    ~Level(){
        for (auto& wave : waves) {
            delete wave;
        }
    };
    virtual void wave_1() = 0;
    virtual void wave_2() = 0;
    virtual void wave_3() = 0;
};


#endif //CPPGAMEDARCUOPENGL_LEVEL_HPP
