#include <math.h>
#include "Ghost.h"
#include "Direction.h"
#include "Player.h"
#include <FEHLCD.h>
#include <FEHUtility.h>

unsigned int ghost_frames[GHOST_FRAME_COUNT*(GHOST_SIZE*GHOST_SIZE)] = {
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
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000
};

Ghost::Ghost() : Sprite(ghost_frames, GHOST_FRAME_COUNT, 0, 0, GHOST_SIZE, GHOST_SIZE) {}

Ghost::Ghost(Collider *c, Player *p, int ghost, int x, int y) : Sprite(ghost_frames, GHOST_FRAME_COUNT, x, y, GHOST_SIZE, GHOST_SIZE), p(p) {
    mode = CHASE;
    modeTime = 0;
    alive = true;
    coll = c;
}

Ghost::Ghost(Collider *c, Player *p, int ghost, Position pos) : Sprite(ghost_frames, GHOST_FRAME_COUNT, pos, Size{GHOST_SIZE,GHOST_SIZE}), p(p) {
    mode = CHASE;
    modeTime = 0;
    alive = true;
    coll = c;
}

void Ghost::update(unsigned int frame) {}

float Ghost::distanceToPlayer(int xOff, int yOff) {
    float val = pow(p->get_position()->x-position.x-xOff, 2) + pow(p->get_position()->y-position.y+yOff, 2);
    return sqrt(val);
}

void Ghost::move() {
    if (!alive) return;
    if (coll->at_intersection(position.x, position.y)) {
        // Chose Direction
        LCD.SetFontColor(WHITE);
        float distance = 10000000; // TODO : Better than default high value
        enum Direction min;
        if (coll->can_go_north(position.x, position.y)) {
            min = North;
            distance = distanceToPlayer(0, 8);
        }
        if (coll->can_go_south(position.x, position.y) && distanceToPlayer(0, -8) < distance) {
            min = South;
            distance = distanceToPlayer(0, -8);
        }
        if (coll->can_go_east(position.x, position.y) && distanceToPlayer(8, 0) < distance) {
            min = East;
            distance = distanceToPlayer(8, 0);
        }
        if (coll->can_go_west(position.x, position.y) && distanceToPlayer(-8, 0) < distance) {
            min = West;
            distance = distanceToPlayer(-8, 0);
        }
        /*LCD.Clear();
        LCD.WriteLine(coll->can_go_north(position.x, position.y));
        LCD.WriteLine(coll->can_go_south(position.x, position.y));
        LCD.WriteLine(coll->can_go_east(position.x, position.y));
        LCD.WriteLine(coll->can_go_west(position.x, position.y));
        Sleep(2000);*/
        dir = min;
    }
    // Move Forward
    switch  (dir) {
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

void Ghost::kill() {
    alive = false;
}