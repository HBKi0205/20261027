#include "Player.h"
#include "Config.h"
#include "DxLib.h"
#include <cmath>
using namespace std;

//コンストラクタ
Player::Player() :x(0.0f), y(0.0f), z(0.0f){}

//更新
void Player::Update(float deltaTime)
{
	float moveX = 0.0f;
	float moveZ = 0.0f;

	if (CheckHitKey(KEY_INPUT_W)) {
		moveZ += 1.0f;
	}
	if (CheckHitKey(KEY_INPUT_S)) {
		moveZ -= 1.0f;
	}
	if (CheckHitKey(KEY_INPUT_A)) {
		moveX -= 1.0f;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		moveX += 1.0f;
	}

	const float length = sqrt(moveX * moveX + moveZ * moveZ);
	if (length > 0.0f) {
		moveX /= length;
		moveZ /= length;
		x += moveX * Config::PLAYER_MOVE_SPEED * deltaTime;
		z += moveZ * Config::PLAYER_MOVE_SPEED * deltaTime;
	}

	//const float limit = Config::FIELD_HALF_SIZE - Config::PLAYER_HALF_SIZE;
	//if (x < -limit) {
	//	x = -limit;
	//}
	//if (x > limit) {
	//	x = limit;
	//}
	//if (z < -limit) {
	//	z = -limit;
	//}
	//if (z > limit) {
	//	z = limit;
	//}
}

void Player::Draw() const
{
	const VECTOR bottom = VGet(x, y + Config::PLAYER_HEIGHT, z);
	const VECTOR top = VGet(x, y + Config::PLAYER_HEIGHT - Config::PLAYER_RADIUS, z);

	const int blue = GetColor(50, 120, 255);

	DrawCapsule3D(bottom, top, Config::PLAYER_RADIUS, 8, blue, blue, TRUE);
}

float Player::GetX() const { return x; }
float Player::GetY() const { return y; }
float Player::GetZ() const { return z; }
