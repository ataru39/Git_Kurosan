#include "Wall.h"
#include "DxLib.h"

Wall::Wall()
{
	hp = 100;
	image = LoadGraph("Resources/Images/kabe2.png");
	image2 = LoadGraph("Resources/Images/kabe3.png");
	imageblock = LoadGraph("Resources/Images/kabeblock.png");
}

Wall::~Wall()
{

}

void Wall::Initialize()
{
	location = Vector2D(100.0f, 100.0f);
	box_size = Vector2D(50.0f, 50.0f);

}

void Wall::Update()
{

}

void Wall::Draw()
{
	DrawGraph(0, 100, image, TRUE);
	DrawGraph(0, 300, image, TRUE);
	DrawGraph(0, 500, image, TRUE);
	DrawGraph(0, 700, image, TRUE);
	
	//DrawBox(0, 100, 200, 720, 0x0000f, TRUE);
	DrawBox(location.x, location.y, location.x + box_size.x, location.y + box_size.y, 0x00ff00, TRUE);
}

void Wall::Finalize()
{

}

Vector2D Wall::GetLocation() const
{
	return location;
}

Vector2D Wall::GetBoxSize() const
{
	return box_size;
}



