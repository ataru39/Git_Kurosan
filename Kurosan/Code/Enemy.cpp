#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy() :type(0), image(0), speed(0.0f), location(0.0f), box_size(0.0f)
{
	image = LoadGraph("Resources/Images/Slime.png");
	
}

Enemy::~Enemy()
{

}

//初期化処理
void Enemy::Initialize()
{
	//出現させるX座標パターンを取得
	float random_y = (float)(GetRand(50) * 11 + 100);
	//生成位置の設定
	location = Vector2D(1300.0f, random_y);
	//当たり判定の設定
	box_size = Vector2D(50.0f, 50.0f);
	//速さの設定
	speed = 5.5f;
	dmg = 1;
	hp = 30;
	delay = 300;
	atk_flg = false;
}

void Enemy::Update()
{
	//位置情報に移動量を加算する
	location += Vector2D(-speed, 0.0f);

	if (location.x <= 200) {
		location.x = 200;
	}

	if (atk_flg) {
		if (delay > 0) {
			delay--;
			if (delay <= 0) {
				atk_flg = false;
				delay = 300;
			}
		}
	}
}

void Enemy::Draw()const
{
	//敵画像を描画
	//DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);
	
	DrawGraph(location.x, location.y, image, TRUE);
}

void Enemy::Finalize()
{
	DeleteGraph(image);
}

void Enemy::Movement()
{

}

void Enemy::Spawn()
{

}

//敵タイプを取得
int Enemy::GetType()const
{
	return type;
}

//位置情報を取得
Vector2D Enemy::GetLocation()
{
	return location;
}

//当たり判定の大きさを取得
Vector2D Enemy::GetBoxSize()const
{
	return box_size;
}

int Enemy::GetHP()
{
	return this->hp;
}

void Enemy::Damage(int damage)
{
	hp -= damage;
}

int Enemy::GetDamage()const
{
	return int(dmg);
}

bool Enemy::GetAtkFlg()
{
	return atk_flg;
}

void Enemy::ChengeAtkFlg(bool flg)
{
	atk_flg = flg;
}
