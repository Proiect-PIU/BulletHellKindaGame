//
// Created by francisc on 10/10/24.
//

#include "GameLogic.hpp"

GameLogic::GameLogic() {
    std::vector<float> triangleVertices = {
            -0.04f, -0.01f, 0.0f,  1.0f, 0.0f, 0.0f,
            0.0f, 0.1f, 0.0f,  0.0f, 1.0f, 0.0f,
            0.04f,  -0.01f, 0.0f,  0.0f, 0.0f, 1.0f
    };
    std::vector<float> weaponVertices = {
            -0.01f, -0.05f, 0.0f,   1.0f, 1.0f, 1.0f,
            0.01f, -0.05f, 0.0f,   1.0f, 0.0f, 1.0f,
            0.01f,  0.05f, 0.0f,   0.0f, 1.0f, 1.0f,
            -0.01f,  0.05f, 0.0f,   1.0f, 1.0f, 0.0f
    };
    std::vector<unsigned int> weaponIndices = {
            0, 1, 2,
            2, 3, 0
    };

    player = new Player(new Entity(new Graphics(triangleVertices),
                              new BaseStats(10, 3)),
                   new Weapon(new Graphics(weaponVertices, weaponIndices),
                              new WeaponStats(new ClassicPattern(3), 0.3)));

}

static std::chrono::steady_clock::time_point lastUpdateTime = std::chrono::steady_clock::now();
float getDeltaTime() {
    auto currentTime = std::chrono::steady_clock::now();
    float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastUpdateTime).count();
    lastUpdateTime = currentTime;
    return deltaTime;
}

void GameLogic::processLogic(Canvas &canvas, GLFWwindow &window) {
    player->update(window, canvas, getDeltaTime());
    canvas.addElement(std::move(std::make_unique<Element>(*player->self->element)));
}

GameLogic::~GameLogic() {
    if (!player) {
        delete player;
    }
}
