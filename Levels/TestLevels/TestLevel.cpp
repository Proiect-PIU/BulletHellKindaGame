//
// Created by francisc on 11/24/24.
//

#include "TestLevel.hpp"
#include "../../Components/Entities/Enemies/Bacteria/Cocci/Cocci.hpp"
#include "../../Components/Pattern/ShootingPatterns/ClassicPattern.hpp"
#include "../../Components/Entities/Player/Player.hpp"
#include "../../Creators/Loader/Loader.hpp"


TestLevel::TestLevel(const std::vector<Wave*> &waves) : Level(waves) {

}

TestLevel::TestLevel() {
    //Loader& loader = Loader::getInstance();
    const auto& data = Loader::getInstance().getData();

    // shipW speed = 5.0
    // cocciW speed = 2.0


    std::vector<Entities*> entities;
    Entities *player = new Player(new Entity(new Graphics(data.at("hec_pylori").first, data.at("hec_pylori").second),
                                   new BaseStats(10, 3, 0.8), SquareState::ALLY),
                        new Weapon(new Graphics(data.at("weapon_cocci").first, data.at("weapon_cocci").second),
                                   new WeaponStats(new ClassicPattern(3), 0.3f, 1)));
    Entities *cocci = new Cocci(new Entity(new Graphics(data.at("cocci_2").first, data.at("cocci_2").second),
                                 new BaseStats(10, 3, 0.5), SquareState::ENEMY),
                      new Weapon(new Graphics(data.at("weapon_cocci").first, data.at("weapon_cocci").second),
                                 new WeaponStats(new ClassicPattern(3), 1, 1)));
    player->self->element->setPosition(glm::vec3(0.0, -0.8, 0.0));
    float scale = 0.8;
    player->self->element->setScale(glm::vec3(scale, scale, 0));
    player->self->shape->update(player->self->element->getModelMatrix());
    player->weapon->element->setScale(glm::vec3(scale, scale, 0));
    cocci->self->element->setPosition(glm::vec3(-0.9, 0.8, 0.0));

    entities.push_back(player);
    entities.push_back(cocci);
    waves.push_back(new Wave(entities, Wave::Condition::KILL_ALL));
}
