#include "Ennemy.h"
#include <iostream>


Ennemy::Ennemy(sf::Texture& _texture, std::string _code, int _scale, int _tile_size, std::vector<sf::Vector2f> _posEnnemy) : Entity(_texture, _code, _scale, _tile_size)
{
    pv = 3;
    pv_max = 3;
	posEnnemy = _posEnnemy;
	sprite.setPosition(posEnnemy[0]);
}

Ennemy::~Ennemy()
{
}

void Ennemy::passing_ennemy(sf::Clock& clock_ennemy) {
    if (mouv)
    {
        if (sprite.getPosition().x <= posEnnemy[ennemy_des].x + 0.5 && sprite.getPosition().x >= posEnnemy[ennemy_des].x - 0.5)
        {
            if (sprite.getPosition().y <= posEnnemy[ennemy_des].y + 0.5 && sprite.getPosition().y >= posEnnemy[ennemy_des].y - 0.5)
            {
                pause.restart();
                mouv = false;
                               
                if (ennemy_des == posEnnemy.size() - 1)
                {
                    aller = false;
                }
                if (ennemy_des == 0)
                {
                    aller = true;
                }

                if (aller)
                {
                    ennemy_des++;
                }
                else {
                    ennemy_des--;
                }
                
            }
        }
    }
    else if (pause.getElapsedTime().asSeconds()>= 1 && !mouv)
    {
        mouv = true;
    }
    move_ennemy(posEnnemy[ennemy_des], clock_ennemy);
    
}

void Ennemy::move_ennemy(sf::Vector2f& destination, sf::Clock& clock) {

    if (mouv)
    {
        speed.x = (destination.x - sprite.getPosition().x);
        speed.y = (destination.y - sprite.getPosition().y);
        float norme = sqrt(speed.x * speed.x + speed.y * speed.y);
        if (norme > speed.x && norme > speed.y)
        {
            speed = speed / norme;
        }
    }
    else
    {
        speed.x = 0;
        speed.y = 0;
    }

}

