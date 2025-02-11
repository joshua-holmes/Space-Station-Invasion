#include "raylib.h"
#include "GameObject.h"
#include "CollisionShape.h"
#include <string>
using namespace std;

#pragma once
class Asteroid : public GameObject
{

public:
	//-CONSTRUCTOR-
	Asteroid();
	Asteroid(int, Asteroid*);

	//-VARIABLES-
	//Sprite
	Texture2D* sprite;
	Rectangle* spriteSize;
	Rectangle destination;
	Vector2 spriteOffset;
	//Collision Shape
	CollisionShape* cs;
	//Damage
	int hp;
	float damageRest;
	float damageRestTimer;
	//Breaking
	int size;
	int killScore;
	Asteroid* creator;
	//Movement
	Vector2 velocity;
	float speed;
	float bounceTimer;
	float torque;
	//-FUNCTIONS-
	void Start();
	void Draw();
	void Update();
	void Destroy();
	void ManageTimers();
	//Damage
	void Damage(int);
	void Die();
	void CollisionCheck();
	//Movement
	void ApplyVelocity();
};