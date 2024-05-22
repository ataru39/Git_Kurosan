#include "S_21Fist.h"

S_21Fist::S_21Fist()
{
	image = LoadGraph("Resources/Images/kobushide2.png");
}

S_21Fist::~S_21Fist()
{

}

void S_21Fist::Initialize(Vector2D p_location)
{
	location = p_location;
	box_size = Vector2D(100.0f, 100.0f);
	speed = 3.6f;
	damage = 10.0f;
	bright_fadeout = 255;
	kaiten = PI / 2;
}

void S_21Fist::Update()
{
	if (kaiten < 2.6) {
		kaiten += 0.01f;
	}

	location.x += speed;

	if (bright_fadeout>0) {
		location.y++;
	}

	if (location.x >= 250) {
		location.x = 250;
		bright_fadeout-=10;
	}
	
	
}

void S_21Fist::Draw() const
{
	if (location.x>=250) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, bright_fadeout);
		DrawRotaGraph(location.x, location.y, 1.0f, kaiten, image, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	else {
		DrawRotaGraph(location.x, location.y,1.0f, kaiten, image, TRUE);
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

int S_21Fist::FadeOut()
{
	return bright_fadeout;
}
