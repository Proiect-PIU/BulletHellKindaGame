
#include "Level_1.hpp"
#include "../../Creators/Loader/Loader.hpp"
#include "../../Components/Entities/Player/Player.hpp"
#include "../../Components/Entities/Enemies/Bacteria/Cocci/Cocci.hpp"

Level_1::Level_1(const std::vector<Wave*> &waves) : Level(waves) {

}

Level_1::Level_1() {
    //Loader& loader = Loader::getInstance();
    const auto& data = Loader::getInstance().getData();

    // shipW speed = 5.0
    // cocciW speed = 2.0


    std::vector<std::pair<Entities*, std::vector<Bullet*>>> entities;
    Entities *player = new Player(*(new Entity(new Graphics(data.at("ship").first, data.at("ship").second),
                                               new BaseStats(1000, 3, 0.8, 10), SquareState::ALLY)),
                                  BulletType::CHAOTIC,*(new Timer(0.2f, 0)));
    player->self->figure->setPosition(glm::vec3(0.0, -0.8, 0.0));
    float scale = 0.5;
    player->self->figure->setScale(glm::vec3(scale, scale, 0));

    player->nrOfBullets = 4;
    player->angle = 20.0;
    entities.emplace_back(player, std::vector<Bullet*>{});

    for (int i = 1; i <= 14; ++i) {
        Entities *cocci = new Cocci(*(new Entity(new Graphics(data.at("cocci").first, data.at("cocci").second),
                                                 new BaseStats(100, 3, 0.5, 1), SquareState::ENEMY)),
                                    BulletType::COCCI_STRONG,*(new Timer(1.0f, 0)));
        cocci->self->figure->setPosition(glm::vec3(-0.9 + i * 0.20, 0.9, 0.0));
        cocci->angle = 90.0;
        cocci->nrOfBullets = 10;
        entities.emplace_back(cocci, std::vector<Bullet*>{});
    }

    waves.push_back(new Wave(entities, Wave::Condition::KILL_ALL));
}