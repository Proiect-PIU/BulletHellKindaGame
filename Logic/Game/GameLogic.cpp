//
// Created by francisc on 10/10/24.
//

#include "GameLogic.hpp"
#include "../../Core/Utility/Utils.hpp"
#include "../../Components/Entities/Entities.hpp"

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
    e = new Player(triangleVertices, weaponVertices, weaponIndices);
}

static std::chrono::steady_clock::time_point lastUpdateTime = std::chrono::steady_clock::now();
float getDeltaTime() {
    auto currentTime = std::chrono::steady_clock::now();
    float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastUpdateTime).count();
    lastUpdateTime = currentTime;
    return deltaTime;
}

void GameLogic::processLogic(Canvas &canvas, GLFWwindow &window) {
    e->update(window, canvas, getDeltaTime());
    canvas.addElement(std::move(std::make_unique<Element>(*e->getElement())));
}

GameLogic::~GameLogic() {

}
