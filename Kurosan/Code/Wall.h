#pragma once

#include"../Utility/Vector2D.h"

class Wall
{
public:
	Wall();
	~Wall();

	void Initialize();    //‰Šú‰»ˆ—
	void Update();        //XVˆ—
	void Draw()const;          //•`‰æˆ—
	void Finalize();      //I—¹ˆ—
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
	Vector2D location;
	Vector2D box_size;

};

