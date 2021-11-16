#include "Entity.h"
#include "Character_sprite.h"

Entity::Entity(sf::Texture& _texture, std::string _code, int _scale, int _tile_size)
{
    sprite.setTexture(_texture);
    sprite.setScale(_scale, _scale);
    code = _code;
    std::string chara_name = character::chara_aliasses.at(_code.append("DS"));
    sf::Vector2i offset = character::chara_offset.at(chara_name);

    sprite.setTextureRect(sf::IntRect(sf::Vector2i(offset.x * _tile_size, offset.y * _tile_size), sf::Vector2i(_tile_size, _tile_size)));
}

Entity::~Entity()
{
}



void Entity::collision_border(int scale, int tile_size) {
    if (sprite.getPosition().x + tile_size * scale >= 768 && speed.x >= 0)
    {
        speed.x = 0;
    }
    if (sprite.getPosition().x <= 0 && speed.x <= 0)
    {
        speed.x = 0;
    }
    if (sprite.getPosition().y + tile_size * scale >= 512 && speed.y >= 0)
    {
        speed.y = 0;
    }
    if (sprite.getPosition().y <= 0 && speed.y <= 0)
    {
        speed.y = 0;
    }
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(sprite);
}

void Entity::update()
{
    sprite.move(speed);
}

void Entity::anim_chara(sf::Texture& texture, sf::Clock& clock, int tile_size) {
    sf::Time elapsed = clock.getElapsedTime();
    if (std::abs(speed.x) > std::abs(speed.y) && speed.x > 0)
    {
        direction_anim = 2;
    }
    if (std::abs(speed.x) > std::abs(speed.y) && speed.x < 0)
    {
        direction_anim = 3;
    }
    if (std::abs(speed.x) < std::abs(speed.y) && speed.y < 0)
    {
        direction_anim = 1;
    }
    if (std::abs(speed.x) < std::abs(speed.y) && speed.y > 0)
    {
        direction_anim = 0;
    }

    if (elapsed.asMilliseconds() >= 250 && speed != sf::Vector2f{ 0.f,0.f })
    {
        clock.restart();
        switch (state_anime)
        {
        case 1:
            state_anime = 2;
            break;
        case 2:
            state_anime = 1;
            break;
        default:
            state_anime = 1;
            break;
        }

    }
    else if (speed == sf::Vector2f{ 0.f,0.f })
    {
        state_anime = 0;
    }

    std::string tmp_code = code;
    switch (direction_anim)
    {
    case 1:
        tmp_code.append("U");
        break;
    case 2:
        tmp_code.append("R");
        break;
    case 3:
        tmp_code.append("L");
        break;
    default:
        tmp_code.append("D");
        break;
    }

    switch (state_anime)
    {
    case 1:
        tmp_code.append("1");
        break;
    case 2:
        tmp_code.append("2");
        break;
    default:
        tmp_code.append("S");
        break;
    }

    if (invincible)
    {

        

        sprite.setColor(sf::Color(255, 255, 255, 128));
    }
    else {
        sprite.setColor(sf::Color(255, 255, 255, 255));
    }

    std::string chara_name = character::chara_aliasses.at(tmp_code);
    sf::Vector2i offset = character::chara_offset.at(chara_name);
    sprite.setTextureRect(sf::IntRect(sf::Vector2i(offset.x * tile_size, offset.y * tile_size), sf::Vector2i(tile_size, tile_size)));

}

void Entity::setIs_it(bool _is_hit)
{
    is_hit = _is_hit;
}

void Entity::invinsibiliter()
{
    if (is_hit && !invincible)
    {
        invincible_timing.restart();
        invincible = true;
    }
    else if (invincible && invincible_timing.getElapsedTime().asSeconds() >= invinsible_time)
    {
        invincible = false;
    }
}


