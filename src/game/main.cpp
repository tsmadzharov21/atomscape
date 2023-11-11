#include "raylib.h"
#include "atom.h"
#include <iostream>


void startGame() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Game Lobby");

    int selectedOption = 0;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_DOWN)) {
            selectedOption = (selectedOption + 1) % 2;
        }
        else if (IsKeyPressed(KEY_UP)) {
            selectedOption = (selectedOption - 1 + 2) % 2;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            if (selectedOption != 0) {
                InitGame();
                CloseWindow();
            }
            else {
                CloseWindow();
                break;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the lobby options
        DrawText("Play Game", screenWidth / 2 - 100, screenHeight / 2 - 30, 30, (selectedOption == 0) ? RED : DARKGRAY);
        DrawText("Quit", screenWidth / 2 - 100, screenHeight / 2 + 30, 30, (selectedOption == 1) ? RED : DARKGRAY);

        EndDrawing();
    }
}
int main() 
{
    startGame();

    while (!WindowShouldClose()) {

        UpdateGame();
        DrawGame();
        
    }

    CloseWindow();

    return 0;
}
