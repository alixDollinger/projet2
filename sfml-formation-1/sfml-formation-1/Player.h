#pragma once
#include "Entity.h"
#include "Ennemy.h"
class Player :
    public Entity
{

public:
    Player(sf::Texture& _texture, sf::Texture& _texture_sword, std::string _code, int _scale, int _tile_size);
    ~Player();

    void movement_player(sf::Event& event);
    void movement_cheval(sf::Event& event);
    void attak(sf::Event& event);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update();
    void anim_attack();
    bool& getAttaquer() { return attaquer; };
    sf::Clock& getTimingAtk() { return timing_atk; };
    void hitEnnemy(Ennemy& ennemy);
    bool& getCheval() { return etat_cheval; };
    void setcheval(bool etat) { etat_cheval = etat; }
    void movepoussee();
private:
    int atk = 3;
    float atk_speed = 0.5;
    bool attaquer = false;
    sf::Sprite sprite_sword;
    sf::Clock timing_atk;
    bool etat_anim_atk = false;
    bool etat_cheval = false;

    sf::Vector2f acceleration = { 0.f,0.f };
    float angle_direction = 0;
    float poussee = 0;
    float masse = 252;
    int directionKey = 0;

};

