#include "atom.h"
void updatePlayer();
void updateEnemies();


void RestartGame(int lvl)
{
    isGameOver = false;
    isLevelCompleted = false;
    level = lvl;
    atomPosition = { (float)gridSize, (float)gridSize };
    enemyPositions.clear();
    pellets.clear();
    isPelletEaten.clear();
    enemyPositions.push_back({ (float)(screenWidth - gridSize), (float)(screenHeight - gridSize) });
    for (int i = 0; i < level; i++)
    {
        enemyPositions.push_back({ (float)(GetRandomValue(gridSize, screenWidth - gridSize)), (float)(GetRandomValue(gridSize, screenHeight - gridSize)) });
    }

    for (int i = 0; i < 10; i++)
    {
        pellets.push_back({ (float)(GetRandomValue(0, (screenWidth / gridSize) - 1) * gridSize), (float)(GetRandomValue(0, (screenHeight / gridSize) - 1) * gridSize), (float)gridSize, (float)gridSize });
        isPelletEaten.push_back(false);
    }
}


void UpdateGame()
{
    // Implementation of UpdateGame
    if (isGameOver) {
        return;
    }
    if (isLevelCompleted)
    {
        if (level < maxLevel)
        {
            level++;
            RestartGame(level);
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
            if (!isPelletEaten[i] && CheckCollisionCircleRec({ atomPosition.x + gridSize / 2, atomPosition.y + gridSize / 2 }, gridSize / 2, pellets[i]))
            {

                isPelletEaten[i] = true;
                enemyGridSize += 20;
                atomSpeed += 0.03;
            }
        }
        if (!isPelletEaten[i] && CheckCollisionCircleRec({ atomPosition.x + gridSize / 2, atomPosition.y + gridSize / 2 }, gridSize / 2, pellets[i]))
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
        if (CheckCollisionCircles({ atomPosition.x + gridSize / 2, atomPosition.y + gridSize / 2 }, gridSize / 2, 
            { enemyPositions[i].x + enemyGridSize / 2,enemyPositions[i].y + enemyGridSize / 2 }, enemyGridSize / 2))
        {
            isGameOver = true;
        }
    }

}