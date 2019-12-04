//
// Created by Kirk Brauer on 11/21/19.
//

#include "Sprite.h"
#include "FEHLCD.h"

Sprite::Sprite(unsigned int *f, unsigned int fc, int x, int y, int width, int height, Rotation rot) {
  frames = f;
  frame_count = fc;
  current_frame = 0;
  size = Size { width, height };
  position = Position { x, y };
  rotation = rot;
}

Sprite::Sprite(unsigned int *f, unsigned int fc, Position pos, Size sz, Rotation rot) {
  frames = f;
  frame_count = fc;
  current_frame = 0;
  size = sz;
  position = pos;
  rotation = rot;
}

Position *Sprite::get_position() {
  // Return a reference to the positon
  return &position;
}

void Sprite::set_position(int x, int y) {
  // Set the sprite position
  position = Position { x, y };
}

void Sprite::set_position(Position pos) {
  // Set the sprite position
  position = pos;
}

void Sprite::set_current_frame(unsigned int f) {
  // Set the current frame
  current_frame = f;
}

unsigned int *Sprite::get_frame() {
  // Return a reference to the current frame
  return &frames[current_frame * (size.width * size.height)];
}

unsigned int Sprite::get_frame_count() {
  // Return the frame count
  return frame_count;
}

Size *Sprite::get_size() {
  // Return a reference to the size
  return &size;
}

unsigned int Sprite::get_current_frame() {
  // Return the current frame index
  return current_frame;
}

void Sprite::draw_pixel(unsigned int x, unsigned int y, unsigned int hex) {
  // Set the LCD font color
  LCD.SetFontColor(hex);
  // Draw the pixel at the specified position
  LCD.DrawPixel(position.x + x, position.y + y);
}

void Sprite::render() {
  // Get a pointer to the frame
  unsigned int *frame = get_frame();
  unsigned int hex;
  // Loop through each pixel
  for(unsigned int x = 0; x < size.width; x++) {
    for (unsigned int y = 0; y < size.height; y++) {
      // Select the correct pixel depending on the rotation of the sprite
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
      // Don't draw transparent pixels.
      if (hex != TRANSPARENT) {
        draw_pixel(x, y, hex);
      }
    }
  }
}
