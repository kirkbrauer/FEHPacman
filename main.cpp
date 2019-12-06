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
void dispInstructions();
void gameOver(int, bool);

// Charset for scores
char charset[] = {"_ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
struct score {
  char initals[3]; // Offsets into charset
  int score;
};
score highScores[HIGHSCORE_COUNT];

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
int wins = 0;
int losses = 0;
float scoreTot = 0;

int main() {
  LCD.Clear(FEHLCD::Black);
  LCD.SetFontColor(FEHLCD::White);
  LCD.SetOrientation(FEHLCD::East);

  for (int i = 0; i < 5; i++) {
    highScores[i] = {{'\0', '\0', '\0'}, 0};
  }

  while (true) {
    LCD.Clear();
    LCD.SetFontColor(FEHLCD::White);
    LCD.WriteLine("FEHPacman");
    LCD.WriteLine("");
    LCD.WriteLine(" 1. Play Game");
    LCD.WriteLine(" 2. View Scoreboard");
    LCD.WriteLine(" 3. Instructions");
    LCD.WriteLine(" 4. Exit");

    while (!LCD.Touch(&lcdX, &lcdY));
    if (lcdX > 281 && lcdX < 291 && lcdY > 22 && lcdY < 224) {
      game();
    } else if (lcdX > 263 && lcdX < 273 && lcdY > 21 && lcdY < 226) {
      dispHighScores();
    } else if (lcdX > 246 && lcdX < 258 && lcdY > 22 && lcdY < 228) {
      dispInstructions();
    } else if (lcdX > 225 && lcdX < 241 && lcdY > 21 && lcdY < 225) {
      break;
    }
  }
  
  return 0;
}

void game() {
  bool exitLoop = false;

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
  ghosts[0] = Ghost(&paths, &player, 56, 48);
  ghosts[1] = Ghost(&paths, &player, 168, 48);
  ghosts[2] = Ghost(&paths, &player, 56, 128);
  ghosts[3] = Ghost(&paths, &player, 168, 128);

  // Current frame number
  unsigned long long frame = 0;
  unsigned long long hide_start = 0;

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
      if (lcdY < 90) {
        dir = West;
      } else if (lcdY > 160) {
        dir = East;
      } else if (lcdX < 100) {
        dir = South;
      } else if (lcdX > 200) {
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
        ghosts[i].update(frame);
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
            return;
          }
        }

        Position *p = ghosts[i].get_position();
        // Replace Clobbered Dots
        if (paths.at_intersection(p->x, p->y)) {
          // Place dots on each side
          for (int j = -2; j <= 2; j++) {
            for (int k = -2; k <= 2; k++) {
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
        }
        // Render the ghost
        ghosts[i].render();
      }
    }

    // Check if any dots left
    if (dotsEaten >= 258) {
      gameOver(player.getScore(), true);
      return;
    }

    // Check if any ghosts are left alive
    if (ghostsAlive == 0) {
      gameOver(player.getScore(), true);
      return;
    }

    // Stop the ghosts from hiding after a specific duration
    if (frame - hide_start > GHOST_HIDE_DURATION) {
      for (int i = 0; i < GHOST_COUNT; i++) {
        // Set the ghost modes to chase
        ghosts[i].set_mode(Chase);
      }
    }

    // Score tracking
    LCD.SetFontColor(WHITE);
    LCD.WriteAt("Score: ", 10, 280);
    LCD.WriteAt(player.getScore(), 150, 280);

    // Each frame delayed 15ms
    frame++;
    Sleep(2);
  }
}

void dispHighScores() {
  // Disply Header
  LCD.Clear();
  LCD.WriteLine("Statistics:");

  LCD.Write("Wins: ");
  LCD.WriteLine(wins);
  LCD.Write("Losses: ");
  LCD.WriteLine(losses);
  LCD.Write("Average Points: ");
  if (wins+losses == 0) {
    LCD.WriteLine("0.0");
  } else {
    LCD.WriteLine(scoreTot / (wins+losses));
  }

  // Return to menu
  LCD.WriteLine("Click anywhere to go back...");
  Sleep(100);
  do {} while (!LCD.Touch(&lcdX, &lcdY));
}

void dispInstructions() {
  LCD.Clear();
  LCD.SetFontColor(WHITE);

  LCD.WriteLine("Instructions:");
  LCD.WriteLine(" 1. Click start Game");
  LCD.WriteLine(" 2. Click sides of screen to change direction");
  LCD.WriteLine(" 3. Eat pellets, avoid ghosts");
  LCD.WriteLine(" 4. Eat power pellet to eat ghosts");
  LCD.WriteLine("");

  // Return to menu
  LCD.WriteLine("Click anywhere to go back...");
  Sleep(100);
  do {} while (!LCD.Touch(&lcdX, &lcdY));
}

void gameOver(int score, bool win) {
  scoreTot += score;
  win ? wins++ : losses++;
}