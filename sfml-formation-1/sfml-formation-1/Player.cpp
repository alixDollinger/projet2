#include "Player.h"
#include <iostream>


Player::Player(sf::Texture& _texture_chara, sf::Texture& _texture_sword, std::string _code, int _scale, int _tile_size) : Entity(_texture_chara, _code, _scale, _tile_size)
{
    sprite_sword.setTexture(_texture_sword);
    sprite_sword.setScale(0.75, 0.75);
    sprite_sword.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(104, 32)));
    sprite_sword.setOrigin(sf::Vector2f(0, 16));
    sprite_sword.setPosition(sf::Vector2f(sprite.getPosition().x +8*4 , sprite.getPosition().y+8*4));
    pv = 3;


}

Player::~Player()
{
}


void Player::movement_player(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Z: case sf::Keyboard::W:
            speed.y = -1;
            break;
        case sf::Keyboard::Q:case sf::Keyboard::A:
            speed.x = -1;
            break;
        case sf::Keyboard::D:
            speed.x = 1;
            break;
        case sf::Keyboard::S:
            speed.y = 1;
            break;
        }
    }

    if (event.type == sf::Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Z:case sf::Keyboard::W:
            speed.y = 0.;
            break;
        case sf::Keyboard::Q:case sf::Keyboard::A:
            speed.x = 0.;
            break;
        case sf::Keyboard::D:
            speed.x = 0.;
            break;
        case sf::Keyboard::S:
            speed.y = 0.;
            break;
        }
    }


}

void Player::attak(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::F) {
            attaquer = true;
            timing_atk.restart();
        }
    }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Entity::draw(target, states);
    if (attaquer)
    {
        target.draw(sprite_sword);
    }
}

void Player::update()
{
    Entity::update();
    sprite_sword.move(speed);
}

void Player::anim_attack(Ennemy& enemy)
{
    if (timing_atk.getElapsedTime().asSeconds() >= atk_speed && etat_anim_atk)
    {
        etat_anim_atk = false;
        attaquer = false;
        if (enemy.getIs_it())
        {
            enemy.setIs_it(false);
        }
    }

    if (!etat_anim_atk)
    {
        etat_anim_atk = true;
        switch (direction_anim)
        {
        case 1:
            sprite_sword.setRotation(-135);
            break;
        case 2:
            sprite_sword.setRotation(-45);
            break;
        case 3:
            sprite_sword.setRotation(135);
            break;
        default:
            sprite_sword.setRotation(45);
            break;
        }
    }
    else
    {
        switch (direction_anim)
        {
        case 1:
            sprite_sword.setRotation(-135 + 90 * timing_atk.getElapsedTime().asSeconds()/atk_speed);
            break;
        case 2:
            sprite_sword.setRotation(-45 + 90 * timing_atk.getElapsedTime().asSeconds() / atk_speed);
            break;
        case 3:
            sprite_sword.setRotation(135 + 90 * timing_atk.getElapsedTime().asSeconds() / atk_speed);
            break;
        default:
            sprite_sword.setRotation(45 + 90 * timing_atk.getElapsedTime().asSeconds() / atk_speed);
            break;
        }
    }
}

void Player::hitEnnemy(Ennemy& ennemy)
{
    if (sprite_sword.getGlobalBounds().intersects(ennemy.getSprite().getGlobalBounds()) && !ennemy.getIs_it())
    {
        ennemy.setIs_it(true);
        ennemy.take_damage(1);

    }
}


