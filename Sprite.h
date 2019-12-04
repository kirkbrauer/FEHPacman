//
// Created by Kirk Brauer on 11/21/19.
//

#ifndef FEHPACMAN_SPRITE_H
#define FEHPACMAN_SPRITE_H

#include "Position.h"
#include "Size.h"
#define TRANSPARENT 0xFF00F5

// Defines the angles of rotation for a sprite bitmap
enum Rotation {
  Deg0 = 0,
  Deg90 = 90,
  Deg180 = 180,
  Deg270 = 270
};

/**
 * Represents a sprite that can be rendered to the screen.
 */
class Sprite {
  protected:
    // Array of unsigned integer hex values for the sprite frames
    unsigned int *frames;
    // The position of the sprite
    Position position;
    // The size of the sprite
    Size size;
    // The number of frames in the frames array
    unsigned int frame_count;
    // The current frame
    unsigned int current_frame;
    // Returns the current frame as a pointer
    unsigned int *get_frame();
    // Draws a pixel of a specified color on the screen at position x, y
    void draw_pixel(unsigned int x, unsigned int y, unsigned int color);
    // The rotation of the sprite
    Rotation rotation;
  public:
    /**
     * The primary Sprite constructor.
     * @param f The frames array.
     * @param fc The number of frames.
     * @param x The x position of the sprite.
     * @param y The y position of the sprite.
     * @param width The width of the sprite.
     * @param height The height of the sprite.
     * @param rot The rotation of the sprite.
     */
    Sprite(unsigned int *f, unsigned int fc, int x, int y, int width, int height, Rotation rot = Deg0);
    /**
     * The primary Sprite constructor.
     * @param f The frames array.
     * @param fc The number of frames.
     * @param pos The position of the sprite.
     * @param size The size of the sprite.
     * @param rot The rotation of the sprite.
     */
    Sprite(unsigned int *f, unsigned int fc, Position pos, Size sz, Rotation rot = Deg0);
    Position* get_position();
    Size* get_size();
    void set_position(int x, int y);
    void set_position(Position pos);
    void set_current_frame(unsigned int frame);
    unsigned int get_current_frame();
    unsigned int get_frame_count();
    void render();
    void update(unsigned int frame) {}
};


#endif //FEHPACMAN_SPRITE_H
