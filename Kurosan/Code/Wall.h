#pragma once

class Wall
{
public:
	Wall();
	~Wall();

	void Initialize();    //初期化処理
	void Update();        //更新処理
	void Draw();          //描画処理
	void Finalize();      //終了時処理

private:
	float hp;

	struct Rect{
		float x;
		float y;
		float width;
		float height;
	};struct Rect rec_wall;

	struct Vec2 {
		float x;
		float y;
	};struct Vec2 center_wall;
};

