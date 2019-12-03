#ifndef FEHGAMECLASSES_COLLIDER_H
#define FEHGAMECLASSES_COLLIDER_H

#include "Size.h"

class Collider {
private:
  const int *map;
  Size size;
public:
  Collider();
  Collider(const int *map, int width, int height);
  bool at_intersection(int x, int y);
  bool can_go_north(int x, int y);
  bool can_go_south(int x, int y);
  bool can_go_east(int x, int y);
  bool can_go_west(int x, int y);
};

#endif