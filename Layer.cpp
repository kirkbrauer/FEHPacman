//
// Created by Kirk Brauer on 11/22/19.
//

#include "Layer.h"

Layer::Layer(Entity *e, unsigned int c) {
  entities = e;
  count = c;
}

void Layer::update(unsigned int time) {
  for (int i = 0; i < count; i++) {
    entities[i].update(time);
  }
}

void Layer::render() {
  for (int i = 0; i < count; i++) {
    entities[i].render();
  }
}