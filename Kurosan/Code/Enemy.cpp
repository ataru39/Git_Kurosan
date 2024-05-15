#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy() :type(0), image(0),image2(0), speed(0.0f), location(0.0f), box_size(0.0f)
{
	image = LoadGraph("Resources/Images/slime.png");
	image2 = LoadGraph("Resources/Images/slime_red.png");
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
	speed = 1.0f;
	hp = 30;
	dmgflg = false;
	dmgcnt = 10;
	dmg = 1;
	atk_flg = false;
	delay = 300;
}

void Enemy::Update()
{
	//位置情報に移動量を加算する
	location += Vector2D(-speed , 0.0f);

	if (location.x <= 200) {
		location.x = 200;
	}

	if (dmgflg) {
		dmgcnt--;
	}
	if (dmgcnt <= 0) {
		dmgflg=false;
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
	if(!dmgflg)		
	//DrawGraph(location.x, location.y, image, TRUE);
	DrawGraph(location.x, location.y, image, TRUE);
	else{
		DrawGraph(location.x, location.y, image2, TRUE);
	}
}

void Enemy::Finalize()
{
	DeleteGraph(image);
	DeleteGraph(image2);
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
	dmgflg = true;
	dmgcnt = 10;
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