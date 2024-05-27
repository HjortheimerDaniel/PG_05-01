#pragma once
#include "Struct.h"

class Enemy
{
public:

	void Initialize();

	void Update();

	void Movement();

	Vector2 GetPos() { return enemy_.pos; };

	Vector2 GetSize() { return enemy_.size; };

	void Draw();

private:

	EnemyStruct enemy_;

};

