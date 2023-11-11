#include "atom.h"

int main() 
{
    Init();
    mainMenu();

    while (!WindowShouldClose()) {
        if (isGameOver && IsKeyPressed(KEY_ENTER))
        {
            RestartGame();
        }
        UpdateGame();
        DrawGame();
        
    }

    CloseWindow();

    return 0;
}
