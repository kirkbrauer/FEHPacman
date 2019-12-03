#include "Collider.h"

Collider::Collider() {}

Collider::Collider(unsigned int *m, unsigned int bs, int width, int height) {
  map = m;
  block_size = bs;
  size = Size { width, height };
}

bool Collider::at_intersection(int x, int y) {
  return x % 8 == 0 && y % 8 == 0;
}

bool Collider::can_go_north(int x, int y) {
  return y > 0 && map[(x/block_size) + (y/block_size-1) * size.width];
}

bool Collider::can_go_south(int x, int y) {
  return y < size.height*block_size && map[(x/block_size) + ((y/block_size)+1) * size.width];
}

bool Collider::can_go_east(int x, int y) {
  return x < size.width*block_size && map[(x/block_size) + (y/block_size) * size.width];
  
}

bool Collider::can_go_west(int x, int y) {
  return x > 0 && map[((x/block_size) - 1) + (y/block_size) * size.width];
}