#include "Enemy.h"
#include "DxLib.h"
#include "math.h"

Enemy::Enemy() :type(0), image(0),image2(0), image_g(0), image_m(0), speed(0.0f), location(0.0f), box_size(0.0f)
{
	//画像読み込み
	image = LoadGraph("Resources/Images/slime.png");
	image2 = LoadGraph("Resources/Images/slime_red.png");
	image_g = LoadGraph("Resources/Images/ghost.png");
	image_g2 = LoadGraph("Resources/Images/ghost_red.png");
	image_m = LoadGraph("Resources/Images/mash.png");
	image_m2 = LoadGraph("Resources/Images/mash_red.png");
				//画像					//ダメージ			//HP				 //スピード				//ダメージ画像
	/*スライム*/e_type[0][0] = { image }; e_type[0][1] = {1}; e_type[0][2] = {30}; e_type[0][3] = {2};   e_type[0][4] = { image2 };
	/*ゴースト*/e_type[1][0] = {image_g}; e_type[1][1] = {5}; e_type[1][2] = {90}; e_type[1][3] = {10};  e_type[1][4] = { image_g2 };
	/* きのこ */e_type[2][0] = {image_m}; e_type[2][1] = {10}; e_type[2][2] = {100}; e_type[2][3] = {5}; e_type[2][4] = { image_m2 };
}

Enemy::~Enemy()
{
}

//初期化処理
void Enemy::Initialize(int teki,int plevel)
{
	#define PI    3.1415926535897932384626433832795f
	//プレイヤーレベルに応じてステータス強化
				//ダメージ			//HP					//スピード
	/*スライム*/e_type[0][1] = { 1  }; e_type[0][2] = { 30 } ; e_type[0][3] = { 2  };
	/*ゴースト*/e_type[1][1] = { 5  }; e_type[1][2] = { 90 } ; e_type[1][3] = { 10 };
	/* きのこ */e_type[2][1] = { 10 }; e_type[2][2] = { 100 }; e_type[2][3] = { 1  };
	//敵の種類
	//type = (rand() % fun);
	type = teki;
	//出現させるX座標パターンを取得
	float random_y = (float)(GetRand(50) * 11 + 100);
	//生成位置の設定
	location = Vector2D(1300.0f, random_y);
	//当たり判定の設定
	box_size = Vector2D(50.0f, 50.0f);
	//種類ごとのスピード
	speed = e_type[type][3];
	//種類ごとのHP
	hp = e_type[type][2];
	//種類ごとの攻撃力
	dmg = e_type[type][1];
	// EXPの設定
	exp = 1;
	dmgflg = false;
	dmgcnt = 10;
	atk_flg = false;
	delay = 300;
	angflg = false;
	angcnt = 15;
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

	//敵の画像反転
	if (angflg) {
		angcnt--;
	}
	else {
		angcnt--;
	}

	if (angcnt <= 0 && angflg) {
		angflg = false;
		angcnt = 15;
	}

	if (angcnt <= 0 && !angflg) {
		angflg = true;
		angcnt = 15;
	}
}

void Enemy::Draw()const
{
	if (!dmgflg) {
		if (angflg) {
			//DrawGraph(location.x, location.y, image, TRUE);
			DrawRotaGraph2(location.x, location.y, 50, 50, 1.0, PI / 1, e_type[type][0], TRUE, TRUE);
		}
		else {
			DrawRotaGraph2(location.x, location.y, 0, 0, 1, 0, e_type[type][0], TRUE, FALSE);
		}

	}
	else {
		if (angflg) {
			DrawRotaGraph2(location.x, location.y, 50, 50, 1, PI / 1, e_type[type][4], TRUE, TRUE);
		}
		else {
			DrawRotaGraph2(location.x, location.y, 0, 0, 1, 0, e_type[type][4], TRUE, FALSE);
		}
	}

	DrawFormatString(500, 500, 0xffffff, "%d", type, true);
}

void Enemy::Finalize()
{
	DeleteGraph(image);
	DeleteGraph(image2);
	DeleteGraph(image_g);
	DeleteGraph(image_g2);
	DeleteGraph(image_m);
	DeleteGraph(image_m2);

}

void Enemy::Movement()
{

}

void Enemy::Spawn()
{

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

int Enemy::GetExp()
{
	return this->exp;
}

