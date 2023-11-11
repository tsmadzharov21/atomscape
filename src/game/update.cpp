#include "atom.h"
void updatePlayer();
void updateEnemies();

void UpdateGame()
{
    // Implementation of UpdateGame
    if (isGameOver) {
        return;
    }
    if (IsKeyPressed(KEY_ENTER))
    {
        InitGame();
        isGameOver = false;
        isLevelCompleted = false;
        level = 1;
    }
    if (isLevelCompleted)
    {
        if (level < maxLevel)
        {
            level++;
            InitGame();
            isLevelCompleted = false;
        }
        else
        {
            isGameOver = true;
        }
    }
    updatePlayer();
    updateEnemies();


}
void updatePlayer() {
    // Move Atom 
    if (IsKeyDown(KEY_RIGHT) && atomPosition.x + atomSpeed + gridSize <= screenWidth)
    {
        atomPosition.x += atomSpeed;
    }
    if (IsKeyDown(KEY_LEFT) && atomPosition.x - atomSpeed >= 0)
    {
        atomPosition.x -= atomSpeed;
    }
    if (IsKeyDown(KEY_DOWN) and atomPosition.y + atomSpeed + gridSize <= screenHeight)
    {
        atomPosition.y += atomSpeed;
    }
    if (IsKeyDown(KEY_UP) && atomPosition.y - atomSpeed >= 0)
    {
        atomPosition.y -= atomSpeed;
    }
    

    for (size_t i = 0; i < pellets.size(); i++)
    {
        if (i == 9)
        {
            if (!isPelletEaten[i] && CheckCollisionCircleRec(atomPosition, gridSize / 2, pellets[i]))
            {

                isPelletEaten[i] = true;
                enemyGridSize += 20;
                atomSpeed += 0.03;
            }
        }
        if (!isPelletEaten[i] && CheckCollisionCircleRec(atomPosition, gridSize / 2, pellets[i]))
        {

            isPelletEaten[i] = true;
            
        }
    }

    bool allPelletsEaten = true;
    for (size_t i = 0; i < isPelletEaten.size(); i++)
    {
        if (!isPelletEaten[i])
        {
            allPelletsEaten = false;
            break;
        }
    }

    if (allPelletsEaten)
    {
        isLevelCompleted = true;
    }
}

void updateEnemies() {
    for (size_t i = 0; i < enemyPositions.size(); i++)
    {
        Vector2 direction = { atomPosition.x - enemyPositions[i].x, atomPosition.y - enemyPositions[i].y };
        float length = sqrt(direction.x * direction.x + direction.y * direction.y);

        if (length > 0)
        {
                direction.x /= length;
                direction.y /= length;

                enemyPositions[i].x += direction.x * enemySpeed;
                enemyPositions[i].y += direction.y * enemySpeed;
        }
        if (CheckCollisionCircles(atomPosition, gridSize / 2, enemyPositions[i], enemyGridSize / 2))
        {
            isGameOver = true;
        }
    }

}