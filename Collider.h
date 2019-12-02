#ifndef FEHGAMECLASSES_COLLIDER_H
#define FEHGAMECLASSES_COLLIDER_H

class Collider {
private:
  bool **map;
  int xSiz, ySiz;
public:
  Collider(bool **map, int xSiz, int ySiz);
  bool atIntersection(int x, int y);
  bool canGoNorth(int x, int y);
  bool canGoSouth(int x, int y);
  bool canGoEast(int x, int y);
  bool canGoWest(int x, int y);
};

#endif