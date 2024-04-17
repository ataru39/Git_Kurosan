#include "Player.h"
#include "../Utility/InputControl.h"
#include "Dxlib.h"

Player::Player()
{

}

Player::~Player()
{

}

//初期化処理
void Player::Initialize()
{
	location = Vector2D(140.0f, 260.0f);
}

//更新処理
void Player::Update()
{

}

//描画処理
void Player::Draw()
{

}

//終了時処理
void Player::Finalize()
{

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

	if (InputControl::GetLeftStick().y<0.2)
	{
		move -= Vector2D(0.0f, -3.0f);
	}

	if (InputControl::GetLeftStick().y<-0.2)
	{
		move += Vector2D(0.0f, +3.l0f);
	}
}
