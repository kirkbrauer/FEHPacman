//
// Created by Kirk Brauer on 12/02/19.
//

#ifndef FEHPACMAN_TILE_H
#define FEHPACMAN_TILE_H

#include "Sprite.h"

#define TILE_SIZE 8
#define TILE_FRAME_COUNT 11

// Represents the tile type
enum TileType {
  None = 0,
  DoubleStraight = 1,
  SingleStraight = 2,
  DoubleInnerCorner = 3,
  SingleInnerCorner = 4,
  OuterCorner = 5,
  SquareCorner = 6
};

/**
 * A sprite for each tile of the map.
 */
class Tile: public Sprite {
  public:
    // Default constructor
    Tile();
    /**
     * The primary Tile constructor.
     * @param x The x position of the tile.
     * @param y The y position of the tile.
     */
    Tile(int x, int y, TileType type, Rotation rot);
    // Updates the tile each frame
    void update(unsigned int frame);
};

#endif // FEHPACMAN_TILE_H