#pragma once
#include "Struct.h"


class Player
{

public:

	void Initialize();

	~Player();

	void Update(char* keys, char* preKeys);

	void Movement(char* keys, char* preKeys);

	Vector2* GetBulletPos() { return bullet_.pos; };

	Vector2 GetBulletSize() { return bullet_.size; };

	void Shoot(char* keys, char* preKeys);

	void Draw();

private:

	PlayerStruct player_;
	Bullet bullet_;
};

