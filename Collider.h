#ifndef FEHPACMAN_COLLIDER_H
#define FEHPACMAN_COLLIDER_H

#include "Size.h"

class Collider {
private:
  unsigned int *map;
  unsigned int block_size;
  Size size;
public:
  Collider();
  Collider(unsigned int *map, unsigned int block_size, int width, int height);
  bool at_intersection(int x, int y);
  bool can_go_north(int x, int y);
  bool can_go_south(int x, int y);
  bool can_go_east(int x, int y);
  bool can_go_west(int x, int y);
};

#endif