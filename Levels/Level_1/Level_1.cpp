
#include "Level_1.hpp"
#include "../../Creators/Loader/Loader.hpp"
#include "../../Components/Entities/Player/Player.hpp"
#include "../../Components/Entities/Enemies/Bacteria/Cocci/Cocci.hpp"

Level_1::Level_1(const std::vector<Wave*> &waves) : Level(waves) {

}

Level_1::Level_1()
{
    const auto &data = Loader::getInstance().getData();

    Entities *player = new Player(*(new Entity(new Graphics(data.at("ship").first, data.at("ship").second),
                                               new BaseStats(1000, 3, 0.8, 10), SquareState::ALLY)),
                                  BulletType::CHAOTIC, *(new Timer(0.2f, 0)));
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

void Level_1::wave_1() {
    const auto& data = Loader::getInstance().getData();

    for (int i = 1; i <= 14; ++i) {
        Entities *cocci = new Cocci(*(new Entity(new Graphics(data.at("bambir").first, data.at("bambir").second),
                                                 new BaseStats(100, 3, 0.5, 1), SquareState::ENEMY)),
                                    BulletType::COCCI_STRONG,*(new Timer(1.0f, 0)));
        cocci->self->figure->setPosition(glm::vec3(-0.9 + i * 0.20, 0.9, 0.0));
        cocci->angle = 90.0;
        cocci->nrOfBullets = 10;
        waves[currentWave]->entities.emplace_back(cocci, std::vector<Bullet*>{});
    }
}

void Level_1::wave_2() {
    const auto& data = Loader::getInstance().getData();

    for (int i = 1; i <= 14; ++i) {
        Entities *cocci = new Cocci(*(new Entity(new Graphics(data.at("bambir").first, data.at("bambir").second),
                                                 new BaseStats(100, 3, 0.5, 1), SquareState::ENEMY)),
                                    BulletType::COCCI_STRONG,*(new Timer(1.0f, 0)));
        cocci->self->figure->setPosition(glm::vec3(-0.9 + i * 0.20, 0.9, 0.0));
        cocci->angle = 90.0;
        cocci->nrOfBullets = 10;
        waves[currentWave]->entities.emplace_back(cocci, std::vector<Bullet*>{});
    }
}

void Level_1::wave_3()
{
    const auto& data = Loader::getInstance().getData();

    for (int i = 1; i <= 14; ++i) {
        Entities *cocci = new Cocci(*(new Entity(new Graphics(data.at("bambir").first, data.at("bambir").second),
                                                 new BaseStats(100, 3, 0.5, 1), SquareState::ENEMY)),
                                    BulletType::COCCI_STRONG,*(new Timer(1.0f, 0)));
        cocci->self->figure->setPosition(glm::vec3(-0.9 + i * 0.20, 0.9, 0.0));
        cocci->angle = 90.0;
        cocci->nrOfBullets = 10;
        waves[currentWave]->entities.emplace_back(cocci, std::vector<Bullet*>{});
    }
}
