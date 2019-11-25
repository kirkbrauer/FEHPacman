//
// Created by Kirk Brauer on 11/21/19.
//

#ifndef FEHGAMECLASSES_SPRITE_H
#define FEHGAMECLASSES_SPRITE_H

#include "Entity.h"
#include "Position.h"
#include "Size.h"
#include "Bounds.h"

struct RGB {
  unsigned int r, g, b;
};

class Sprite: public Entity {
  protected:
    const unsigned int *frames;
    Position position {};
    Bounds bounds;
    const Size size;
    const unsigned int frame_count;
    const unsigned int scale;
    unsigned int current_frame = 0;
    const unsigned int *get_frame();
  public:
    Sprite(const unsigned int *f, unsigned int fc, int x, int y, int width, int height, unsigned int s = 1);
    Sprite(const unsigned int *f, unsigned int fc, Position pos, Size sz, unsigned int s = 1);
    Position* get_position();
    Bounds* get_bounds();
    const Size* get_size();
    void set_position(int x, int y);
    void set_position(Position pos);
    void set_current_frame(unsigned int frame);
    unsigned int get_current_frame();
    unsigned int get_frame_count();
    unsigned int get_scale();
    void render() override;
};


#endif //FEHGAMECLASSES_SPRITE_H
