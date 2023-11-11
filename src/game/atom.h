#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>
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



extern Texture2D background;
extern Texture2D playerTexture;
extern Texture2D enemyTexture;
extern Texture2D palletsTexture;

void Init();
void UpdateGame();
void DrawGame();
void RestartGame(int lvl = 0);
void mainMenu();
