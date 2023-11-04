#include "raylib.h"
#include "atom.h"

int main() {
    InitGame();

    while (!WindowShouldClose()) {

        UpdateGame();
        DrawGame();
    }

    CloseWindow();

    return 0;
}
