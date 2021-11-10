#pragma once
#include <map>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace character {
    std::map<std::string, sf::Vector2i> chara_offset = {
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
    };;
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

