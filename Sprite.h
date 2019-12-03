//
// Created by Kirk Brauer on 11/21/19.
//

#ifndef FEHPACMAN_SPRITE_H
#define FEHPACMAN_SPRITE_H

#include "Entity.h"
#include "Position.h"
#include "Size.h"
#include "Bounds.h"
#define TRANSPARENT 0xFF00F5

struct RGB {
  unsigned int r, g, b;
};

enum Rotation {
  Deg0 = 0,
  Deg90 = 90,
  Deg180 = 180,
  Deg270 = 270
};

class Sprite: public Entity {
  protected:
    unsigned int *frames;
    Position position;
    Bounds bounds;
    Size size;
    unsigned int frame_count;
    unsigned int current_frame;
    unsigned int *get_frame();
    void draw_pixel(unsigned int x, unsigned int y, unsigned int color);
    Rotation rotation;
  public:
    Sprite(unsigned int *f, unsigned int fc, int x, int y, int width, int height, Rotation rot = Deg0);
    Sprite(unsigned int *f, unsigned int fc, Position pos, Size sz, Rotation rot = Deg0);
    Position* get_position();
    Bounds* get_bounds();
    Size* get_size();
    void set_position(int x, int y);
    void set_position(Position pos);
    void set_current_frame(unsigned int frame);
    unsigned int get_current_frame();
    unsigned int get_frame_count();
    unsigned int get_scale();
    void render();
};


#endif //FEHPACMAN_SPRITE_H
