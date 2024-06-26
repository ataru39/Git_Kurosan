#pragma once

#include"../Utility/Vector2D.h"
#define ENEMY_MAX 100

class Enemy
{
private:
	int type;            //タイプ
	int image, image_g, image_m;		//通常画像
	int image2, image_g2, image_m2;		//ダメージ画像
	float speed;         //速さ
	Vector2D location;   //位置情報
	Vector2D box_size;   //当たり判定の大きさ
	int hp;				 // HP
	bool dmgflg;		 //ダメージを受けた時
	int dmgcnt;			 //ダメージカウンター	
	int reverse;
	int dmg;
	bool atk_flg;
	int delay;
	bool angflg;
	int angcnt;
	int exp;
	int e_type[4][5];

public:
	Enemy();
	~Enemy();

	void Initialize(int minute);	//初期化処理
	void Update();		//更新処理
	void Draw()const;   //描画処理
	void Finalize();    //終了時処理
	void Movement();	//移動処理
	void Spawn();
	void Damage(int damage);		// ダメージ処理

	Vector2D GetLocation();			//位置情報の取得
	Vector2D GetBoxSize()const;     //当たり判定の大きさを取得
	int GetHP();					// HPの取得
	int GetDamage()const;
	bool GetAtkFlg();
	void ChengeAtkFlg(bool flg);
	int GetExp();					// 経験値の取得
};