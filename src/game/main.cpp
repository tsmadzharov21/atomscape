#include "raylib.h"
#include "atom.h"
#include <iostream>

int main() {

    InitGame();

    while (!WindowShouldClose()) {

        UpdateGame();
        DrawGame();
    }

    CloseWindow();

    return 0;
}
