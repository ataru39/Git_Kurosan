#include "Player.h"
#include "../Utility/InputControl.h"
#include "Dxlib.h"

Player::Player()
{
	image = LoadGraph("Resources/Images/PTamesi.png");
}

Player::~Player()
{

}

//初期化処理
void Player::Initialize()
{
	location = Vector2D(140.0f, 260.0f);
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
	DrawGraph(location.x, location.y, image, TRUE);
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

//移動処理
void Player::Movement()
{
	Vector2D move = Vector2D(0.0f);

	if (InputControl::GetLeftStick().y > 0.2 && location.y < 670)
	{
		move += Vector2D(0.0f, +3.0f);
	}

	if (InputControl::GetLeftStick().y < -0.2 && location.y > 100)
	{
		move += Vector2D(0.0f, -3.0f);
	}
	//if (location.y < 100)
	//{
	//	location.y = 100;
	//}
	//if (location.y > 1230)
	//{
	//	location.y = 1230;
	//}

		location += move;
}

void Player::LevelUP()
{
	if (InputControl::GetButton(XINPUT_BUTTON_B)==TRUE)
	{
		level++;

	}
}
