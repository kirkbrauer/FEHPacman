//
// Created by Kirk Brauer on 12/02/19.
//

#ifndef FEHPACMAN_DOT_H
#define FEHPACMAN_DOT_H

#include "Sprite.h"

// Sizes for array of pixels
#define DOT_SIZE 8
#define DOT_FRAME_COUNT 2

// Dot for PAC-MAN to eat
class Dot: public Sprite {
  private:
    // If the dot is big
    bool big;
  public:
    // Default constructor
    Dot();
    /**
     * The primary Dot constructor.
     * @param x The x position of the dot.
     * @param y The y position of the dot.
     * @param big Wether the dot is big.
     */
    Dot(int x, int y, bool big);
    void set_big(bool big);
    // Standard Methods of Sprite
    void update(unsigned int frame);
    void render();
};

#endif //FEHPACMAN_DOT_H