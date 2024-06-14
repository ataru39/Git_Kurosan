#include "S_21Fist.h"

S_21Fist::S_21Fist()
{
	image = LoadGraph("Resources/Images/kobushide2.png");
	image2 = LoadGraph("Resources/Images/kobushide22.png");
}

S_21Fist::~S_21Fist()
{

}

void S_21Fist::Initialize(Vector2D p_location)
{
	location = p_location;
	box_size = Vector2D(100.0f, 50.0f);
	speed = 3.6f;
	damage = 15.0f;
	bright_fadeout = 255;
	kaiten = PI / 2;
	atk = false;
	ougi_y = 200;
	ougi_x = 200;
}

void S_21Fist::Update()
{
	location.x += speed;

	//ç∂éËçUåÇ
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

	//ougi_y += speed;
	//if (ougi_x >= 390) {
	//ougi_x = 390;
	//bright_fadeout -= 10;
	//}

}

void S_21Fist::Draw() const
{
	//ç∂éËï`âÊ
	if (location.x >= 250)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, bright_fadeout);
		DrawRotaGraph(location.x, location.y-50 , 1.0f, kaiten, image, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	else {
		DrawRotaGraph(location.x, location.y-50, 1.0f, kaiten, image, TRUE);
	}
	//if (ougi_y < 390) {
	//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, bright_fadeout);
	//	DrawRotaGraph(ougi_x, ougi_y , 1.0f, 0.0f, image2, TRUE);
	//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//}

}

void S_21Fist::Finalize()
{
	DeleteGraph(image);
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

float S_21Fist::FadeOut()
{
	return bright_fadeout;
}

int S_21Fist::GetLevel()
{
	return level;
}

