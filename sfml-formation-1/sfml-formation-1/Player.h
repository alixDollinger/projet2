#pragma once
#include "Entity.h"
class Player :
    public Entity
{

public:
    Player(sf::Texture& _texture, std::string _code, int _scale, int _tile_size);
    ~Player();

    void movement_player(sf::Event& event);

private:

};

