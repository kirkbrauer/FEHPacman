//
// Created by Kirk Brauer on 11/22/19.
//

#ifndef FEHGAMECLASSES_PLAYER_H
#define FEHGAMECLASSES_PLAYER_H

#include "Sprite.h"
#include "Direction.h"

#define PLAYER_SIZE 13
#define PLAYER_FRAME_COUNT 9

class Player: public Sprite {
  private:
    Direction direction;
    int score;
    bool dead;
    bool moving;
    unsigned int last_anim_frame;
    unsigned int move_anim_frame;
    int move_anim_direction;
  public:
    Player(int x, int y, unsigned int scale);
    void update(unsigned int frame);
    void move(Direction dir);
    void stop();
    void render();
};


#endif //FEHGAMECLASSES_PLAYER_H
