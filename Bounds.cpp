//
// Created by Kirk Brauer on 11/21/19.
//

#include "Bounds.h"

Bounds::Bounds(Position *pos, Size *s) { 
  size = s;
  position = pos;
}

unsigned int Bounds::get_x() {
  return position->x;
}

unsigned int Bounds::get_y() {
  return position->y;
}

unsigned int Bounds::get_max_x() {
  return position->x + size->width;
}

unsigned int Bounds::get_max_y() {
  return position->y + size->height;
}