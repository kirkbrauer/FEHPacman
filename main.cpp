#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <stdlib.h>
#include <stdio.h>
#include "Sprite.h"
#include "Player.h"
#include "Dot.h"
#include "Tile.h"
#include "Ghost.h"

#define FG_COUNT 5
#define DG_COUNT 754
#define MAP_WIDTH 28
#define MAP_HEIGHT 31
#define GHOST_COUNT 4
#define HIGHSCORE_COUNT 5
#define GHOST_HIDE_DURATION 500

void game();
void dispHighScores();
void gameOver(int, bool);

unsigned int dot_data[MAP_WIDTH*MAP_HEIGHT] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,
  0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
  0,2,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,2,0,
  0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
  0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
  0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
  0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
  0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,
  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
  1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,
  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
  0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,
  0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
  0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
  0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,
  0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,
  0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,
  0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,
  0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
  0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
  0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

unsigned int path_data[MAP_WIDTH*MAP_HEIGHT] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,
  0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
  0,2,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,2,0,
  0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
  0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
  0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
  0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
  0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,
  0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
  0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,
  0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
  0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
  0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,
  0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
  0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
  0,2,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,2,0,
  0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,
  0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,
  0,1,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,1,1,0,
  0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
  0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
  0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

unsigned int map[MAP_WIDTH*MAP_HEIGHT] = {
    33,10,10,10,10,10,10,10,10,10,10,10,10,40,43,10,10,10,10,10,10,10,10,10,10,10,10,30,
    13,00,00,00,00,00,00,00,00,00,00,00,00,23,21,00,00,00,00,00,00,00,00,00,00,00,00,11,
    13,00,53,20,20,50,00,53,20,20,20,50,00,23,21,00,53,20,20,20,50,00,53,20,20,50,00,11,
    13,00,23,00,00,21,00,23,00,00,00,21,00,23,21,00,21,00,00,00,23,00,23,00,00,21,00,11,
    13,00,52,22,22,51,00,52,22,22,22,51,00,52,51,00,52,22,22,22,51,00,52,22,22,51,00,11,
    13,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,11,
    13,00,53,20,20,50,00,53,50,00,53,20,20,20,20,20,20,50,00,53,50,00,53,20,20,50,00,11,
    13,00,52,22,22,51,00,23,21,00,52,22,22,40,43,22,22,51,00,23,21,00,52,22,22,51,00,11,
    13,00,00,00,00,00,00,23,21,00,00,00,00,23,21,00,00,00,00,23,21,00,00,00,00,00,00,11,
    32,12,12,12,12,50,00,23,42,20,20,50,00,23,21,00,53,20,20,41,21,00,53,12,12,12,12,31,
    00,00,00,00,00,13,00,23,43,22,22,51,00,52,51,00,52,22,22,40,21,00,11,00,00,00,00,00,
    00,00,00,00,00,13,00,23,21,00,00,00,00,00,00,00,00,00,00,23,21,00,11,00,00,00,00,00,
    00,00,00,00,00,13,00,23,21,00,63,12,12,00,00,12,12,60,00,23,21,00,11,00,00,00,00,00,
    10,10,10,10,10,51,00,52,51,00,11,00,00,00,00,00,00,13,00,52,51,00,52,10,10,10,10,10,
    00,00,00,00,00,00,00,00,00,00,11,00,00,00,00,00,00,13,00,00,00,00,00,00,00,00,00,00,
    12,12,12,12,12,50,00,53,50,00,11,00,00,00,00,00,00,13,00,53,50,00,53,12,12,12,12,12,
    00,00,00,00,00,13,00,23,21,00,62,10,10,10,10,10,10,61,00,23,21,00,11,00,00,00,00,00,
    00,00,00,00,00,13,00,23,21,00,00,00,00,00,00,00,00,00,00,23,21,00,11,00,00,00,00,00,
    00,00,00,00,00,13,00,23,21,00,53,20,20,20,20,20,20,50,00,23,21,00,11,00,00,00,00,00,
    33,10,10,10,10,51,00,52,51,00,52,22,22,40,43,22,22,51,00,52,51,00,52,10,10,10,10,30,
    13,00,00,00,00,00,00,00,00,00,00,00,00,23,21,00,00,00,00,00,00,00,00,00,00,00,00,11,
    13,00,53,20,20,50,00,53,20,20,20,50,00,23,21,00,53,20,20,20,50,00,53,20,20,50,00,11,
    13,00,52,22,40,21,00,52,22,22,22,51,00,52,51,00,52,22,22,22,51,00,23,43,22,51,00,11,
    13,00,00,00,23,21,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,23,21,00,00,00,11,
    42,20,50,00,23,21,00,53,50,00,53,20,20,20,20,20,20,50,00,53,50,00,23,21,00,53,20,41,
    43,22,51,00,52,51,00,23,21,00,52,22,22,40,43,22,22,51,00,23,21,00,52,51,00,52,22,40,
    13,00,00,00,00,00,00,23,21,00,00,00,00,23,21,00,00,00,00,23,21,00,00,00,00,00,00,11,
    13,00,53,20,20,20,20,41,42,20,20,50,00,23,21,00,53,20,20,41,42,20,20,20,20,50,00,11,
    13,00,52,22,22,22,22,22,22,22,22,51,00,52,51,00,52,22,22,22,22,22,22,22,22,51,00,11,
    13,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,11,
    32,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,31,
};

