#include "S_21Fist.h"

S_21Fist::S_21Fist()
{
	image = LoadGraph("Resources/Images/teki.png");
}

S_21Fist::~S_21Fist()
{

}

void S_21Fist::Initialize(Vector2D p_location)
{
	location = p_location;
	box_size = Vector2D(50.0f, 50.0f);
	speed = 10.0f;
	damage = 10.0f;
	bright_fadeout = 255;
}

void S_21Fist::Update()
{
	location.x += speed;
	if (location.x >= 250) {
		location.x = 250;
		bright_fadeout--;
	}
}

void S_21Fist::Draw() const
{
	if (location.x>=250) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, bright_fadeout);
		DrawGraph(location.x, location.y, image, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	else {
		DrawGraph(location.x, location.y, image, TRUE);
	}
}

void S_21Fist::Finalize()
{
}

Vector2D S_21Fist::GetLocation() const
{
	return Vector2D(this->location);
}

Vector2D S_21Fist::GetBoxSize() const
{
	return Vector2D();
}

int S_21Fist::GetDamage() const
{
	return int(damage);
}
