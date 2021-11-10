#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <iostream>
#include <cmath>        // std::abs
#include "Entity.h"
#include "LevelSprite.h"
#include "Player.h"
#include "Ennemy.h"

using namespace sf;
/*
Dans cet example, vous allez devoir charger et afficher un tileset
Vous devrez charger plusieurs sprites, de pr�f�rences dans un vector<>.
Vous devrez utiliser la fonction Sprite::setTextureRect() qui prend un IntRect en argument.

Un IntRect est un struct POD (plain old data type) contenant une origine et une taille, en entier.

Cette fonction permet de n'afficher que une certaine r�gion de texture dans votre Sprite.

Je vous ai fourni un niveau � charger, une std::map<string,string> et une std::map<string, Vector2i> pr�remplies, et une image qui permet de visualiser la disposition des tiles.

Votre travail consiste � �crire la fonction load_level(), qui doit:
* instancier les Sprite et appeler la fonction setTextureRect() sur chacun d'entre eux.
* positionner les Sprites
Les tiles font 16x16px, il faudra donc multiplier par 16 les offset fournis dans la map
Il sera n�cessaire de charger deux grilles de tiles, la premi�re �tant celle du sol, et l'autre des objets.

*/

void load_level(std::vector<std::vector<Sprite> >& level_element, Texture& texture, int scale, int tile_size) {

    for (int i = 0; i < level::tile_strings.size(); i++)
    {
        std::vector<Sprite> tmp;
        for (int j = 0; j < level::tile_strings[i].size()/3; j++)
        {
            std::string str = level::tile_strings[i].substr(j*3, 2);
           
            if (str != "  ")
            {
                std::string tile_name = level::aliasses.at(str);
                Vector2i offset = level::tile_offsets.at(tile_name);

                Sprite shape;
                shape.setTexture(texture);
                shape.setScale(scale, scale);
                shape.setTextureRect(IntRect(Vector2i(offset.x * tile_size, offset.y * tile_size), Vector2i(tile_size, tile_size)));
                shape.setPosition(j * tile_size * scale, i * tile_size * scale);
                tmp.push_back(shape);
            }
            else
            {
                Sprite shape;
                shape.setTexture(texture);
                shape.setScale(scale, scale);
                shape.setTextureRect(IntRect(Vector2i(0,0), Vector2i(0, 0)));

                shape.setPosition(j * tile_size * scale, i * tile_size * scale);
                tmp.push_back(shape);
            }
            
        }
        level_element.push_back(tmp);
        
    }
}

void drawAll(sf::RenderWindow& window, std::vector<std::vector<Sprite> >& sol, std::vector<std::vector<Sprite> >& level_element, Player& chara, Ennemy& ennemie) {
    window.clear();
    for (int y = 0; y < 8; y++) {

        for (int x = 0; x < 12; x++) {
            window.draw(sol[y][x]);
            window.draw(level_element[y][x]);
        }

    }

    window.draw(chara);
    window.draw(ennemie);
    chara.update();
    ennemie.update();
    window.display();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(768, 512), "SFML works!");
    sf::Clock clock_chara;
    sf::Clock clock_ennemy;
    std::string chara_code = "NUDS";
    std::string enemy_code = "SKDS";

    sf::Vector2f speed_chara = { 0.f,0.f };
    sf::Vector2f speed_ennemy = { 0.f,0.f };

    window.setKeyRepeatEnabled(false);

    int scale = 4;
    int tile_size = 16;

    Texture texture;
    texture.loadFromFile("foresttiles2-t.png");
    Texture texture_character;
    texture_character.loadFromFile("characters.png");

    std::vector<Vector2f> posEnnemy = {
        {350,400},
        {300.f,300.f},
        {250.f,190.f},
        {200.f, 149.f},
        {250.f, 49.f},
        {300.f, 249.f},
    };

    Player chara = Player(texture_character, chara_code, scale, tile_size);
    Ennemy ennemie = Ennemy(texture_character, enemy_code, scale, tile_size, posEnnemy);

    posEnnemy.~vector();

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(scale, scale);
    sprite.setTextureRect(IntRect(Vector2i(4 * tile_size, 6 * tile_size), Vector2i(tile_size, tile_size)));
    std::vector<std::vector<Sprite> > sol;
    std::vector<std::vector<Sprite> > level_element;
    load_level(level_element,texture,scale, tile_size);
    for (int y = 0; y < 8; y++) {
        std::vector<Sprite> tmp;
        for (int x = 0; x < 12; x++) {
            sprite.setPosition(x * tile_size * scale, y * tile_size * scale);
            tmp.push_back(sprite);
        }
        sol.push_back(tmp);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            chara.movement_player(event);
        }

        chara.collision_border(scale, tile_size);
        chara.anim_chara(texture_character, clock_chara, tile_size);
        ennemie.anim_chara(texture_character, clock_chara, tile_size);
        ennemie.passing_ennemy(clock_ennemy);

        drawAll(window, sol, level_element, chara, ennemie);
        
    }

    return 0;
}