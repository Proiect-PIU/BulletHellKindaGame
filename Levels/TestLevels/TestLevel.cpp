//
// Created by francisc on 11/24/24.
//

#include "TestLevel.hpp"
#include "../../Creators/Loader/Loader.hpp"
#include "../../Components/Entities/Player/Player.hpp"
#include "../../Components/Entities/Enemies/Bacteria/Cocci/Cocci.hpp"


TestLevel::TestLevel(const std::vector<Wave*> &waves) : Level(waves) {

}

TestLevel::TestLevel() {
    //Loader& loader = Loader::getInstance();
    const auto& data = Loader::getInstance().getData();

    // shipW speed = 5.0
    // cocciW speed = 2.0


    std::vector<std::pair<Entities*, std::vector<Bullet*>>> entities;
    Entities *player = new Player(*(new Entity(new Graphics(data.at("ship").first, data.at("ship").second),
                                new BaseStats(5000, 3, 0.8, 5), SquareState::ALLY)),BulletType::SPREAD,
                                *(new Timer(0.2f, 0)));

    Entities *cocci = new Cocci(*(new Entity(new Graphics(data.at("cocci").first, data.at("cocci").second),
                                            new BaseStats(5000, 3, 0.5, 5), SquareState::ENEMY)),BulletType::COCCI_STRONG,
                               *(new Timer(0.3f, 1)));

    player->self->figure->setPosition(glm::vec3(0.0, -0.8, 0.0));
    float scale = 0.5;
    player->self->figure->setScale(glm::vec3(scale, scale, 0));
    cocci->self->figure->setScale(glm::vec3(1.0, 1.0, 0));
    cocci->self->figure->setPosition(glm::vec3(-0.9, 0.8, 0.0));
    cocci->nrOfBullets = 3;
    cocci->angle = 50.0;
    player->nrOfBullets = 10;
    player->angle = 20.0;

    entities.emplace_back(player, std::vector<Bullet*>{});
    entities.emplace_back(cocci, std::vector<Bullet*>{});
    waves.push_back(new Wave(entities, Wave::Condition::KILL_ALL));
}
