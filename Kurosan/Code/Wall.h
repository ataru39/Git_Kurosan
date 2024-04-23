#pragma once

#include"../Utility/Vector2D.h"

class Wall
{
public:
	Wall();
	~Wall();

	void Initialize();    //初期化処理
	void Update();        //更新処理
	void Draw();          //描画処理
	void Finalize();      //終了時処理

	Vector2D GetLocation()const;
	Vector2D GetBoxSize()const;

private:
	float hp;
	Vector2D location;
	Vector2D box_size;

};

