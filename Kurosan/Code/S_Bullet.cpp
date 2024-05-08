#include "S_Bullet.h"
#include "DxLib.h"

S_Bullet::S_Bullet()
{
	image = LoadGraph("Resources/Images/Bullet.png");
}

S_Bullet::~S_Bullet()
{

}

void S_Bullet::Initialize(Vector2D p_location)
{
	location = p_location;
	box_size = Vector2D(50.0f, 50.0f);
	speed = 5.0f;
}

void S_Bullet::Update()
{
	location.x += speed;

	if (cool_time > 0)
	{
		cool_time--;
	}
}

void S_Bullet::Draw() const
{
	DrawGraph(location.x, location.y, image, TRUE);
	//DrawBox(location.x, location.y, location.x +50, location.y + 50, image, TRUE);
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

//Vector2D S_Bullet::GetCoolTime() const
//{
//	return Vector2D(this->cool_time);
//}

Vector2D S_Bullet::GetDamage() const
{
	return Vector2D();
}
