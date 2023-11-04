#include "atom.h"

int screenWidth = 1280;
int screenHeight = 720;
int gridSize = 40;
float atomSpeed = 0.07;
float enemySpeed = atomSpeed / 5;
int level = 0;
int maxLevel = 5;

Vector2 atomPosition;
std::vector<Vector2> enemyPositions;
std::vector<Rectangle> pellets;
std::vector<bool> isPelletEaten;
bool isGameOver;
bool isLevelCompleted;

void InitGame() {
	// Implementation of InitGame
	InitWindow(screenWidth, screenHeight, "Atom Lite");
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
