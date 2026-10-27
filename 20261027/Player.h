#pragma once

class Player
{
private:
	float x, y, z;

public:
	//コンストラクタ
	Player();

	//プレイヤー更新
	void Update(float deltaTime);

	//プレイヤー描画
	void Draw() const;

	//プレイヤーの位置を取得
	float GetX() const;
	float GetY() const;
	float GetZ() const;
};

