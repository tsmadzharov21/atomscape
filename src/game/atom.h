#pragma once
#include "raylib.h"
#include <vector>

extern int screenWidth;
extern int screenHeight;
extern int gridSize;
extern int enemyGridSize;
extern float atomSpeed;
extern float enemySpeed;
extern int level;
extern int maxLevel;


extern Vector2 atomPosition;
extern std::vector<Vector2> enemyPositions;
extern std::vector<Rectangle> pellets;
extern std::vector<bool> isPelletEaten;
extern bool isGameOver;
extern bool isLevelCompleted;

void InitGame();
void UpdateGame();
void DrawGame();
void RestartGame();
