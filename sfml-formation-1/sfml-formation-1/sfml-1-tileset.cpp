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
Vous devrez charger plusieurs sprites, de préférences dans un vector<>.
Vous devrez utiliser la fonction Sprite::setTextureRect() qui prend un IntRect en argument.

Un IntRect est un struct POD (plain old data type) contenant une origine et une taille, en entier.

Cette fonction permet de n'afficher que une certaine région de texture dans votre Sprite.

Je vous ai fourni un niveau à charger, une std::map<string,string> et une std::map<string, Vector2i> préremplies, et une image qui permet de visualiser la disposition des tiles.

Votre travail consiste à écrire la fonction load_level(), qui doit:
* instancier les Sprite et appeler la fonction setTextureRect() sur chacun d'entre eux.
* positionner les Sprites
Les tiles font 16x16px, il faudra donc multiplier par 16 les offset fournis dans la map
Il sera nécessaire de charger deux grilles de tiles, la première étant celle du sol, et l'autre des objets.

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

void drawAll(sf::RenderWindow& window, std::vector<std::vector<Sprite> >& sol, std::vector<std::vector<Sprite> >& level_element, Player& chara, Ennemy& ennemie, int& map_max_x, int& map_max_y) {
    window.clear();
    for (int y = 0; y < map_max_y; y++) {

        for (int x = 0; x < map_max_x; x++) {
            window.draw(sol[y][x]);
            window.draw(level_element[y][x]);
        }

    }
    
    if (ennemie.is_alive())
    {
        window.draw(ennemie);
        ennemie.update();
    }
    window.draw(chara);
    chara.update();
    window.display();
}

void entity_hit(Player& chara, Ennemy& ennemy) {
    if (chara.getAttaquer())
    {
        chara.anim_attack(ennemy);

        if (chara.getSprite_sword().getGlobalBounds().intersects(ennemy.getSprite().getGlobalBounds()) && !ennemy.getIs_it() && !ennemy.getInvincible() && ennemy.is_alive())
        {

            ennemy.setIs_it(true);
            ennemy.take_damage(1);
        }

    }
    else if (ennemy.getSprite().getGlobalBounds().intersects(chara.getSprite().getGlobalBounds()) && !chara.getIs_it() && !chara.getInvincible() && ennemy.is_alive())
    {
        chara.setIs_it(true);
        chara.take_damage(1);

    }

}

int main()
{  
    sf::RenderWindow window(sf::VideoMode(768, 512), "SFML works!");                    //initialisation des Variables, des Textures et Construction des objets
    sf::Clock clock_chara;  
    sf::Clock clock_ennemy;
    std::string chara_code = "NU";
    std::string enemy_code = "SK";

    sf::Vector2f speed_chara = { 0.f,0.f };
    sf::Vector2f speed_ennemy = { 0.f,0.f };

    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);

    int scale = 4;
    int tile_size = 16;
    int map_max_x = 13;
    int map_max_y = 11;

    Texture texture;
    texture.loadFromFile("Asset/foresttiles2-t.png");
    Texture texture_character;
    texture_character.loadFromFile("Asset/characters.png");
    Texture texture_sword;
    texture_sword.loadFromFile("Asset/sword.png");

    std::vector<Vector2f> posEnnemy = {                     //Position du déplacement de l'ennemi
        {350,400},
        {300.f,300.f},
        {250.f,190.f},
        {200.f, 149.f},
        {250.f, 49.f},
        {300.f, 249.f},
    };

    Player chara = Player(texture_character, texture_sword, chara_code, scale, tile_size);
    Ennemy ennemie = Ennemy(texture_character, enemy_code, scale, tile_size, posEnnemy);

    posEnnemy.~vector();

    int WidthView = 350;                 //Définition de la View sur le player
    int HeightView = 250;
    sf::View viewchara(sf::FloatRect(chara.getPosition().x-(WidthView/2 -(tile_size/2)*4), chara.getPosition().y-(HeightView / 2 - (tile_size / 2) * 4), WidthView, HeightView));

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(scale, scale);
    sprite.setTextureRect(IntRect(Vector2i(4 * tile_size, 6 * tile_size), Vector2i(tile_size, tile_size)));
    std::vector<std::vector<Sprite> > sol;
    std::vector<std::vector<Sprite> > level_element;
    load_level(level_element,texture,scale, tile_size);
    for (int y = 0; y < map_max_y; y++) {
        std::vector<Sprite> tmp;
        for (int x = 0; x < map_max_x; x++) {
            sprite.setPosition(x * tile_size * scale, y * tile_size * scale);
            tmp.push_back(sprite);
        }
        sol.push_back(tmp);
    }

    while (window.isOpen() && chara.is_alive())             //Boucle du Jeu
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (chara.getCheval() == 0) {                   //Vérification de l'état de mobilité
                chara.movement_player(event);
                
            }
            if (chara.getCheval() == 1) {
                chara.input_cheval(event);
            }
            if (!chara.getAttaquer())                       //Vérification pour l'attaque
            {
                chara.attak(event);
            }
            if (event.type == sf::Event::KeyPressed)
                switch (event.key.code)
                {
                case sf::Keyboard::B:                      //Changement d'état de mobilité
                    if (chara.getCheval() == 0) {
                        chara.setcheval(true);
                    }
                    else if (chara.getCheval() == 1) {
                        chara.setcheval(false);
                    }
                    break;
                }
        }

        chara.collision_border(scale, tile_size, map_max_x, map_max_y);     //Vérification pour la bordure
        chara.anim_chara(texture_character, clock_chara, tile_size);        //Animation du Player

        if (ennemie.is_alive())             //Vérification si l'ennemi est en vie
        {
            ennemie.anim_chara(texture_character, clock_ennemy, tile_size);             //Animation
            ennemie.passing_ennemy(clock_ennemy);                                       //Temps d'attente pour les déplacements
            ennemie.invinsibiliter();                                                   //Vérification de l'état d'invincibilté de l'ennemi pour une nouvelle touche par l'épée
        }
        if (chara.getCheval() == 1) {                   //Application des Forces si le joueur est sur le cheval
            chara.movepoussee();
        }

        entity_hit(chara, ennemie);
        chara.invinsibiliter();
        viewchara.move(chara.getSpeed().x, chara.getSpeed().y);                         //Application de la vitesse du joueur sur la caméra pour garder le focus
        window.setView(viewchara);
        drawAll(window, sol, level_element, chara, ennemie, map_max_x, map_max_y);      //Redessiner le tout
    }

    return 0;
}