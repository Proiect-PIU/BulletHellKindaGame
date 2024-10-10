#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Loop/Game.hpp"

int main() {
    Game *game = new Game();
    game->run();
    return 0;
}