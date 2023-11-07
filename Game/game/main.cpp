#include "raylib.h"
#include "atom.h"
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>

int main() {


    PlaySound(TEXT("1107.wav"), NULL, SND_FILENAME | SND_SYNC);
    return 0;

    InitGame();

    while (!WindowShouldClose()) {

        UpdateGame();
        DrawGame();
    }

    CloseWindow();

    return 0;
}
