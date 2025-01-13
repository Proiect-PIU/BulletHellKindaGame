
#include "Level_2.hpp"
#include "../../Components/Entities/Player/Player.hpp"
#include "../Components//Entities/Enemies/Bacteria/Bambir/Bambir.hpp"

Level_2::Level_2(const std::vector<Wave *> &waves): Level(waves) {

}

Level_2::Level_2() {
    const auto &data = Loader::getInstance().getData();

    Entities *player = new Player(*(new Entity(new Graphics(data.at("ship").first, data.at("ship").second),
                                               new BaseStats(1000, 3, 0.8, 10), SquareState::ALLY)),
                                  BulletType::FIRE, *(new Timer(0.1f, 0)));
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

void Level_2::wave_1()
{
    const auto& data = Loader::getInstance().getData();

    for (int i = 1; i <= 10; ++i) {
        Entities *bambir = new Bambir(*(new Entity(new Graphics(data.at("bambir").first, data.at("bambir").second),
                                                 new BaseStats(200, 3, 0.1, 1), SquareState::ENEMY)),
                                    BulletType::BAMBIR_BASIC,*(new Timer(1.0f, 0)));
        bambir->self->figure->setPosition(glm::vec3(-0.9 + i * 0.20, 0.9, 0.0));
        bambir->angle = 90.0;
        bambir->nrOfBullets = 2;
        waves[currentWave]->entities.emplace_back(bambir, std::vector<Bullet*>{});
    }
}

void Level_2::wave_2()
{
    const auto& data = Loader::getInstance().getData();

    for (int i = 1; i <= 10; ++i) {
        Entities *bambir = new Bambir(*(new Entity(new Graphics(data.at("bambir").first, data.at("bambir").second),
                                                   new BaseStats(300, 3, 0.1, 1), SquareState::ENEMY)),
                                      BulletType::BAMBIR_STRONG,*(new Timer(1.0f, 0)));
        bambir->self->figure->setPosition(glm::vec3(-0.9 + i * 0.20, 0.9, 0.0));
        bambir->angle = 90.0;
        bambir->nrOfBullets = 3;
        waves[currentWave]->entities.emplace_back(bambir, std::vector<Bullet*>{});
    }
}

void Level_2::wave_3()
{
    const auto& data = Loader::getInstance().getData();

    Entities *aloUla = new Bambir(*(new Entity(new Graphics(data.at("boss_3_aloo_ula").first, data.at("boss_3_aloo_ula").second),
                                                   new BaseStats(5000, 3, 1.0, 1), SquareState::ENEMY)),
                                      BulletType::BAMBIR_STRONG,*(new Timer(1.0f, 0)));
    aloUla->self->figure->setScale(glm::vec3(4.0, 4.0, 0.0));
    aloUla->self->figure->setPosition(glm::vec3(0.0, 0.5, 0.0));
    aloUla->angle = 90.0;
    aloUla->nrOfBullets = 14;
    waves[currentWave]->entities.emplace_back(aloUla, std::vector<Bullet*>{});
}
