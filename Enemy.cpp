#include "Enemy.h"
#include "Novice.h"
#define _USE_MATH_DEFINES
#include <math.h>

void Enemy::Initialize()
{
	enemy_.pos = { 500,50 };
	enemy_.size = { 128,128 };
	enemy_.handle = Novice::LoadTexture("./Sprites/enemyeye.png");
	enemy_.speed = 6;
	enemy_.amplitude = 350.0f;
	enemy_.theta = 0;

	
}

void Enemy::Update()
{
	Movement();
}

void Enemy::Movement()
{
	enemy_.theta += float(M_PI) / 250.0f;

	enemy_.pos.x = cosf(enemy_.theta) * enemy_.amplitude + 700;
	enemy_.pos.x = cosf(enemy_.theta) * enemy_.amplitude + 828;
	enemy_.pos.x = cosf(enemy_.theta) * enemy_.amplitude + 700;
	enemy_.pos.x = cosf(enemy_.theta) * enemy_.amplitude + 828;
}



void Enemy::Draw()
{
	Novice::DrawSprite((int)enemy_.pos.x, (int)enemy_.pos.y, enemy_.handle, 1, 1, 0.0f, WHITE);
}
