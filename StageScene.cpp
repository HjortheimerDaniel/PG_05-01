#include "StageScene.h"
#include <Novice.h>
#include "Collision.h"


void StageScene::Init()
{
	player->Initialize();
	enemy->Initialize();
	
}

StageScene::~StageScene()
{
	delete player;
	delete enemy;
}

void StageScene::Update(char* keys, char* preKeys)
{
	
	player->Update(keys, preKeys);
	enemy->Update();
	CollisionBulletEnemy();
}

void StageScene::CollisionBulletEnemy()
{
	for (int i = 0; i < 10; i++) {
		if (CheckCollision(player->GetBulletPos()[i],enemy->GetPos(), player->GetBulletSize(), enemy->GetSize()))
		{
			sceneNo = CLEAR;
			Init();
		}
		
	}
		
	

}

void StageScene::Draw()
{
	player->Draw();
	enemy->Draw();
	Novice::ScreenPrintf(0, 0, "A || < = LEFT");
	Novice::ScreenPrintf(0, 20, "D || > = RIGHT");
	Novice::ScreenPrintf(0, 40, "SPACE = SHOOT");
}
