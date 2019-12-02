#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <stdlib.h>
#include "Sprite.h"
#include "Player.h"
#include "Dot.h"

#define FG_COUNT 5
#define DG_COUNT 754

const int dot_data[28 * 31] = {
  0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,
  0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
  0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
  0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,
  0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,
  0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,
};

int main() {

  float x, y;

  LCD.Clear(FEHLCD::Black);
  LCD.SetFontColor(FEHLCD::White);
  LCD.SetOrientation(FEHLCD::East);

  enum Direction dir = East; // Player Direction

  Dot dgents[DG_COUNT];

  int di = 0;
  bool big = false;
  bool make_dot = true;
  Dot dot;

  for (int x = 1; x < 27; x++) {
    for (int y = 1; y < 30; y++) {
      big = false;
      make_dot = true;
      if (y == 3 || y == 23) {
        if (x == 1 || x == 26) {
          big = true;
        }
      }
      if (y >= 2 && y <= 4) {
        if (x >= 2 && x <= 5 || x >= 7 && x <= 11 || x >= 16 && x <= 20 || x >= 22 && x <= 25 || x == 13 || x == 14) {
          make_dot = false;
        }
      }
      if (y == 6 || y == 7) {
        if (x >= 2 && x <= 5 || x == 7 || x == 8 || x >= 10 && x <= 17 || x == 19 || x == 20 || x >= 22 && x <= 25) {
          make_dot = false;
        }
      }
      if (make_dot) {
        dot = Dot(x*8, y*8, big);
        dgents[di] = dot;
        di++;
      }
    }
  }

  Player player(5, 0);

  unsigned int frame = 0;

  while (!LCD.Touch(&x, &y));

  for (int i = 0; i < DG_COUNT; i++) {
    dgents[i].render();
  }

  while (true) {

    // Choose Direction for Player
    if (LCD.Touch(&x, &y))
    {
      if (y < 90)
      {
        dir = West;
      }
      else if (y > 160)
      {
        dir = East;
      }
      else if (x < 100)
      {
        dir = South;
      }
      else if (x > 200)
      {
        dir = North;
      }
    }

    // Move Entities
    player.move(dir);
    player.update(frame);
    player.render();

    frame++;
    Sleep(15);
  }
  return 0;
}