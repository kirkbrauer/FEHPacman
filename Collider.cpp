#include "Collider.h"

Collider::Collider() {}

Collider::Collider(int *m, int width, int height) {
  map = m;
  size = Size { width, height };
}

bool Collider::at_intersection(int x, int y) {
  return x % 8 == 0 && y % 8 == 0;
}

bool Collider::can_go_north(int x, int y) {
  return y > 0 && map[x*(y-1)];
}

bool Collider::can_go_south(int x, int y) {
  return y < size.height && map[x*(y+1)];
}

bool Collider::can_go_east(int x, int y) {
  return x < size.width && map[(x+1)*y];
}

bool Collider::can_go_west(int x, int y) {
  return x > 0 && map[(x-1)*y];
}