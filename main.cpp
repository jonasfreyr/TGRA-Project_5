#include <iostream>
#include "Core/boiler.h"
#include "Core/matrix.h"
#include "Core/vector3.h"
#include "Game/game.h"

int main() {
    Game g = Game();
    Clock c = Clock();

    if (g.init()) return -1;
    while (g.running){
        g.Events();
        g.Update(c.Tick());
        g.Display();
    }

    return 0;
}
