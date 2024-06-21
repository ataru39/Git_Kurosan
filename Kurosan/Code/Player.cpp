#include "Player.h"
#include "../Utility/InputControl.h"
#include "Dxlib.h"
#include"stdio.h"
#define PI    3.1415926535897932384626433832795f


Player::Player()
{
	image = LoadGraph("Resources/Images/wizard.png");
	LoadDivGraph("Resources/Images/kamifubuki.png",12,1,12,1920,480,l_image);

}

Player::~Player()
{

}

//初期化処理
void Player::Initialize()
{
	location = Vector2D(80.0f, 410.0f);
	box_size = Vector2D(50.0f, 100.0f);

	// EXPの初期化
	exp = 0;
	// レベルアップ必要EXPの初期化
	need_exp = 5;
	// レベル初期化
	level = 1;
	// スピード初期化
	speed = 7.5f;
}

//更新処理
void Player::Update()
{
	Movement();
	if (Levelup())
	{
		PlaySoundMem(levelsound, DX_PLAYTYPE_NORMAL, TRUE);
	}
}

//描画処理
void Player::Draw()
{
	DrawRotaGraph(location.x, location.y, 2, PI / 2, image, TRUE);

	if (Levelup() == true)
	{
		for(int i=0;i<11;i++)
		{
			DrawGraph(0, 0, l_image[i], TRUE);
		}
	}
}

//終了時処理
void Player::Finalize()
{
	DeleteGraph(image);
	for (int i = 0; i < 11; i++) {
		DeleteGraph(l_image[i]);
	}
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
		move += Vector2D(0.0f, +speed);
	}

	if (InputControl::GetLeftStick().y < -0.2 && location.y > 150)
	{
		move += Vector2D(0.0f, -speed);
	}

		location += move;
}

int Player::GetLevel()
{
	return this->level;
}

int Player::GetExp()
{
	return this->exp;
}

int Player::RcvExp(int exp)
{
	return this->exp += exp;
}

bool Player::Levelup()
{
	if (exp >= need_exp && level < 11)
	{
		// レベルアップ
		level += 1;
		// レベルアップ必要EXP上昇
		need_exp += 5;
		// EXPをゼロにする
		exp = 0;

		return true;
	}
	return false;
}
