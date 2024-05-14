#pragma once

#include"../Utility/Vector2D.h"
#define ENEMY_MAX 100

class Enemy
{
private:
	int type;            //タイプ
	int image;           //画像
	float speed;         //速さ
	Vector2D location;   //位置情報
	Vector2D box_size;   //当たり判定の大きさ
	int hp;				 // HP
	int dmg;
	int delay;

	bool atk_flg;		 //攻撃フラグ

public:
	Enemy();
	~Enemy();

	void Initialize();          //初期化処理
	void Update();   //更新処理
	void Draw()const;           //描画処理
	void Finalize();            //終了時処理
	void Movement();			//移動処理
	void Spawn();

	int GetType()const;             //タイプ取得
	Vector2D GetLocation();		//位置情報の取得
	Vector2D GetBoxSize()const;     //当たり判定の大きさを取得
	int GetHP();					//HPの取得
	void Damage(int damage);		//ダメージ処理
	int GetDamage()const;		//攻撃処理
	void ChengeAtkFlg(bool flg);			//攻撃フラグ
	bool GetAtkFlg();
};