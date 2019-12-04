//
// Created by Kirk Brauer on 11/22/19.
//

#ifndef FEHPACMAN_PLAYER_H
#define FEHPACMAN_PLAYER_H

#include "Sprite.h"
#include "Direction.h"
#include "Collider.h"

#define PLAYER_SIZE 16
#define PLAYER_FRAME_COUNT 4

class Player: public Sprite {
  private:
    // The direction the player is facing
    Direction direction;
    // The player score
    int score;
    // Is the player dead
    bool dead;
    // Is the player moving
    bool moving;
    // The last animation frame
    unsigned int last_anim_frame;
    // The current move animation frame
    unsigned int move_anim_frame;
    // The direction of the animation
    int move_anim_direction;
    // The player collider
    Collider *coll;
  public:
    /**
     * The primary Player constructor.
     * @param coll The player collider
     * @param x The x position.
     * @param y The y position.
     */
    Player(Collider *coll, int x, int y);
    // Updates the player each frame
    void update(unsigned int frame);
    // Moves the player in a direction
    void move(Direction dir);
    // Returns the player score
    int getScore();
    // Sets the player score
    void setScore(int s);
    // Stops the player move animation
    void stop();
    // Renders the player
    void render();
};


#endif //FEHPACMAN_PLAYER_H
