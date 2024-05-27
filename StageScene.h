#pragma once
#include "IScene.h"
#include "Player.h"
#include "Enemy.h"




class StageScene : public IScene
{
public:

	void Init() override;
	~StageScene();
	void Update(char* keys, char* preKeys) override;

	void CollisionBulletEnemy();

	void Draw() override;

private:

	Player* player = new Player();
	Enemy* enemy = new Enemy();

};

