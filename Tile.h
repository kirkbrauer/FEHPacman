//
// Created by Kirk Brauer on 12/02/19.
//

#ifndef FEHPACMAN_TILE_H
#define FEHPACMAN_TILE_H

#include "Sprite.h"

#define TILE_SIZE 8
#define TILE_FRAME_COUNT 11

enum TileType {
  None = 0,
  DoubleStraight = 1,
  SingleStraight = 2,
  DoubleInnerCorner = 3,
  SingleInnerCorner = 4,
  OuterCorner = 5,
  DoubleSplitCorner = 6,
  DoubleSplitCornerMirror = 7,
  SquareCorner = 8,
  SquareEnd = 9,
  Door = 10
};

class Tile: public Sprite {
  public:
    Tile();
    Tile(int x, int y, TileType type, Rotation rot);
    void update(unsigned int frame);
};

#endif // FEHPACMAN_TILE_H