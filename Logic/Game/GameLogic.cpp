//
// Created by francisc on 10/10/24.
//

#include "GameLogic.hpp"
#include "../../Components/Pattern/ShootingPatterns/ClassicPattern.hpp"
#include "../../Levels/TestLevels/TestLevel.hpp"

GameLogic::GameLogic() {
    testLevel = new TestLevel();
    worker = new Updater();
    matrix = new CollisionMatrix(1, 1, 16, 16);
    std::vector<float> playerShip = {
            0.0f, 0.2f, 0.0f,    0.14f, 0.55f, 0.36f,   //0
            0.05f, 0.05f, 0.0f,   0.11f, 0.24f, 0.00f,  //1
            0.1f, 0.0f, 0.0f,   0.11f, 0.24f, 0.00f,    //2
            0.1f, -0.05f, 0.0f,   1.00f, 0.87f, 0.07f,  //3
            0.0f, 0.0f, 0.0f,   0.11f, 0.24f, 0.00f,    //4
            -0.1f, -0.05f, 0.0f,   1.00f, 0.87f, 0.07f, //5
            -0.1f, 0.0f, 0.0f,   0.11f, 0.24f, 0.00f,   //6
            -0.05f, 0.05f, 0.0f,   0.11f, 0.24f, 0.00f, //7

            0.0f, 0.1f, 0.0f,       0.38f, 0.74f, 0.88f,//8
            0.01f, 0.08f, 0.0f,     0.08f, 0.1f, 0.35f, //9
            0.02f, 0.06f, 0.0f,     0.08f, 0.1f, 0.35f, //10
            0.0f, 0.05f, 0.0f,      0.08f, 0.1f, 0.35f, //11
            -0.02f, 0.06f, 0.0f,     0.08f, 0.1f, 0.35f, //12
            -0.01f, 0.08f, 0.0f,     0.08f, 0.1f, 0.35f,//13
    };
    std::vector<unsigned int> playerShipIndices = {
            0, 1, 7,
            1, 2, 7,
            2, 6, 7,
            2, 3, 4,
            4, 5, 6,

            8, 9, 13,
            9, 10, 13,
            10, 12, 13,
            10, 11, 12
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
                              new BaseStats(10, 3, 1)),
                   new Weapon(new Graphics(weaponVertices, weaponIndices),
                              new WeaponStats(new ClassicPattern(3), 0.3)));

    player->self->element->setPosition(glm::vec3(0.0, -0.8, 0.0));

}

static std::chrono::steady_clock::time_point lastUpdateTime = std::chrono::steady_clock::now();
float getDeltaTime() {
    auto currentTime = std::chrono::steady_clock::now();
    float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastUpdateTime).count();
    lastUpdateTime = currentTime;
    return deltaTime;
}

void GameLogic::processLogic(Canvas &canvas, GLFWwindow &window) {
    float delta = getDeltaTime();
    player->update(canvas, delta, window);
    matrix->AddElement(*player->self->shape, SquareState::ALLY);
    worker->update(*testLevel, canvas, *matrix, delta, window);
    canvas.addElement(std::move(std::make_unique<Element>(*player->self->element)));
}

GameLogic::~GameLogic() {
    if (!player) {
        delete player;
    }
    player = nullptr;
    if (!testLevel) {
        delete testLevel;
    }
    testLevel = nullptr;
}
