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
        Components/Entities/Player/Player.cpp
        Components/Pattern/BulletPattern.hpp
        Components/Pattern/ShootingPatterns/ClassicPattern.hpp
        Core/Utility/Collision/Shape.hpp
        Components/Entities/Enemies/Bacteria/Cocci/Cocci.cpp
        Components/Entities/Enemies/Bacteria/Cocci/Cocci.hpp
        Persistance/Data/Stats/BaseStats.hpp
        Persistance/Data/Geometry/Graphics.hpp
        Core/Utility/Timer.hpp
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
        Components/Entities/Enemies/Bacteria/HePylori/HePylori.cpp
        Persistance/Data/Figure/Figure.hpp Persistance/Data/Stats/BulletStats.hpp Components/Entities/Bullets/Bullet.cpp Components/Entities/Bullets/Bullet.hpp Components/Entities/Bullets/BulletTypes.hpp Components/Entities/Enemies/Bacteria/HePylori/HePylori.hpp Core/Utility/Enums/Directions.h Components/Collisions/Squares/Square.cpp Core/Utility/Timer.cpp Components/Entities/Bullets/Weapons.h Components/Pattern/ShootingPatterns/SpreadPattern.hpp Levels/Level_1/Level_1.cpp Levels/Level_1/Level_1.hpp Components/Pattern/ShootingPatterns/ZigzagPattern.hpp Components/Pattern/ShootingPatterns/DnaPattern.hpp Components/Pattern/ShootingPatterns/FirePattern.hpp Components/Pattern/ShootingPatterns/ChaoticPattern.hpp Components/Pattern/ShootingPatterns/PulsePattern.hpp)

target_include_directories(CppGameDarCuOpenGL PRIVATE
        ${CMAKE_SOURCE_DIR}/Creators
        )

target_link_libraries(CppGameDarCuOpenGL
        OpenGL::GL
        glfw
        GLEW::GLEW
)