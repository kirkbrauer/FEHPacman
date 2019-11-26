//
// Created by Kirk Brauer on 11/21/19.
//

#ifndef FEHGAMECLASSES_BOUNDS_H
#define FEHGAMECLASSES_BOUNDS_H


#include "Position.h"
#include "Size.h"

class Bounds {
  private:
    Position *position;
    Size *size;
  public:
    Bounds(): position(), size() {};
    Bounds(Position *position, Size *size);
    unsigned int get_x();
    unsigned int get_y();
    unsigned int get_max_x();
    unsigned int get_max_y();
};


#endif //FEHGAMECLASSES_BOUNDS_H
