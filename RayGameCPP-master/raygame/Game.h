#include "GameObject.h"
#include "CollisionShape.h"
#include "Player.h"
#include "Bullet.h"
#include "EnemyDefault.h"
#include "Explosion.h"
#include "Minimap.h"
#include "Base.h"
#include "Button.h"
#include "Asteroid.h"
#include <vector>
#include <string>
using namespace std;

#pragma once
class Game
{

protected:
	//Constructor
	Game();
	static Game* instance;

public:

	static Game* GetInstance();
	//Deconstructor
	~Game();

	//Variables
	vector<GameObject*> scene;
	vector<CollisionShape*> collisionShapes;
	vector<GameObject*> enemies;
	vector<Asteroid*> asteroids;
	Player* player;
	Base* base;
	//Game
	Vector2 worldSize;
	Vector2 worldTileSize;
	Vector2 center; //Center of the world
	Vector2 playerSpawn;
	bool gameover;
	bool menuOpen;
	//Camera
	Vector2 cameraPosition;
	Vector2 cameraSize;
	GameObject* cameraOwner;
	//Enemy Spawn
	float enemySpawnTime;
	float enemySpawnTimer;
	//Player spawn
	float playerSpawnTime;
	float playerSpawnTimer;
	//Start timer
	float instructionTime;
	float instructionTimer;
	//Stats
	int score;
	//Textures
	Texture2D spr_background;
	Rectangle rect_background;
	Texture2D spr_player;
	Rectangle rect_player;
	Texture2D spr_playerBooster;
	Rectangle rect_playerBooster;
	int frames_playerBooster;
	Texture2D spr_bullet;
	Rectangle rect_bullet;
	Texture2D spr_enemyDefault;
	Rectangle rect_enemyDefault;
	Texture2D spr_explosion;
	Rectangle rect_explosion;
	int frames_explosion;
	Texture2D spr_base;
	Rectangle rect_base;
	Texture2D spr_asteroidS;
	Rectangle rect_asteroidS;
	Texture2D spr_asteroidM;
	Rectangle rect_asteroidM;
	Texture2D spr_asteroidL;
	Rectangle rect_asteroidL;
	//Sounds
	Sound sfx_boostPlayer;
	Sound sfx_shootPlayer;
	Sound sfx_shootEnemy;
	Sound sfx_hitPlayer;
	Sound sfx_hitEnemy;
	Sound sfx_hitAsteroid;
	Sound sfx_hitBase;
	Sound sfx_explodePlayer;
	Sound sfx_explodeEnemy;
	Sound sfx_explodeAsteroid;
	Sound sfx_buttonHover;
	Sound sfx_buttonClick;
	Sound sfx_gameover;
	//For debugging
	bool drawCollisions;
	//Waves
	int wave;
	int enemiesToSpawn;
	int enemiesPerWave;
	//Asteroid spawning
	Rectangle chunk[16];

	//Functions
	void Start();
	void Draw();
	void Update();
	void ManageTimers();
	void CameraPosition();
	//Gameover
	void Gameover();
	void StartGame();
	//Spawning
	void InstanceObject(GameObject*, int, int);
	void SpawnEnemy();
	void SpawnPlayer();
	void SpawnAsteroid(int);
	void SpawnWaveAsteroids();
	int CheckAsteroidChunk(int);
	int CountLargeAsteroids();
	//Waves
	void WaveIncrease();
	//Helpful stuff
	void ShuffleArray(int[], int);

	//Singleton operator override
	void operator = (const Game&) = delete;
	Game(const Game& other) = delete;

};

