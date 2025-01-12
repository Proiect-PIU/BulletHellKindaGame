
#include "Level_4.hpp"
#include "../../Components/Entities/Player/Player.hpp"
#include "../../Components/Entities/Enemies/Bacteria/Blout/Blout.hpp"

Level_4::Level_4(const std::vector<Wave *> &waves): Level(waves) {

}

Level_4::Level_4() {
    const auto &data = Loader::getInstance().getData();

    Entities *player = new Player(*(new Entity(new Graphics(data.at("ship").first, data.at("ship").second),
                                               new BaseStats(1000, 3, 0.8, 10), SquareState::ALLY)),
                                  BulletType::DNA, *(new Timer(0.1f, 0)));
    player->self->figure->setPosition(glm::vec3(0.0, -0.8, 0.0));
    float scale = 0.5;
    player->self->figure->setScale(glm::vec3(scale, scale, 0));

    player->nrOfBullets = 4;
    player->angle = 20.0;
    Wave *wave = new Wave({{player, {}}}, Wave::Condition::KILL_ALL);
    waves.push_back(wave);
    waves.push_back(wave);
    waves.push_back(wave);
}

void Level_4::wave_1() {
    const auto& data = Loader::getInstance().getData();

    for (int i = 1; i <= 16; ++i) {
        Entities *blout = new Blout(*(new Entity(new Graphics(data.at("blout").first, data.at("blout").second),
                                                   new BaseStats(400, 3, 0.1, 1), SquareState::ENEMY)),
                                      BulletType::BLOUT,*(new Timer(1.0f, 0)));
        blout->self->figure->setPosition(glm::vec3(-0.9 + i * 0.3, 0.9, 0.0));
        blout->self->figure->setScale(glm::vec3(2.0, 2.0, 0.0));
        blout->angle = 90.0;
        blout->nrOfBullets = 4;
        waves[currentWave]->entities.emplace_back(blout, std::vector<Bullet*>{});
    }
}

void Level_4::wave_2(){
    const auto& data = Loader::getInstance().getData();

    for (int i = 1; i <= 20; ++i) {
        Entities *blout = new Blout(*(new Entity(new Graphics(data.at("blout").first, data.at("blout").second),
                                                 new BaseStats(400, 3, 0.1, 1), SquareState::ENEMY)),
                                    BulletType::BLOUT,*(new Timer(1.0f, 0)));
        blout->self->figure->setPosition(glm::vec3(-0.9 + i * 0.2, 0.9, 0.0));
        blout->self->figure->setScale(glm::vec3(2.0, 2.0, 0.0));
        blout->angle = 90.0;
        blout->nrOfBullets = 6;
        waves[currentWave]->entities.emplace_back(blout, std::vector<Bullet*>{});
    }
}

void Level_4::wave_3(){
    const auto& data = Loader::getInstance().getData();
    Entities *deBoss = new Blout(*(new Entity(new Graphics(data.at("boss_4_de_boss").first, data.at("boss_4_de_boss").second),
                                             new BaseStats(12000, 3, 0.1, 1), SquareState::ENEMY)),
                                BulletType::BLOUT,*(new Timer(0.2f, 0)));
    deBoss->self->figure->setPosition(glm::vec3(0.0, 0.9, 0.0));
    deBoss->self->figure->setScale(glm::vec3(9.0, 9.0, 0.0));
    deBoss->angle = 90.0;
    deBoss->nrOfBullets = 20;
    waves[currentWave]->entities.emplace_back(deBoss, std::vector<Bullet*>{});
}
