#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHBuzzer.h>
#include <FEHUtility.h>
#include "Sprite.h"
#include "Player.h"

int main() {

    float x, y;

    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::White);

    Player player(5, 0, 1);
    enum Direction dir = East;

    unsigned int frame = 0;

    while (!LCD.Touch(&x, &y)) {}

    while(true) {
        // LCD.ClearBuffer();
        if (LCD.Touch(&x, &y)) {
            LCD.SetFontColor(WHITE);
            if (y < 90) {
                dir = North;
            } else if (y > 160) {
                dir = South;
            } else if (x < 100) {
                dir = West;
            } else if (x > 200) {
                dir = East;
            }
        }
        player.move(dir);
        player.update(frame);
        player.render();
        Buzzer.Buzz(15);
        frame++;
    }
    return 0;
}