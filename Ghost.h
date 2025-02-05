//
// Created by Brian Duffy on 12/02/19.
//

#ifndef FEHPACMAN_GHOST_H
#define FEHPACMAN_GHOST_H

#include "Sprite.h"
#include "Collider.h"
#include "Direction.h"
#include "Player.h"

// Sizes for array of pixels in bitmap
#define GHOST_SIZE 16
#define GHOST_FRAME_COUNT 2

// Current Mode Ghost is In (Unused)
enum GhostMode {
  Chase,
  Hide
};

/**
 * Represents a Ghost enemy.
 */
class Ghost : public Sprite {
private:
  // The current ghost mode
  enum GhostMode mode;
  // The time that the mode started
  unsigned int modeTime;
  // If the ghost is alive
  bool alive;
  // The ghost collider
  Collider *coll;
  // The ghost direction
  enum Direction dir;
  // A pointer to the player
  Player *p;
public:
  // Default constructor
  Ghost();
  /**
   * The primary Ghost constructor.
   * @param coll The collider.
   * @param player A pointer to the player.
   * @param x The x position of the ghost.
   * @param y The y position of the ghost.
   */
  Ghost(Collider *collider, Player *player, int x, int y);
  /**
   * The primary Ghost constructor.
   * @param coll The collider.
   * @param player A pointer to the player.
   * @param pos The ghost position.
   */
  Ghost(Collider *collider, Player *player, Position pos);
  // Sets the ghost mode
  void set_mode(GhostMode mode);
  // Gets the ghost mode
  GhostMode get_mode();
  // Updates the ghost every frame
  void update(unsigned int frame);
  // Returns if the ghost is alive
  bool is_alive();
  // Kills the ghost
  void kill();
  // Renders the ghost
  void render();
  /**
   * Calculates the distance to the player.
   * @param xOff The x offset.
   * @param yOff The y offset.
   */
  float distanceToPlayer(int xOff, int yOff);
};

#endif // FEHPACMAN_GHOST_H