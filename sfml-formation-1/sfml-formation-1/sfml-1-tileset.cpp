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

namespace character {
    std::map<std::string, Vector2i> chara_offset = {
        //nudiste sprite
        { "nudiste_down1",{0,0} },
        { "nudiste_down_stay",{1,0} },
        { "nudiste_down2",{2,0} },

        { "nudiste_left1",{0,1} },
        { "nudiste_left_stay",{1,1} },
        { "nudiste_left2",{2,1} },

        { "nudiste_right1",{0,2} },
        { "nudiste_right_stay",{1,2} },
        { "nudiste_right2",{2,2} },

        { "nudiste_up1",{0,3} },
        { "nudiste_up_stay",{1,3} },
        { "nudiste_up2",{2,3} },

        //boy sprite
        { "boy_down1",{3,0} },
        { "boy_down_stay",{4,0} },
        { "boy_down2",{5,0} },

        { "boy_left1",{3,1} },
        { "boy_left_stay",{4,1} },
        { "boy_left2",{5,1} },

        { "boy_right1",{3,2} },
        { "boy_right_stay",{4,2} },
        { "boy_right2",{5,2} },

        { "boy_up1",{3,3} },
        { "boy_up_stay",{4,3} },
        { "boy_up2",{5,3} },

        //girl sprite
        { "girl_down1",{6,0} },
        { "girl_down_stay",{7,0} },
        { "girl_down2",{8,0} },

        { "girl_left1",{6,1} },
        { "girl_left_stay",{7,1} },
        { "girl_left2",{8,1} },

        { "girl_right1",{6,2} },
        { "girl_right_stay",{7,2} },
        { "girl_right2",{8,2} },

        { "girl_up1",{6,3} },
        { "girl_up_stay",{7,3} },
        { "girl_up2",{8,3} },

        //skeleton sprite
        { "skeleton_down1",{9,0} },
        { "skeleton_down_stay",{10,0} },
        { "skeleton_down2",{11,0} },

        { "skeleton_left1",{9,1} },
        { "skeleton_left_stay",{10,1} },
        { "skeleton_left2",{11,1} },

        { "skeleton_right1",{9,2} },
        { "skeleton_right_stay",{10,2} },
        { "skeleton_right2",{11,2} },

        { "skeleton_up1",{9,3} },
        { "skeleton_up_stay",{10,3} },
        { "skeleton_up2",{11,3} },

        //slime sprite
        { "slime_down1",{0,4} },
        { "slime_down_stay",{1,4} },
        { "slime_down2",{2,4} },

        { "slime_left1",{0,5} },
        { "slime_left_stay",{1,5} },
        { "slime_left2",{2,5} },

        { "slime_right1",{0,6} },
        { "slime_right_stay",{1,6} },
        { "slime_right2",{2,6} },

        { "slime_up1",{0,7} },
        { "slime_up_stay",{1,7} },
        { "slime_up2",{2,7} },

        //bat sprite
        { "bat_down1",{3,4} },
        { "bat_down_stay",{4,4} },
        { "bat_down2",{5,4} },

        { "bat_left1",{3,5} },
        { "bat_left_stay",{4,5} },
        { "bat_left2",{5,5} },

        { "bat_right1",{3,6} },
        { "bat_right_stay",{4,6} },
        { "bat_right2",{5,6} },

        { "bat_up1",{3,7} },
        { "bat_up_stay",{4,7} },
        { "bat_up2",{5,7} },

        //ghost sprite
        { "ghost_down1",{6,4} },
        { "ghost_down_stay",{7,4} },
        { "ghost_down2",{8,4} },

        { "ghost_left1",{6,5} },
        { "ghost_left_stay",{7,5} },
        { "ghost_left2",{8,5} },

        { "ghost_right1",{6,6} },
        { "ghost_right_stay",{7,6} },
        { "ghost_right2",{8,6} },

        { "ghost_up1",{6,7} },
        { "ghost_up_stay",{7,7} },
        { "ghost_up2",{8,7} },

        //spider sprite
        { "spider_down1",{9,4} },
        { "spider_down_stay",{10,4} },
        { "spider_down2",{11,4} },

        { "spider_left1",{9,5} },
        { "spider_left_stay",{10,5} },
        { "spider_left2",{11,5} },

        { "spider_right1",{9,6} },
        { "spider_right_stay",{10,6} },
        { "spider_right2",{11,6} },

        { "spider_up1",{9,7} },
        { "spider_up_stay",{10,7} },
        { "spider_up2",{11,7} },
    };
    std::map<std::string, std::string> chara_aliasses = {
        //nudiste aliasse
        {"NUD1","nudiste_down1"},
        {"NUDS","nudiste_down_stay"},
        {"NUD2","nudiste_down2"},

        {"NUL1","nudiste_left1"},
        {"NULS","nudiste_left_stay"},
        {"NUL2","nudiste_left2"},

        {"NUR1","nudiste_right1"},
        {"NURS","nudiste_right_stay"},
        {"NUR2","nudiste_right2"},

        {"NUU1","nudiste_up1"},
        {"NUUS","nudiste_up_stay"},
        {"NUU2","nudiste_up2"},

        //boy aliasse
        {"BOD1","boy_down1"},
        {"BODS","boy_down_stay"},
        {"BOD2","boy_down2"},

        {"BOL1","boy_left1"},
        {"BOLS","boy_left_stay"},
        {"BOL2","boy_left2"},

        {"BOR1","boy_right1"},
        {"BORS","boy_right_stay"},
        {"BOR2","boy_right2"},

        {"BOU1","boy_up1"},
        {"BOUS","boy_up_stay"},
        {"BOU2","boy_up2"},

        //girl aliasse
        {"GID1","girl_down1"},
        {"GIDS","girl_down_stay"},
        {"GID2","girl_down2"},

        {"GIL1","girl_left1"},
        {"GILS","girl_left_stay"},
        {"GIL2","girl_left2"},

        {"GIR1","girl_right1"},
        {"GIRS","girl_right_stay"},
        {"GIR2","girl_right2"},

        {"GIU1","girl_up1"},
        {"GIUS","girl_up_stay"},
        {"GIU2","girl_up2"},

        //skeleton aliasse
        {"SKD1","skeleton_down1"},
        {"SKDS","skeleton_down_stay"},
        {"SKD2","skeleton_down2"},

        {"SKL1","skeleton_left1"},
        {"SKLS","skeleton_left_stay"},
        {"SKL2","skeleton_left2"},

        {"SKR1","skeleton_right1"},
        {"SKRS","skeleton_right_stay"},
        {"SKR2","skeleton_right2"},

        {"SKU1","skeleton_up1"},
        {"SKUS","skeleton_up_stay"},
        {"SKU2","skeleton_up2"},

        //slime aliasse
        {"SLD1","slime_down1"},
        {"SLDS","slime_down_stay"},
        {"SLD2","slime_down2"},

        {"SLL1","slime_left1"},
        {"SLLS","slime_left_stay"},
        {"SLL2","slime_left2"},

        {"SLR1","slime_right1"},
        {"SLRS","slime_right_stay"},
        {"SLR2","slime_right2"},

        {"SLU1","slime_up1"},
        {"SLUS","slime_up_stay"},
        {"SLU2","slime_up2"},

        //bat aliasse
        {"BAD1","bat_down1"},
        {"BADS","bat_down_stay"},
        {"BAD2","bat_down2"},

        {"BAL1","bat_left1"},
        {"BALS","bat_left_stay"},
        {"BAL2","bat_left2"},

        {"BAR1","bat_right1"},
        {"BARS","bat_right_stay"},
        {"BAR2","bat_right2"},

        {"BAU1","bat_up1"},
        {"BAUS","bat_up_stay"},
        {"BAU2","bat_up2"},

        //ghost aliasse
        { "GHD1","ghost_down1" },
        { "GHDS","ghost_down_stay" },
        { "GHD2","ghost_down2" },

        { "GHL1","ghost_left1" },
        { "GHLS","ghost_left_stay" },
        { "GHL2","ghost_left2" },

        { "GHR1","ghost_right1" },
        { "GHRS","ghost_right_stay" },
        { "GHR2","ghost_right2" },

        { "GHU1","ghost_up1" },
        { "GHUS","ghost_up_stay" },
        { "GHU2","ghost_up2" },

        //spider aliasse
        { "SPD1","spider_down1" },
        { "SPDS","spider_down_stay" },
        { "SPD2","spider_down2" },

        { "SPL1","spider_left1" },
        { "SPLS","spider_left_stay" },
        { "SPL2","spider_left2" },

        { "SPR1","spider_right1" },
        { "SPRS","spider_right_stay" },
        { "SPR2","spider_right2" },

        { "SPU1","spider_up1" },
        { "SPUS","spider_up_stay" },
        { "SPU2","spider_up2" },
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

void anim_chara(sf::Vector2f& speed_chara, std::string& chara_code, Texture& texture, sf::Clock& clock, Sprite& chara) {
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asMilliseconds() >= 250 && speed_chara != sf::Vector2f{ 0.f,0.f })
    {
        clock.restart();
        switch (chara_code.at(3))
        {
        case '1':
            chara_code.replace(3, 1, "2");
            break;
        case '2':
            chara_code.replace(3, 1, "1");
            break;
        default:
            chara_code.replace(3, 1, "1");
            break;
        }
        
    }
    std::string chara_name = character::chara_aliasses.at(chara_code);
    Vector2i offset = character::chara_offset.at(chara_name);

    chara.setTextureRect(IntRect(Vector2i(offset.x * 16, offset.y * 16), Vector2i(16, 16)));

}

int main()
{
    sf::RenderWindow window(sf::VideoMode(768, 512), "SFML works!");
    sf::Clock clock;
    std::string chara_code = "NUDS";

    sf::Vector2f speed_chara = { 0.f,0.f };

    Texture texture;
    texture.loadFromFile("foresttiles2-t.png");
    Texture texture_character;
    texture_character.loadFromFile("characters.png");

    Sprite chara;
    chara.setTexture(texture_character);
    chara.setScale(4, 4);
    chara.setTextureRect(IntRect(Vector2i(1 * 16, 0 * 16), Vector2i(16, 16)));

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

            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Z:
                    speed_chara.y = -0.1;
                    chara_code.replace(2, 1, "U");
                    break;
                case sf::Keyboard::Q:
                    speed_chara.x = -0.1;
                    chara_code.replace(2, 1, "L");
                    break;
                case sf::Keyboard::D:
                    speed_chara.x = 0.1;
                    chara_code.replace(2, 1, "R");
                    break;
                case sf::Keyboard::S:
                    speed_chara.y = 0.1;
                    chara_code.replace(2, 1, "D");
                    break;
                }
            }

            if (event.type == sf::Event::KeyReleased)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Z:
                    speed_chara.y = 0.;
                    if (speed_chara == sf::Vector2f{ 0.f,0.f })
                    {
                        chara_code.replace(2, 2, "US");
                    }
                    break;
                case sf::Keyboard::Q:
                    speed_chara.x = 0.;
                    if(speed_chara == sf::Vector2f{ 0.f,0.f })
                    {
                        chara_code.replace(2, 2, "LS");
                    }
                    break;
                case sf::Keyboard::D:
                    speed_chara.x = 0.;
                    if (speed_chara == sf::Vector2f{ 0.f,0.f })
                    {
                        chara_code.replace(2, 2, "RS");
                    }    
                    break;
                case sf::Keyboard::S:
                    speed_chara.y = 0.;
                    if (speed_chara == sf::Vector2f{ 0.f,0.f })
                    {
                        chara_code.replace(2, 2, "DS");
                    }
                    break;
                }
            }
        }

        if (chara.getPosition().x + 16*4 >= 768 && speed_chara.x >= 0)
        {
            speed_chara.x = 0;
        }
        if (chara.getPosition().x <= 0 && speed_chara.x <= 0)
        {
            speed_chara.x = 0;
        }
        if (chara.getPosition().y + 16*4 >= 512 && speed_chara.y >= 0)
        {
            speed_chara.y = 0;
        }
        if (chara.getPosition().y <= 0 && speed_chara.y <= 0)
        {
            speed_chara.y = 0;
        }

        anim_chara(speed_chara, chara_code, texture_character, clock, chara);


        window.clear();
        for (int y = 0; y < 8; y++) {

            for (int x = 0; x < 12; x++) {
                window.draw(sol[y][x]);
                window.draw(level_element[y][x]);
            }

        }
        window.draw(chara);
        chara.move(speed_chara);
        window.display();
    }

    return 0;
}