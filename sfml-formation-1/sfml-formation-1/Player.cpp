#include "Player.h"


Player::Player(sf::Texture& _texture, std::string _code, int _scale, int _tile_size) : Entity(_texture, _code, _scale, _tile_size)
{
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
        case sf::Keyboard::Z:
            speed.y = -0.5;
            code.replace(2, 1, "U");
            break;
        case sf::Keyboard::Q:
            speed.x = -0.5;
            code.replace(2, 1, "L");
            break;
        case sf::Keyboard::D:
            speed.x = 0.5;
            code.replace(2, 1, "R");
            break;
        case sf::Keyboard::S:
            speed.y = 0.5;
            code.replace(2, 1, "D");
            break;
        }
    }

    if (event.type == sf::Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Z:
            speed.y = 0.;
            if (speed == sf::Vector2f{ 0.f,0.f })
            {
                code.replace(2, 2, "US");
            }
            break;
        case sf::Keyboard::Q:
            speed.x = 0.;
            if (speed == sf::Vector2f{ 0.f,0.f })
            {
                code.replace(2, 2, "LS");
            }
            break;
        case sf::Keyboard::D:
            speed.x = 0.;
            if (speed == sf::Vector2f{ 0.f,0.f })
            {
                code.replace(2, 2, "RS");
            }
            break;
        case sf::Keyboard::S:
            speed.y = 0.;
            if (speed == sf::Vector2f{ 0.f,0.f })
            {
                code.replace(2, 2, "DS");
            }
            break;
        }
    }


}


