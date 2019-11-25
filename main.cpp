#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include "Sprite.h"
#include "Player.h"

int main() {

    float x, y;

    LCD.Clear(FEHLCD::Black);
    LCD.SetFontColor(FEHLCD::White);

    Player player(5, 0, 1);

    unsigned int frame = 0;

    while (!LCD.Touch(&x, &y)) {}

    while(true) {
        player.move(East);
        player.update(frame);
        player.render();
        Sleep(30);
        frame++;
    }
    return 0;
}