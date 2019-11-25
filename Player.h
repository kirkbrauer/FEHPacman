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
    Direction direction = North;
    int score = 0;
    bool dead = false;
    bool moving = false;
    unsigned int last_anim_frame = 0;
    unsigned int move_anim_frame = 0;
    int move_anim_direction = 1;
  public:
    Player(int x, int y, unsigned int scale);
    void update(unsigned int frame) final;
    void move(Direction dir);
    void stop();
    void render() override;
};


#endif //FEHGAMECLASSES_PLAYER_H
