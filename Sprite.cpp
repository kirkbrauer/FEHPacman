//
// Created by Kirk Brauer on 11/21/19.
//

#include "Sprite.h"
#include "FEHLCD.h"

Sprite::Sprite(const unsigned int *f, unsigned int fc, int x, int y, int width, int height, unsigned int s):
    frames(f),
    frame_count(fc),
    scale(s),
    size(Size { width, height }) {
  position = Position { x, y };
  bounds = Bounds(&position, &size);
}

Sprite::Sprite(const unsigned int *f, unsigned int fc, Position pos, Size sz, unsigned int s):
    frames(f),
    frame_count(0),
    scale(0),
    size(sz) {
  position = pos;
  bounds = Bounds(&position, &size);
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

const unsigned int *Sprite::get_frame() {
  return &frames[current_frame * (size.width * size.height)];
}

unsigned int Sprite::get_frame_count() {
  return frame_count;
}

const Size *Sprite::get_size() {
  return &size;
}

unsigned int Sprite::get_scale() {
  return scale;
}

Bounds *Sprite::get_bounds() {
  return &bounds;
}

unsigned int Sprite::get_current_frame() {
  return current_frame;
}

void Sprite::render() {
  const unsigned int *frame = get_frame();
  for(unsigned int x = 0; x < size.width; x++) {
    for (unsigned int y = 0; y < size.height; y++) {
      unsigned int hex = frame[(y * size.width) + x];
      LCD.SetFontColor(hex);
      LCD.FillRectangle((position.x * scale) + (x * scale), (position.y * scale) + (y * scale), scale, scale);
    }
  }
}
