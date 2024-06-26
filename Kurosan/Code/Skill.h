#pragma once

#include"../Utility/Vector2D.h"
#define PI    3.1415926535897932384626433832795f

class Skill
{
protected:
	int image;			 // 画像
	Vector2D location;	 // 位置座標
	Vector2D p_location; // プレイヤーの座標
	Vector2D box_size;	 // 当たり判定の大きさ
	float speed;		 // スキルの速度
	float damage;		 // ダメージ

public:
	Skill() { };
	virtual ~Skill() { };

	virtual void Initialize() { };	// 初期化処理
	virtual void Update() { };		// 更新処理
	virtual void Draw() const { };	// 描画処理
	virtual void Finalize() { };	// 終了時処理

	virtual Vector2D GetLocation() const	//位置座標取得
	{
		return Vector2D();
	}
	virtual Vector2D GetBoxSize() const     //当たり判定の大きさ取得
	{
		return Vector2D();
	}
	virtual Vector2D GetCoolTime() const	//当たり判定の大きさ取得
	{
		return Vector2D();
	}
	virtual int GetDamage() const			//当たり判定の大きさ取得
	{
		return int();
	}
};