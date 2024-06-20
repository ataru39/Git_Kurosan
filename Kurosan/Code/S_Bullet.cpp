#include "S_Bullet.h"
#include "DxLib.h"

S_Bullet::S_Bullet()
{
	image = LoadGraph("Resources/Images/Bullet.png");
}

S_Bullet::~S_Bullet()
{

}

void S_Bullet::Initialize(Vector2D p_location, int p_Lv)
{
	location = p_location;
	location.y-=30;
	box_size = Vector2D(50.0f, 50.0f);
	speed = 7.0f + p_Lv;
	damage = 10.0f + p_Lv;
}

void S_Bullet::Update()
{
	location.x += speed;
}

void S_Bullet::Draw() const
{
	DrawGraph(location.x, location.y, image, TRUE);
}

void S_Bullet::Finalize()
{

}

Vector2D S_Bullet::GetLocation() const
{
	return Vector2D(this->location);
}

Vector2D S_Bullet::GetBoxSize() const
{
	return Vector2D();
}

int S_Bullet::GetDamage() const
{
	return int(damage);
}
