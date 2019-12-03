//
// Created by Brian Duffy on 12/02/19.
//

#ifndef FEHPACMAN_GHOST_H
#define FEHPACMAN_GHOST_H

#include "Sprite.h"
#include "Collider.h"
#include "Direction.h"

#define GHOST_SIZE    16
#define NUM_GHOST     4

enum GhostMode {
  CHASE,
  HIDE
};

class Ghost : public Sprite {
private:
  enum GhostMode mode;
  unsigned int modeTime;
  bool alive;
  Collider coll;
  enum Direction dir;
public:
  Ghost(Collider coll, int ghost, int x, int y, int width, int height);
  Ghost(Collider coll, int ghost, Position pos, Size sz);
  void update(unsigned int frame);
  void move();
  void kill();
};

#endif // FEHPACMAN_GHOST_H