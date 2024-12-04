cmake_minimum_required(VERSION 3.28)
project(CppGameDarCuOpenGL)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

find_package(glfw3 REQUIRED)

find_package(GLEW REQUIRED)

add_executable(CppGameDarCuOpenGL Core/main.cpp
        Core/Loop/Game.cpp
        Core/Loop/Game.hpp
        Core/Context/GameContext.cpp
        Core/Context/GameContext.hpp
        Renderer/Canvas/Element/Element.cpp
        Renderer/Canvas/Element/Element.hpp
        Renderer/Canvas/Canvas.cpp
        Renderer/Canvas/Canvas.hpp
        Renderer/Renderer.cpp
        Renderer/Renderer.hpp
        Core/Utility/Utils.cpp
        Core/Utility/Utils.hpp
        Logic/Game/GameLogic.cpp
        Logic/Game/GameLogic.hpp
        Logic/Logic.hpp
        Components/Entities/Entities.cpp
        Components/Entities/Entities.hpp
        Components/Entities/Player/Player.cpp
        Components/Entities/Player/Player.hpp
        Components/Entities/Bullets/Bullets.cpp
        Components/Entities/Bullets/Bullets.hpp
        Components/Entities/Player/Player.cpp
        Components/Pattern/BulletPattern.hpp
        Components/Pattern/ShootingPatterns/ClassicPattern.hpp
        Core/Utility/Collision/Shape.hpp
        Components/Entities/Enemies/Bacteria/Cocci/Cocci.cpp
        Components/Entities/Enemies/Bacteria/Cocci/Cocci.hpp
        Persistance/Data/Stats/BaseStats.hpp
        Persistance/Data/Geometry/Graphics.hpp
        Persistance/Data/Stats/WeaponStats.hpp
        Persistance/Data/Objects/Weapon.hpp
        Persistance/Data/Objects/Entity.hpp
        Components/Pattern/EnemyPattern.hpp
        Components/Pattern/AiPatterns/CocciPattern.cpp
        Components/Pattern/AiPatterns/CocciPattern.hpp
        Creators/Updater/Updater.cpp
        Creators/Updater/Updater.hpp
        Creators/Loader/Loader.cpp
        Creators/Loader/Loader.hpp
        Levels/Level.hpp
        Levels/Wave.hpp
        Levels/TestLevels/TestLevel.cpp
        Levels/TestLevels/TestLevel.hpp
        Components/Collisions/CollisionMatrix.cpp
        Components/Collisions/CollisionMatrix.hpp
        Components/Collisions/Squares/Square.hpp
        Components/Collisions/Squares/SquareState.hpp
)

target_link_libraries(CppGameDarCuOpenGL
        OpenGL::GL
        glfw
        GLEW::GLEW
)