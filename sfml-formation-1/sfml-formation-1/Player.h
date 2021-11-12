#pragma once
#include "Entity.h"
class Player :
    public Entity
{

public:
    Player(sf::Texture& _texture, sf::Texture& _texture_sword, std::string _code, int _scale, int _tile_size);
    ~Player();

    void movement_player(sf::Event& event);
    void attak(sf::Event& event);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update();
    void anim_attack();
    bool& getAttaquer() { return attaquer; };
private:
    int atk = 3;
    float atk_speed = 500;
    bool attaquer = false;
    sf::Sprite sprite_sword;
    sf::Clock timing_atk;
    bool etat_anim_atk = false;
};

