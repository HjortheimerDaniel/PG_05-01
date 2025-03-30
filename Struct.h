#pragma once

struct Vector2 {
	float x, y;
};

struct Quad {
	Vector2 UL, UR, LL, LR;
};

struct PlayerStruct
{
	Vector2 pos, size;
	int handle;
	float speed;

};


struct EnemyStruct
{
	Quad pos;
	Quad hitbox;
	Vector2 speed, size;
	int handle, animation, frames, MAXAnimation, MAXFrames;
	bool isDead, isDamaged;
	int damagedTimer;
	float theta;
	float amplitude;
	int HP;
	int color;
	bool isDead;

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

struct BulletStruct {
	Vector2 pos[4];
	int radius;
	bool isShot[4];
	int speed[4];
	int handle;
	int CD;
};