//
// Created by Kirk Brauer on 11/21/19.
//

#ifndef FEHPACMAN_ENTITY_H
#define FEHPACMAN_ENTITY_H


class Entity {
  public:
    virtual void update(unsigned int frame) = 0;
    virtual void render() = 0;
};


#endif //FEHPACMAN_ENTITY_H
