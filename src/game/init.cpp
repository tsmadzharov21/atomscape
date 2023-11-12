#include "atom.h"

int screenWidth = 1280;
int screenHeight = 720;
int gridSize = 40;
int enemyGridSize=60;
float atomSpeed = 0.07;
float enemySpeed = 0.07;
int level = 0;
int maxLevel = 15;

Vector2 atomPosition;
std::vector<Vector2> enemyPositions;
std::vector<Rectangle> pellets;
std::vector<bool> isPelletEaten;
bool isGameOver;
bool isLevelCompleted;


Texture2D background;
Texture2D playerTexture;
Texture2D enemyTexture;
Texture2D palletsTexture;
Texture2D menuTexture;


void Init() {
	// Implementation of InitGame
	InitWindow(screenWidth, screenHeight, "AtomScape");

    playerTexture = LoadTexture("../../assets/images/molecule_player.png");
    background = LoadTexture("../../assets/images/maingame_bg.png");
    enemyTexture = LoadTexture("../../assets/images/bacteria_enemy.png");
    palletsTexture = LoadTexture("../../assets/images/atom_target.png");
    menuTexture = LoadTexture("...");



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