float lcdX, lcdY;

int main() {
  LCD.Clear(FEHLCD::Black);
  LCD.SetFontColor(FEHLCD::White);
  LCD.SetOrientation(FEHLCD::East);

  while (!LCD.Touch(&lcdX, &lcdY));

  game();
  
  return 0;
}

void game() {
  // Prepare Screen
  LCD.Clear(FEHLCD::Black);
  LCD.SetFontColor(FEHLCD::White);
  LCD.SetOrientation(FEHLCD::East);

  // Player Direction
  enum Direction dir = East; 

  // Main game collider
  Collider paths(path_data, 8, MAP_WIDTH, MAP_HEIGHT);

  // Instantiations for Graphics
  bool big = false;
  Dot dot;
  Tile tile;

  int x, y;

  // Moving Entities
  Player player(&paths, 8, 8);
  Ghost ghosts[GHOST_COUNT];
  
  // TODO : Give Real Positions on Grid
  ghosts[0] = Ghost(&paths, &player, 56, 56);
  ghosts[1] = Ghost(&paths, &player, 32, 16);
  ghosts[2] = Ghost(&paths, &player, 16, 32);
  ghosts[3] = Ghost(&paths, &player, 32, 32);

  // Current frame number
  unsigned long long frame = 0;
  unsigned long long hide_start = 0;

  Position *player_pos;
  Position *ghost_pos;

  // Build walls
  for (int x = 0; x < MAP_WIDTH; x++) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
      unsigned int block = map[y*MAP_WIDTH + x];
      TileType type = TileType(block / 10 % 10);
      Rotation rot;
      unsigned int rotate = block % 10;
      switch (rotate) {
        case 0:
          rot = Deg0;
          break;
        case 1:
          rot = Deg90;
          break;
        case 2:
          rot = Deg180;
          break;
        case 3:
          rot = Deg270;
          break;
        default:
          rot = Deg0;
      }
      tile = Tile(x*8+4, y*8+4, type, rot);
      tile.render();
    }
  }

  // Initially render Dots
  for (int x = 0; x < MAP_WIDTH; x++) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
      if (dot_data[y*MAP_WIDTH + x] != 0) {
        big = dot_data[y*MAP_WIDTH + x] == 2;
        dot = Dot(x*8+4, y*8+4, big);
        dot.render();
      }
    }
  }

  // Dots eaten by the player
  int dotsEaten = 0;
  int ghostsAlive = GHOST_COUNT;

  // Main game loop
  while (true) {
    // Choose Direction for Player
    if (LCD.Touch(&lcdX, &lcdY)) {
      if (y < 90) {
        dir = West;
      } else if (y > 160) {
        dir = East;
      } else if (x < 100) {
        dir = South;
      } else if (x > 200) {
        dir = North;
      }
    }

    // Move Player
    player.move(dir);
    player.update(frame);
    player.render();
    
    // Check if player eats a dot
    Position *p = player.get_position();
    if (paths.at_intersection(p->x, p->y)) {
      // Player over dot
      if (dot_data[p->x/8+p->y/8*MAP_WIDTH] != 0) {
        // Check if the dot was a powerup
        if (dot_data[p->x/8+p->y/8*MAP_WIDTH] == 2) {
          // Make the ghosts attempt to hide
          for (int i = 0; i < GHOST_COUNT; i++) {
            ghosts[i].set_mode(Hide);
          }
          // Set the time when the ghosts started hiding
          hide_start = frame;
        }
        dot_data[p->x/8+p->y/8*MAP_WIDTH] = 0;
        // Increase Score
        player.setScore(player.getScore() + 100);
        // Count the dots that have been eaten
        dotsEaten++;
      }
    }

    // For each ghost in the game
    for (int i = 0; i < 4; i++) {
      // Only render and update ghosts that are alive
      if (ghosts[i].is_alive()) {
        // Update the ghost position
        if (!(frame % 10 == 0)) {
          ghosts[i].update(frame);
        }
        // Check if ghost kills player
        if (ghosts[i].distanceToPlayer(0, 0) < 8) {
          if (ghosts[i].get_mode() == Hide) {
            // Kill the ghost
            ghosts[i].kill();
            // Reduce the number of ghosts alive
            ghostsAlive--;
            // Update the player score
            player.setScore(player.getScore() + 500);
          } else {
            // Ghost kills player
            gameOver(player.getScore(), false);
            break;
          }
        }

        Position *p = ghosts[i].get_position();
        // Replace Clobbered Dots
        if (paths.at_intersection(p->x, p->y)) {
          // Place dots on each side
          for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
              // Bounds Checking
              if ((p->x+j)/8+(p->y+k)/8*MAP_WIDTH < 0 || (p->x+j)/8+(p->y+k)/8*MAP_WIDTH > MAP_WIDTH*MAP_HEIGHT)
                continue;
              // Draw dot if it exists
              if (dot_data[(p->x+j)/8+(p->y+k)/8*MAP_WIDTH] != 0) {
                // Draw a big dot if big is specified
                big = dot_data[(p->x+j)/8+(p->y+k)/8*MAP_WIDTH] == 2;
                // Construct a new dot
                dot = Dot(x*8+4, y*8+4, big);
                // Render the dot
                dot.render();
              }
            }
          }
          // Render the ghost
          ghosts[i].render();
        }
      }
    }

    // Check if any dots left
    if (dotsEaten >= 258) {
      gameOver(player.getScore(), true);
      break;
    }

    // Check if any ghosts are left alive
    if (ghostsAlive == 0) {
      gameOver(player.getScore(), true);
      break;
    }

    // Stop the ghosts from hiding after a specific duration
    if (frame - hide_start > GHOST_HIDE_DURATION) {
      for (int i = 0; i < GHOST_COUNT; i++) {
        // Set the ghost modes to chase
        ghosts[i].set_mode(Chase);
      }
    }

    // For each ghost in the game
    for (int i = 0; i < GHOST_COUNT; i++) {
      
    }

    // Score tracking
    LCD.WriteAt("Score: ", 10, 280);
    LCD.WriteAt(player.getScore(), 20, 290);

    // Each frame delayed 15ms
    frame++;
    Sleep(15);
  }
}

