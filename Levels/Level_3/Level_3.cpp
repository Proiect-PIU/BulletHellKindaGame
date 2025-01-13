
#include "Level_3.hpp"

#include "../../Components/Entities/Enemies/Bacteria/HePylori/HePylori.hpp"
#include "../../Creators/Loader/Loader.hpp"
#include "../../Components/Entities/Player/Player.hpp"

Level_3::Level_3(const std::vector<Wave *> &waves): Level(waves)
{

}

Level_3::Level_3() {
    const auto &data = Loader::getInstance().getData();

    Entities *player = new Player(*(new Entity(new Graphics(data.at("ship").first, data.at("ship").second),
                                               new BaseStats(1000, 3, 0.8, 10), SquareState::ALLY)),
                                  BulletType::TARUS_ANTI_BAMBIRI, *(new Timer(0.2f, 0)));
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

void Level_3::wave_1()
{
    const auto& data = Loader::getInstance().getData();

    for (int i = 1; i <= 10; ++i) {
        Entities *pylori = new HePylori(*(new Entity(new Graphics(data.at("he_pylori").first, data.at("he_pylori").second),
                                                 new BaseStats(500, 3, 0.5, 1), SquareState::ENEMY)),
                                    BulletType::HEPYLORI_BASIC,*(new Timer(1.0f, 0)));
        pylori->self->figure->setPosition(glm::vec3(-0.55 + i * 0.1, 0.4, 0.0));
        pylori->angle = 90.0;
        pylori->nrOfBullets = 3;
        waves[currentWave]->entities.emplace_back(pylori, std::vector<Bullet*>{});
    }
}

void Level_3::wave_2()
{
    const auto& data = Loader::getInstance().getData();

    for (int i = 1; i <= 10; ++i) {
        Entities *pylori = new HePylori(*(new Entity(new Graphics(data.at("hec_pylori").first, data.at("hec_pylori").second),
                                                 new BaseStats(1000, 3, 0.5, 1), SquareState::ENEMY)),
                                    BulletType::HEPYLORI_STRONG,*(new Timer(1.0f, 0)));
        pylori->self->figure->setPosition(glm::vec3(-0.55 + i * 0.10, 0.3, 0.0));
        pylori->angle = 90.0;
        pylori->nrOfBullets = 7;
        waves[currentWave]->entities.emplace_back(pylori, std::vector<Bullet*>{});
    }
}

void Level_3::wave_3()
{
    const auto& data = Loader::getInstance().getData();

    for (int i = 1; i <= 1; ++i) {
        Entities *pylori = new HePylori(*(new Entity(new Graphics(data.at("boss_2_tubbo").first, data.at("boss_2_tubbo").second),
                                                 new BaseStats(20000, 3, 0.5, 1), SquareState::ENEMY)),
                                    BulletType::FIRE,*(new Timer(1.0f, 0)));
        pylori->self->figure->setPosition(glm::vec3(-0.55 + i * 0.20, 0.9, 0.0));
        pylori->self->figure->setScale(glm::vec3(10, 10, 0));
        pylori->angle = 90.0;
        pylori->nrOfBullets = 15;
        waves[currentWave]->entities.emplace_back(pylori, std::vector<Bullet*>{});
    }
}
