#pragma once
#include "Entity.h"

class Ennemy :
    public Entity
{
public:
    Ennemy(sf::Texture& _texture, std::string _code, int _scale, int _tile_size, std::vector<sf::Vector2f> _posEnnemy);
    ~Ennemy();

    void passing_ennemy(sf::Clock& clock_ennemy);

    void move_ennemy(sf::Vector2f& destination, sf::Clock& clock);

private:
    std::vector<sf::Vector2f> posEnnemy;
    int ennemy_des = 0;
    bool aller = true;
    sf::Clock pause;
    bool mouv = true;
};

