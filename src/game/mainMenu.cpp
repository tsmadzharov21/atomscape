#include "atom.h"
void storyline();

void mainMenu() {
    const int screenWidth = 1280;
    const int screenHeight = 720;


    int selectedOption = 0;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_DOWN)) {
            selectedOption = (selectedOption + 1) % 5;
        }
        else if (IsKeyPressed(KEY_UP)) {
            if (selectedOption == 0) {
                selectedOption = 4;
            }
            else {
                selectedOption = (selectedOption - 1) % 5;
            }
        }
        

        if (IsKeyPressed(KEY_ENTER)) {

            if (selectedOption == 1) {
                storyline();
            }
            else if (selectedOption == 2){
                exit(1);

            }
            else if (selectedOption == 3) {
                exit(1);  

            }
            else if (selectedOption == 4) {
                exit(1);

            }
            else {
                CloseWindow();
                exit(1);
            }
        }

        BeginDrawing();
        DrawTextureEx(menuTexture, { 0,0 }, 0, 0.69, WHITE);

        // Draw the lobby options
        DrawText("Play Game", screenWidth / 2 - 80, screenHeight / 2 - 100, 30, (selectedOption == 0) ? GREEN : WHITE);
        DrawText("Storyline", screenWidth / 2 - 80, screenHeight / 2 - 40, 30, (selectedOption == 1) ? GREEN : WHITE);
        DrawText("Rules", screenWidth / 2 - 80, screenHeight / 2 + 20, 30, (selectedOption == 2) ? GREEN : WHITE);
        DrawText("Credits", screenWidth / 2 - 80, screenHeight / 2 + 80, 30, (selectedOption == 3) ? GREEN : WHITE);
        DrawText("Quit", screenWidth / 2 - 80, screenHeight / 2 + 140, 30, (selectedOption == 4) ? GREEN : WHITE);


        EndDrawing();
    }
}