#include "S21_FistL.h"

S_21FistL::S_21FistL()
{
	image = LoadGraph("Resources/Images/kobushide3.png");
}

S_21FistL::~S_21FistL()
{
}

void S_21FistL::Initialize(Vector2D p_location)
{
	location = p_location;
	box_size = Vector2D(100.0f, 50.0f);
	speed = 3.6f;
	damage = 5.0f;
	bright_fadeout = 255;
	kaiten = PI / 2;
}

void S_21FistL::Update()
{
	location.x += speed;

	//‰EŽèUŒ‚
	if (kaiten > 1.0)
	{
		kaiten -= 0.01f;
	}
	if (bright_fadeout > 0)
	{
		location.y--;
	}
	if (location.x >= 250)
	{
		location.x = 250;
		bright_fadeout -= 10;
	}
}

void S_21FistL::Draw() const
{
	//‰EŽè•`‰æ
	if (location.x >= 250)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, bright_fadeout);
		DrawRotaGraph(location.x, location.y + 50, 1.0f, kaiten, image, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	else {
		DrawRotaGraph(location.x, location.y + 50, 1.0f, kaiten, image, TRUE);
	}
}

void S_21FistL::Finalize()
{
	DeleteGraph(image);
}

Vector2D S_21FistL::GetLocation() const
{
	return Vector2D(this->location);
}

Vector2D S_21FistL::GetBoxSize() const
{
	return Vector2D();
}

int S_21FistL::GetDamage() const
{
	return int(damage);
}

float S_21FistL::FadeOut()
{
	return bright_fadeout;
}
