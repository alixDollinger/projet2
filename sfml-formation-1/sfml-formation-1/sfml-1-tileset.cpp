#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <iostream>
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

namespace level {
    std::map<std::string, Vector2i> tile_offsets = {
        { "convex_angle1", {0,0}},    //
        { "convex_angle2", {1,0}},    //

        { "convex_side1", {0,1}},     //
        { "convex_side2", {1,1}},     //

        { "convex_angle3", {0,2}},    //
        { "convex_angle4", {1,2}},    //


        { "forest_NW", {2,0}},        //
        { "forest_N", {3,0}},         //
        { "forest_NE", {4,0}},        //

        { "forest_W", {2,1}},         //
        { "forest_C", {3,1}},         //
        { "forest_E", {4,1}},         //

        { "forest_SW", {2,2}},        //
        { "forest_S", {3,2}},         //
        { "forest_SE", {4,2}},        //

        { "forest_S2", {0,5}},        //


        { "tree_big_1", {0,3}},       //
        { "tree_big_2", {1,3}},       //
        { "tree_big_3", {0,4}},       //
        { "tree_big_4", {1,4}},       //


        { "stump1", {2,3}},           //
        { "stump2", {2,4}},           //
        { "flowers", {3,3}},          //
        { "grass", {1,5}},            //

        { "ground", {4,6}},           //

        { "pool", {3,3}},  //
        { "river_corner_BL", {1,6}},  //
        { "river_corner_BR", {0,6}},  //

        { "river_corner_TR", {2,6}},  //
        { "river_corner_TL", {3,6}},  //

        { "river_vert", {2,5}},       //
        { "river_horiz", {3,5}},      //


        { "tree_base", {4,5}},        //
        { "tree_middle", {4,4}},      //
        { "tree_top", {4,3}},         //
        { "nothing", {0,7}}
    };
    std::map<std::string, std::string> aliasses = {

        { "A1", "convex_angle1" },
        { "A2", "convex_angle2" },

        { "S1", "convex_side1" },
        { "S2", "convex_side2" },

        { "A3", "convex_angle3" },
        { "A4", "convex_angle4" },


        { "F1", "forest_NW" },
        { "FN", "forest_N" },
        { "F2", "forest_NE" },

        { "FW", "forest_W" },
        { "FC", "forest_C" },
        { "FE", "forest_E" },

        { "F7", "forest_SW" },
        { "FS", "forest_S" },
        { "F4", "forest_SE" },

        { "FZ", "forest_S2" },


        { "T1", "tree_big_1" },
        { "T2", "tree_big_2" },
        { "T3", "tree_big_3" },
        { "T4", "tree_big_4" },


        { "d1", "stump1" },
        { "d2", "stump2" },
        { "FL", "flowers" },
        { "GS", "grass" },

        { "GD", "ground" },
        { "PL", "pool" },

        { "R2", "river_corner_BL" },
        { "R1", "river_corner_BR" },

        { "R3", "river_corner_TR" },
        { "R4", "river_corner_TL" },

        { "RH", "river_horiz" },
        { "RV", "river_vert" },


        { "tb", "tree_base" },
        { "tm", "tree_middle" },
        { "tt", "tree_top" },
        { "--", "nothing" },

    };
    std::vector<std::string> tile_strings = {
        "   GS GS                FW FC A2 -- ",
        "      GS GS       tt    F7 FS S2 -- ",
        "                  tb    tt    FW FC ",
        "   T1 T2    FL          tm    F7 FS ",
        "   T3 T4          GS    tb    F1 FN ",
        "                     F1 FN FN A4 -- ",
        "      R1 R2    F1 FN A4 -- -- -- -- ",
        "R1 RH R4 R3 R2 FW -- -- -- -- -- -- ",

    };
}

void load_level(std::vector<std::vector<Sprite> >& level_element, Texture& texture) {

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
                shape.setScale(4, 4);
                shape.setTextureRect(IntRect(Vector2i(offset.x * 16, offset.y * 16), Vector2i(16, 16)));
                //shape.setTextureRect(IntRect(Vector2i(4 * 16, 2 * 16), Vector2i(16, 16)));
                shape.setPosition(j * 16 * 4, i * 16 * 4);
                tmp.push_back(shape);
            }
            else
            {
                Sprite shape;
                shape.setTexture(texture);
                shape.setScale(4, 4);
                shape.setTextureRect(IntRect(Vector2i(0,0), Vector2i(0, 0)));

                shape.setPosition(j * 16 * 4, i * 16 * 4);
                tmp.push_back(shape);
            }
            
        }
        level_element.push_back(tmp);
        
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    Texture texture;
    texture.loadFromFile("foresttiles2-t.png");

    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(4, 4);
    sprite.setTextureRect(IntRect(Vector2i(4 * 16, 6 * 16), Vector2i(16, 16)));
    std::vector<std::vector<Sprite> > sol;
    std::vector<std::vector<Sprite> > level_element;
    load_level(level_element,texture);
    for (int y = 0; y < 8; y++) {
        std::vector<Sprite> tmp;
        for (int x = 0; x < 12; x++) {
            sprite.setPosition(x * 16 *4, y * 16 * 4);
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
        }


        window.clear();
        for (int y = 0; y < 8; y++) {

            for (int x = 0; x < 12; x++) {
                window.draw(sol[y][x]);
                window.draw(level_element[y][x]);
            }

        }
        
        Sprite shape;
        shape.setTexture(texture);
        shape.setScale(4, 4);
        shape.setTextureRect(IntRect(Vector2i(4 * 16, 2 * 16), Vector2i(16, 16)));
        window.draw(shape);
        window.display();
    }

    return 0;
}