// Charset for scores
char charset[] = {"_ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
struct score {
  char initals[3]; // Offsets into charset
  int score;
};
struct score highScores[HIGHSCORE_COUNT];

void dispHighScores() {
  // Disply Header
  LCD.Clear();
  LCD.WriteRC("High Scores:", 1, 1);

  // For Each Score
  for (int i = 0; i < 10; i++) {
    // Exit if found last score
    if (highScores[i].score == 0) {
      break;
    }
    // Write initals
    for (int j = 0; j < 3; j++) {
      LCD.WriteRC(charset[highScores[i].initals[j]], 1 + j, 2 + i);
    }
    // Write score
    LCD.WriteRC(highScores[i].score, 5, 2 + i);
  }

  // Return to menu
  LCD.WriteAt("Click anywhere to go back...", 0, 0);
  Sleep(100);
  do {} while (!LCD.Touch(&lcdX, &lcdY));
}

void gameOver(int score, bool win) {
  int x, y;
  // Page Header
  LCD.Clear();
  char buf[30];
  sprintf(buf, "You %s!", win ? "won" : "lost");
  LCD.WriteRC(buf, 2, 2);
  LCD.WriteRC("Enter your initials...", 3, 2);

  // Get User initials
  int curChar = 0;
  struct score scr = {{0,0,0}, score};
  while (true) {
    // Write Characters
    LCD.WriteRC(charset[scr.initals[0]], 4, 4);
    LCD.WriteRC(charset[scr.initals[1]], 4, 6);
    LCD.WriteRC(charset[scr.initals[2]], 4, 8);
    if (LCD.Touch(&lcdX, &lcdY)) {
      if (y < 90) {
        // Increase Character
        scr.initals[curChar]++;
        // Check Bounds
        if (scr.initals[curChar] >= sizeof(charset))
          scr.initals[curChar] = 0;
      } else if (y > 160) {
        // Decrease Character
        scr.initals[curChar]--;
        // Check Bounds
        if (scr.initals[curChar] < 0)
          scr.initals[curChar] = sizeof(charset)-2;
      } else if (x < 100) {
        // Back one Character
        if (curChar = 0)
          curChar = 2;
        else
          curChar--;
      } else if (x > 200) {
        // Next Character
        if (curChar = 2)
          curChar = 0;
        else
          curChar++;
      } else {
        // Finished Entering
        break;
      }
    }

    // Insert into high score array
    for (int i = 0; i < 5; i++) {
      // If at end, insert
      if (highScores[i].score == 0) {
        highScores[i] = scr;
        break;
      }
      // Insertion Sort into List
      if (scr.score > highScores[i].score) {
        struct score temp = highScores[i];
        highScores[i] = scr;
        scr = temp;
      }
    }
  }
}