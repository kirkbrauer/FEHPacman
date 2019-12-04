//
// Created by Brian Duffy on 12/03/19.
//

#ifndef FEHPACMAN_COLLIDER_H
#define FEHPACMAN_COLLIDER_H

#include "Size.h"

// Singleton class for objects that need to collide with the world
class Collider {
private:
  // Array of ints where 0 is wall and 1 is open
  unsigned int *map;
  // Size of each block
  unsigned int block_size;
  // Size of Array
  Size size;
public:
  // Default constructor
  Collider();
  /**
   * Collider constructor.
   * @param map The integer-defined map of possible paths.
   * @param block_size The size of each block in the map.
   * @param width The width of the map.
   * @param height The height of the map.
   */
  Collider(unsigned int *map, unsigned int block_size, int width, int height);
  // Wether the supplied coordinates are at an intersection
  bool at_intersection(int x, int y);
  // Functions to check if we can move in a specific direction
  bool can_go_north(int x, int y);
  bool can_go_south(int x, int y);
  bool can_go_east(int x, int y);
  bool can_go_west(int x, int y);
};

#endif