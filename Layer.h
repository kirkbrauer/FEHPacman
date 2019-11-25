//
// Created by Kirk Brauer on 11/22/19.
//

#ifndef FEHGAMECLASSES_LAYER_H
#define FEHGAMECLASSES_LAYER_H

#include "Entity.h"

class Layer: public Entity {
  private:
    Entity *entities;
    unsigned int count;
  public:
    Layer(Entity *entities, unsigned int count);
    void update(unsigned int time);
    void render();
};


#endif //FEHGAMECLASSES_LAYER_H
