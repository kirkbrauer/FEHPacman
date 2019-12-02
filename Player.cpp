//
// Created by Kirk Brauer on 11/22/19.
//

#include "Player.h"

unsigned int PLAYER_FRAMES[PLAYER_FRAME_COUNT*(PLAYER_SIZE*PLAYER_SIZE)] = {
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,

    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,

    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,

    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,

    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,

    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,

    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,

    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,

    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0xffff00,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,0x000000,0xffff00,0xffff00,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
};

Player::Player(Collider *c, int x, int y): Sprite(PLAYER_FRAMES, PLAYER_FRAME_COUNT, x, y, PLAYER_SIZE, PLAYER_SIZE) {
  current_frame = 0;
  direction = East;
  dead = false;
  moving = false;
  move_anim_direction = 1;
  last_anim_frame = 0;
  move_anim_frame = 0;
  coll = c;
}

void Player::update(unsigned int frame) {
  if ((frame - last_anim_frame) >= 2) {
    last_anim_frame = frame;
    move_anim_frame += move_anim_direction;
    if (move_anim_frame == 2) {
      move_anim_direction = -1;
    } else if (move_anim_frame == 0) {
      move_anim_direction = 1;
    }
  }
}

void Player::move(Direction dir) {
  moving = true;
  direction = dir;
  switch  (direction) {
    case North:
      position.y -= 1;
      break;
    case East:
      position.x += 1;
      break;
    case South:
      position.y += 1;
      break;
    case West:
      position.x -= 1;
      break;
  }
}

void Player::stop() {
  moving = false;
}

void Player::render() {
  if (move_anim_frame == 2 || !moving) {
    current_frame = 0;
  } else {
    switch  (direction) {
      case North:
        current_frame = 5 + move_anim_frame;
        break;
      case East:
        current_frame = 1 + move_anim_frame;
        break;
      case South:
        current_frame = 7 + move_anim_frame;
        break;
      case West:
        current_frame = 3 + move_anim_frame;
        break;
    }
  }
  Sprite::render();
}
