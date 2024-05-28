#pragma once

#include"../Utility/Vector2D.h"

class Player
{
private:
	int image;				//描画する画像データ
	int exp;				// 経験値
	int need_exp;			// レベルアップ必要EXP
	int level;				// レベル
	Vector2D location;		//位置座標
	Vector2D box_size;		//当たり判定の大きさ
	float speed;			// スピード

public:
	Player();
	~Player();

	void Initialize();    //初期化処理
	void Update();        //更新処理
	void Draw();          //描画処理
	void Finalize();      //終了時処理

public:
	Vector2D GetLocation() const;  //位置座標取得
	Vector2D GetBoxSize()const;    //当たり判定の大きさ取得
	void Movement();
	int GetLevel();				   // プレイヤーレベルの取得
	int GetExp();				   // 経験値の取得
	int RcvExp(int exp);		   // 経験値の受取
	bool Levelup();				   // レベルアップ
};
