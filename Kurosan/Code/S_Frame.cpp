#include "S_Frame.h"
#include "DxLib.h"
#include <cmath>

S_Frame::S_Frame()
{
	image = LoadGraph("Resources/Images/Fire.png");
}

S_Frame::~S_Frame()
{

}

void S_Frame::Initialize(Vector2D p_location)
{
	location = p_location;
	box_size = Vector2D(50.0f, 50.0f);
	speed = 12.0f;
	damage = 10.0f;
}

void S_Frame::Update()
{
	location.x += speed;
}

void S_Frame::Draw() const
{
	DrawGraph(location.x, location.y, image, TRUE);
}

void S_Frame::Finalize()
{

}

Vector2D S_Frame::GetLocation() const
{
	return Vector2D(this->location);
}

Vector2D S_Frame::GetBoxSize() const
{
	return Vector2D();
}

int S_Frame::GetDamage() const
{
	return int(damage);
}