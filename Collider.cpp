#include "Collider.h"

Collider::Collider(bool **map, int xSiz, int ySiz) : map(map), xSiz(xSiz), ySiz(ySiz) {}

bool Collider::atIntersection(int x, int y) {
  return x % 8 == 0 && y % 8 == 0;
}

bool Collider::canGoNorth(int x, int y) {
  return y > 0 && map[x][y-1];
}

bool Collider::canGoSouth(int x, int y) {
  return y < ySiz && map[x][y+1];
}

bool Collider::canGoEast(int x, int y) {
  return x < xSiz && map[x+1][y];
  
}

bool Collider::canGoWest(int x, int y) {
  return x > 0 && map[x-1][y];
}