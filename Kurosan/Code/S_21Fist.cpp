#include "S_21Fist.h"

S_21Fist::S_21Fist()
{
	image = LoadGraph("Resources/Images/kobushide2.png");
	image2 = LoadGraph("Resources/Images/kobushide3.png");
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
	kaiten2 = PI / 2;
}

void S_21Fist::Update()
{
	location.x += speed;

	R_Fist();

	L_Fist();
	
}

void S_21Fist::Draw() const
{
	
	//‰Eè•`‰æ
	if (location.x >= 250)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, bright_fadeout);
		DrawRotaGraph(location.x, location.y+50 , 1.0f, kaiten2, image2, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	else {
		DrawRotaGraph(location.x, location.y+50, 1.0f, kaiten2, image2, TRUE);
	}

	//¶è•`‰æ
	//if (location.x >= 250)
	//{
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, bright_fadeout);
	//	DrawRotaGraph(location.x, location.y - 50, 1.0f, kaiten, image, TRUE);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//}
	//else {
	//	DrawRotaGraph(location.x, location.y - 50, 1.0f, kaiten, image, TRUE);
	//}
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

//‰EèUŒ‚
void S_21Fist::R_Fist()
{
	if (kaiten2 > 1.0)
	{
		kaiten2 -= 0.01f;
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

//¶èUŒ‚
void S_21Fist::L_Fist()
{
	if (kaiten < 2.6) {
		kaiten += 0.01f;
	}
	if (bright_fadeout > 0) {
		location.y++;
	}
	if (location.x >= 250) {
		location.x = 250;
		bright_fadeout -= 10;
	}
}

int S_21Fist::FadeOut()
{
	return bright_fadeout;
}

int S_21Fist::GetLevel()
{
	return level;
}

int S_21Fist::Level(int le)
{
	level = le;
}

