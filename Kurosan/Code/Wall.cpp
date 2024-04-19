#include "Wall.h"
#include "DxLib.h"

Wall::Wall()
{
	rec_wall->x = 0.0f;
	rec_wall->y = 100.0f;
	rec_wall->width = 200.0f;
	rec_wall->height = 620.0f;
}

Wall::~Wall()
{

}

void Wall::Initialize()
{
	hp = 100;
	Vec2 center_wall = {
		rec_wall->x+(rec_wall->width/2.0f),
		rec_wall->y+(rec_wall->height/2.0f)
	};
}

void Wall::Update()
{



}

void Wall::Draw()
{
	DrawBox(0, 100, 200, 720, 0x0000ff, TRUE);
	
}

void Wall::Finalize()
{

}



