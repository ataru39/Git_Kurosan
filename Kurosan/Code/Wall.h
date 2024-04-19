#pragma once

class Wall
{
public:
	Wall();
	~Wall();

	void Initialize();    //‰Šú‰»ˆ—
	void Update();        //XVˆ—
	void Draw();          //•`‰æˆ—
	void Finalize();      //I—¹ˆ—

private:
	float hp;

	struct Rect{
		float x;
		float y;
		float width;
		float height;
	};struct Rect* rec_wall;

	struct Vec2 {
		float x;
		float y;
	};struct Vec2 center_wall;
};

