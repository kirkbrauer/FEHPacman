//
// Created by Kirk Brauer on 11/21/19.
//

#include "Sprite.h"
#include "FEHLCD.h"
//#include "raylib.h"

Sprite::Sprite(unsigned int *f, unsigned int fc, int x, int y, int width, int height, Rotation rot) {
  frames = f;
  frame_count = fc;
  current_frame = 0;
  size = Size { width, height };
  position = Position { x, y };
  bounds = Bounds(&position, &size);
  rotation = rot;
}

Sprite::Sprite(unsigned int *f, unsigned int fc, Position pos, Size sz, Rotation rot) {
  frames = f;
  frame_count = fc;
  current_frame = 0;
  size = sz;
  position = pos;
  bounds = Bounds(&position, &size);
  rotation = rot;
}

Position *Sprite::get_position() {
  return &position;
}

void Sprite::set_position(int x, int y) {
  position = Position { x, y };
}

void Sprite::set_position(Position pos) {
  position = pos;
}

void Sprite::set_current_frame(unsigned int f) {
  current_frame = f;
}

unsigned int *Sprite::get_frame() {
  return &frames[current_frame * (size.width * size.height)];
}

unsigned int Sprite::get_frame_count() {
  return frame_count;
}

Size *Sprite::get_size() {
  return &size;
}

Bounds *Sprite::get_bounds() {
  return &bounds;
}

unsigned int Sprite::get_current_frame() {
  return current_frame;
}

void Sprite::draw_pixel(unsigned int x, unsigned int y, unsigned int hex) {
  /*Color color;
  color.r = hex / 256 / 256 % 256;
  color.g = hex / 256 % 256;
  color.b = hex % 256;
  color.a = 255;*/
  LCD.SetFontColor(hex);
  LCD.DrawPixel(position.x + x, position.y + y);
}

void Sprite::render() {
  unsigned int *frame = get_frame();
  unsigned int hex;
  for(unsigned int x = 0; x < size.width; x++) {
    for (unsigned int y = 0; y < size.height; y++) {
      switch (rotation) {
        case Deg0:
          hex = frame[(y * size.height) + x];
          break;
        case Deg90:
          hex = frame[((size.width - x - 1) * size.width) + y];
          break;
        case Deg180:
          hex = frame[(size.width - x - 1) + ((size.height - y - 1) * size.height)];
          break;
        case Deg270:
          hex = frame[(x * size.width) + (size.height - y - 1)];
          break;
      }
      if (hex != TRANSPARENT) {
        draw_pixel(x, y, hex);
      }
    }
  }
}
