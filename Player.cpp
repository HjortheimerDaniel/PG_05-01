#include "Player.h"
#include "Novice.h"
#define _USE_MATH_DEFINES_
#include <math.h>


void Player::Initialize()
{
	player_.pos = { 400, 500 };
	player_.size = { 128,128 };
	player_.speed = 5;
	player_.handle = Novice::LoadTexture("./Sprites/player.png");
	
	bullet_.size = { 20, 20 };
	bullet_.handle = Novice::LoadTexture("./Sprites/bulletsmall.png");
	for (int i = 0; i < 10; i++) {

		bullet_.speed[i] = 8;
		bullet_.pos[i].x = -100;
		bullet_.pos[i].y = 200;
		bullet_.isShot[i] = false;
	}
}

Player::~Player()
{
}

void Player::Update(char* keys, char* preKeys)
{
	Movement(keys, preKeys);
	Shoot(keys, preKeys);
}

void Player::Movement(char* keys, char* preKeys)
{
	player_.speed = 0;

	if ((keys[DIK_D]||keys[DIK_RIGHT]) && (preKeys[DIK_D] || preKeys[DIK_RIGHT]) && player_.pos.x <= 1140 && !keys[DIK_A] &&
		!preKeys[DIK_A]) {
		player_.speed = +5;
	}

	if ((keys[DIK_A] || keys[DIK_LEFT]) && (preKeys[DIK_A] || preKeys[DIK_LEFT]) && player_.pos.x >= 0 && !keys[DIK_D] && !preKeys[DIK_D]) {
		player_.speed = -5;
	}

	float normalizeSpeed =
		sqrtf(player_.speed * player_.speed);
	if (normalizeSpeed != 0.0f) {
		player_.speed /= normalizeSpeed;
	
	}

	player_.pos.x += player_.speed * 5;
	
}

void Player::Shoot(char* keys, char* preKeys)
{
	for (int i = 0; i < 10; i++) {

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !bullet_.isShot[i]) {
			bullet_.isShot[i] = true;
			bullet_.pos[i].x = (player_.pos.x + 64) ;
			bullet_.pos[i].y = player_.pos.y - 30;
			break;
		}
	}

	for (int i = 0; i < 10; i++) {

		if (bullet_.isShot[i]) {
			bullet_.pos[i].y -= bullet_.speed[i];
		}

		if (bullet_.pos[i].y <= -30) {
			bullet_.isShot[i] = false;
		}
	}
}

void Player::Draw()
{
	for (int i = 0; i < 10; i++) {
		if (bullet_.isShot[i]) {

			Novice::DrawSprite((int)bullet_.pos[i].x, (int)bullet_.pos[i].y, bullet_.handle, 1, 1, 0.0f, WHITE);
		}
	}
	Novice::DrawSprite((int)player_.pos.x, (int)player_.pos.y, player_.handle, 1, 1, 0.0f, WHITE);
}
