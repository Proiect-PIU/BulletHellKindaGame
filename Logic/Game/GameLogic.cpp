//
// Created by francisc on 10/10/24.
//

#include "GameLogic.hpp"
#include "../../Components/Pattern/ShootingPatterns/ClassicPattern.hpp"

GameLogic::GameLogic() {
    std::vector<float> playerShip = {
        0.0f, 0.2f, 0.0f,    0.14f, 0.55f, 0.36f,
        0.05f, 0.05f, 0.0f,   0.11f, 0.24f, 0.00f,
        0.1f, 0.0f, 0.0f,   0.11f, 0.24f, 0.00f,
        0.1f, -0.05f, 0.0f,   1.00f, 0.87f, 0.07f,
        0.0f, 0.0f, 0.0f,   0.11f, 0.24f, 0.00f,
        -0.1f, -0.05f, 0.0f,   1.00f, 0.87f, 0.07f,
        -0.1f, 0.0f, 0.0f,   0.11f, 0.24f, 0.00f,
        -0.05f, 0.05f, 0.0f,   0.11f, 0.24f, 0.00f
        };
    std::vector<unsigned int> playerShipIndices = {
        0, 1, 7,
        1, 2, 7,
        2, 6, 7,
        2, 3, 4,
        4, 5, 6
};

    std::vector<float> weaponVertices = {
        0.00f, 0.10f, 0.0f,   1.0f, 0.0f, 0.0f,
        0.025f, 0.075f, 0.0f,   1.0f, 0.33f, 0.0f,
        0.00f,  0.00f, 0.0f,   1.0f, 1.0f, 0.0f,
        -0.025f,  0.075f, 0.0f,   1.0f, 0.33f, 0.0f
};
    std::vector<unsigned int> weaponIndices = {
        0, 1, 3,
        1, 2, 3
};

    player = new Player(new Entity(new Graphics(playerShip, playerShipIndices),
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
