#include "Entity.h"
#include "Character_sprite.h"

Entity::Entity(sf::Texture& _texture, std::string _code, int _scale, int _tile_size)
{
    sprite.setTexture(_texture);
    sprite.setScale(_scale, _scale);
    std::string chara_name = character::chara_aliasses.at(_code);
    sf::Vector2i offset = character::chara_offset.at(chara_name);

    sprite.setTextureRect(sf::IntRect(sf::Vector2i(offset.x * _tile_size, offset.y * _tile_size), sf::Vector2i(_tile_size, _tile_size)));

    code = _code;
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
        code.replace(2, 1, "R");
    }
    if (std::abs(speed.x) > std::abs(speed.y) && speed.x < 0)
    {
        code.replace(2, 1, "L");
    }
    if (std::abs(speed.x) < std::abs(speed.y) && speed.y < 0)
    {
        code.replace(2, 1, "U");
    }
    if (std::abs(speed.x) < std::abs(speed.y) && speed.y > 0)
    {
        code.replace(2, 1, "D");
    }

    if (elapsed.asMilliseconds() >= 250 && speed != sf::Vector2f{ 0.f,0.f })
    {
        clock.restart();
        switch (code.at(3))
        {
        case '1':
            code.replace(3, 1, "2");
            break;
        case '2':
            code.replace(3, 1, "1");
            break;
        default:
            code.replace(3, 1, "1");
            break;
        }

    }
    std::string chara_name = character::chara_aliasses.at(code);
    sf::Vector2i offset = character::chara_offset.at(chara_name);

    sprite.setTextureRect(sf::IntRect(sf::Vector2i(offset.x * tile_size, offset.y * tile_size), sf::Vector2i(tile_size, tile_size)));

}

