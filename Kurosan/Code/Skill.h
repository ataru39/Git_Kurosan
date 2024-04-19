#pragma once

#include"../Utility/Vector2D.h"

class Skill
{
private:
	int image;			// 画像
	Vector2D location;	// 位置座標
	Vector2D box_size;	// 当たり判定の大きさ
	Vector2D spawn_location;  // スポーン位置

public:
	Skill();
	~Skill();

	void Initialize();	// 初期化処理
	void Update();		// 更新処理
	void Draw();		// 描画処理
	void Finalize();	// 終了時処理

	Vector2D GetLocation() const;  //位置座標取得
	Vector2D GetBoxSize()const;    //当たり判定の大きさ取得

};
