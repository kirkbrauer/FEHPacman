//
// Created by Kirk Brauer on 11/22/19.
//

#include "Player.h"

// The player animation frames
unsigned int PLAYER_FRAMES[PLAYER_FRAME_COUNT*(PLAYER_SIZE*PLAYER_SIZE)] = {
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x666666,0x666666,0xbb0000,0x666666,0x666666,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0xbb0000,0xbb0000,0xbb0000,0x666666,0x666666,0x666666,0xbb0000,0xbb0000,0xbb0000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0xbb0000,0xbb0000,0xbb0000,0xbb0000,0xbb0000,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0xffffff,0xffffff,0xffffff,0xf4d2a4,0xffffff,0xffffff,0xffffff,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0xffffff,0x000000,0xffffff,0xf4d2a4,0xffffff,0x000000,0xffffff,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0xffffff,0xffffff,0xffffff,0xf4d2a4,0xffffff,0xffffff,0xffffff,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x000000,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0x000000,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x000000,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0x000000,0x000000,0x000000,0x000000,0x000000,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,

    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,

    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x80391d,0xf4d2a4,0x000000,0x000000,0x000000,0x000000,0x000000,0xf4d2a4,0x80391d,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0x000000,0x000000,0x000000,0x000000,0x000000,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x000000,0x000000,0x000000,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x000000,0x000000,0x000000,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x000000,0x000000,0x000000,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x000000,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x000000,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,

    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x80391d,0xf4d2a4,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xf4d2a4,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x000000,0x000000,0x000000,0x000000,0x000000,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x000000,0x000000,0x000000,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x80391d,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x000000,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x80391d,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0x80391d,0x80391d,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0xf4d2a4,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x80391d,0x80391d,0x80391d,0x80391d,0x80391d,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
    0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,0x000000,
};

Player::Player(Collider *c, int x, int y): Sprite(PLAYER_FRAMES, PLAYER_FRAME_COUNT, x, y, PLAYER_SIZE, PLAYER_SIZE, Deg0) {
  current_frame = 0;
  direction = East;
  dead = false;
  moving = false;
  move_anim_direction = 1;
  last_anim_frame = 0;
  move_anim_frame = 0;
  coll = c;
  score = 0;
}

void Player::update(unsigned int frame) {
  // Every two frames, change the animation frame
  if ((frame - last_anim_frame) >= 2) {
    // Update the last animation frame
    last_anim_frame = frame;
    // Add the animation direction to the animation frame
    move_anim_frame += move_anim_direction;
    if (move_anim_frame == 3) {
      // If we are at the last frame, switch direction
      move_anim_direction = -1;
    } else if (move_anim_frame == 1) {
      // If we are at the first frame, switch direction
      move_anim_direction = 1;
    }
  }
}

void Player::move(Direction dir) {
  // Allow the player to move if at an intersection
  if (coll->at_intersection(position.x, position.y)) {
    switch(dir) {
    case North:
      if (coll->can_go_north(position.x, position.y))
        direction = dir;
      break;
    case East:
      if (coll->can_go_east(position.x, position.y))
        direction = dir;
      break;
    case South:
      if (coll->can_go_south(position.x, position.y))
        direction = dir;
      break;
    case West:
      if (coll->can_go_west(position.x, position.y))
        direction = dir;
      break;
    }
  }
  // Set moving to true
  moving = true;
  switch  (direction) {
    case North:
      if (!(coll->at_intersection(position.x, position.y) && !coll->can_go_north(position.x, position.y)))
        position.y -= 1;
      break;
    case East:
      if (!(coll->at_intersection(position.x, position.y) && !coll->can_go_east(position.x, position.y)))
        position.x += 1;
      break;
    case South:
      if (!(coll->at_intersection(position.x, position.y) && !coll->can_go_south(position.x, position.y)))
        position.y += 1;
      break;
    case West:
      if (!(coll->at_intersection(position.x, position.y) && !coll->can_go_west(position.x, position.y)))
        position.x -= 1;
      break;
  }
}

void Player::stop() {
  moving = false;
}

void Player::render() {
  // Render the player
  if (moving) {
    current_frame = move_anim_frame;
    switch  (direction) {
      case North:
        rotation = Deg0;
        break;
      case East:
        rotation = Deg90;
        break;
      case South:
        rotation = Deg180;
        break;
      case West:
        rotation = Deg270;
        break;
    }
  } else {
    // Set the empty state if the player is not moving
    current_frame = 0;
  }
  // Render the sprite
  Sprite::render();
}

int Player::getScore() {
  return score;
}

void Player::setScore(int s) {
  score = s;
}