#pragma once

#include"../Utility/Vector2D.h"

class Wall
{
public:
	Wall();
	~Wall();

	void Initialize();    //初期化処理
	void Update();        //更新処理
	void Draw()const;          //描画処理
	void Finalize();      //終了時処理
	void Damage(int damage);
	int WallHp();
	bool WallBreak();

	Vector2D GetLocation()const;
	Vector2D GetBoxSize()const;

private:
	int hp;
	int image;
	int o_image;
	int font;
	int flg;
	int cnt;
	Vector2D location;
	Vector2D box_size;

};

