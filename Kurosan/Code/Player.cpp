#include "Player.h"
#include "../Utility/InputControl.h"
#include "Dxlib.h"
#include"stdio.h"
#define PI    3.1415926535897932384626433832795f


Player::Player()
{
	image = LoadGraph("Resources/Images/wizard.png");
}

Player::~Player()
{

}

//初期化処理
void Player::Initialize()
{
	location = Vector2D(140.0f, 410.0f);
	box_size = Vector2D(50.0f, 100.0f);
	exp = 0;
	exp_max = 5;
	level = 1;
}

//更新処理
void Player::Update()
{
	Movement();
}

//描画処理
void Player::Draw()
{
	DrawRotaGraph(location.x, location.y, 2, PI / 2, image, TRUE);
}

//終了時処理
void Player::Finalize()
{
	DeleteGraph(image);
}

//位置情報取得処理
Vector2D Player::GetLocation()const
{
	return this->location;
}

Vector2D Player::GetBoxSize()const
{
	return this->box_size;
}

//移動処理
void Player::Movement()
{
	Vector2D move = Vector2D(0.0f);

	if (InputControl::GetLeftStick().y > 0.2 && location.y < 670)
	{
		move += Vector2D(0.0f, +3.0f);
	}

	if (InputControl::GetLeftStick().y < -0.2 && location.y > 150)
	{
		move += Vector2D(0.0f, -3.0f);
	}

		location += move;
}
