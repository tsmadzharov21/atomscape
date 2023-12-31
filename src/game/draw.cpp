#include "atom.h"

void DrawGame() {
    // Implementation of DrawGame
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTextureEx(background, { 0,0 }, 0, 0.93567, WHITE);

    for (size_t i = 0; i < pellets.size(); i++)
    {
        if (!isPelletEaten[i])
        {
            if (i == 9)
            {
                DrawTextureEx(palletsTexture, { pellets[i].x,pellets[i].y }, 0, 0.15, BLUE);
            }
            else
            {
                DrawTextureEx(palletsTexture, { pellets[i].x,pellets[i].y }, 0, 0.15, WHITE);
            }
        }
    }

    for (size_t i = 0; i < enemyPositions.size(); i++)
    {
        DrawTextureEx(enemyTexture,enemyPositions[i], 0,0.004*enemyGridSize, WHITE);
    }

    DrawTextureEx(playerTexture, atomPosition, 0, 0.15, WHITE);
    //DrawCircle(atomPosition.x + gridSize / 4, atomPosition.y - gridSize / 4, 5, BLACK);

    if (isLevelCompleted)
    {
        DrawText("Level completed!", screenWidth / 2 - MeasureText("Level completed!", 30) / 2, screenHeight / 2 - 15, 30, GREEN);
        DrawText("Press Enter to Start Next Level", screenWidth / 2 - 200, screenHeight / 2 + 50, 20, DARKGRAY);

        atomSpeed += 0.03;
    }
    else if (isGameOver)
    {
        DrawText("Game Over!", screenWidth / 2 - 100, screenHeight / 2 - 50, 30, WHITE);
        DrawText("Press Enter to Restart", screenWidth / 2 - 150, screenHeight / 2 + 50, 20, WHITE);
    }

    EndDrawing();
}
