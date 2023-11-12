#include "atom.h"


void mainMenu() {
    const int screenWidth = 1280;
    const int screenHeight = 720;


    int selectedOption = 0;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_DOWN)) {
            selectedOption = (selectedOption + 1) % 2;
        }
        else if (IsKeyPressed(KEY_UP)) {
            selectedOption = (selectedOption - 1 + 2) % 2;
        }


        if (IsKeyPressed(KEY_ENTER)) {
            if (selectedOption == 0) {
                return;
            }
            else {
                CloseWindow();
                exit(1);
            }
        }

        BeginDrawing();
        DrawTextureEx(menuTexture, { 0,0 }, 0, 0.7, WHITE);

        // Draw the lobby options
        DrawText("Play Game", screenWidth / 2 - 100, screenHeight / 2 - 30, 30, (selectedOption == 0) ? RED : DARKGRAY);
        DrawText("Quit", screenWidth / 2 - 100, screenHeight / 2 + 30, 30, (selectedOption == 1) ? RED : DARKGRAY);

        EndDrawing();
    }
}