//
// Created by Kirk Brauer on 12/02/19.
//

#ifndef FEHPACMAN_DOT_H
#define FEHPACMAN_DOT_H

#include "Sprite.h"

#define DOT_SIZE 8
#define DOT_FRAME_COUNT 2

class Dot: public Sprite {
  private:
    bool big;
    bool eaten;
  public:
    Dot();
    Dot(int x, int y, bool big);
    void set_big(bool big);
    void update(unsigned int frame);
    void eat();
    void render();
};

#endif //FEHPACMAN_DOT_H