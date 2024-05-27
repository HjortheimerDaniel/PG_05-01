#pragma once

struct Vector2 {
	float x, y;
};

struct PlayerStruct
{
	Vector2 pos, size;
	int handle;
	float speed;

};


struct EnemyStruct
{
	Vector2 pos, size;
	int handle;
	float speed;
	float theta;
	float amplitude;

};

struct Bullet
{
	Vector2 pos[10];
	Vector2 size;
	bool isShot[10];
	int speed[10];
	int handle;
	int CD;
};
