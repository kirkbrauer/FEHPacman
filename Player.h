//
// Created by Kirk Brauer on 11/22/19.
//

#ifndef FEHPACMAN_PLAYER_H
#define FEHPACMAN_PLAYER_H

#include "Sprite.h"
#include "Direction.h"
#include "Collider.h"

#define PLAYER_SIZE 16
#define PLAYER_FRAME_COUNT 3

class Player: public Sprite {
  private:
    Direction direction;
    int score;
    bool dead;
    bool moving;
    unsigned int last_anim_frame;
    unsigned int move_anim_frame;
    int move_anim_direction;
    Collider *coll;
  public:
    Player(Collider *coll, int x, int y);
    void update(unsigned int frame);
    void move(Direction dir);
    void stop();
    void render();
};


#endif //FEHPACMAN_PLAYER_H
