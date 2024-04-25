#pragma once

#include"../Utility/Vector2D.h"

class Skill
{
protected:
	int image;			// 画像
	Vector2D location;	// 位置座標
	Vector2D p_location;// プレイヤーの座標
	Vector2D box_size;	// 当たり判定の大きさ
	float speed;		// スキルの速度
	float cool_time;	// スキルクールタイム
	float damage;		// ダメージ

public:
	Skill();
	~Skill();

	void Initialize();	// 初期化処理
	void Update();		// 更新処理
	void Draw();		// 描画処理
	void Finalize();	// 終了時処理

	Vector2D GetLocation() const;   //位置座標取得
	Vector2D GetBoxSize() const;    //当たり判定の大きさ取得
	Vector2D GetCoolTime() const;   //当たり判定の大きさ取得
	Vector2D GetDamage() const;		//当たり判定の大きさ取得
};
