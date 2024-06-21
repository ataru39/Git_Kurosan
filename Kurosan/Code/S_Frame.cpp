#include "S_Frame.h"
#include "Enemy.h"
#include "DxLib.h"
#include <cmath>

S_Frame::S_Frame()
{
	image = LoadGraph("Resources/Images/F3.png");
	LoadDivGraph("Resources/Images/Flames.png", 7, 7, 1, 50, 50, images);
}

S_Frame::~S_Frame()
{

}

void S_Frame::Initialize(Vector2D p_location, Vector2D e_location)
{
	location = p_location;
	box_size = Vector2D(0.2f, 0.2f);
	speed = 22.0f;
	damage = 10.0f;

	f_size = 1.0f;
	f_count = 0;
	delay = 3;
	a = 0.2;

	f_flg = false;

	destination_location += e_location;

	movement_vector = destination_location - location;

	/*ƒxƒNƒgƒ‹‚Ì³‹K‰»*/
	float distance = std::sqrtf(std::powf(movement_vector.x, 2) + std::powf(movement_vector.y, 2));
	movement_vector.x *= (1 / distance);
	movement_vector.y *= (1 / distance);
}

void S_Frame::Update()
{
	if (f_flg == false) {
		location += (movement_vector * speed);
	}

	//“–‚½‚Á‚½‚ç”š”­
	if (f_flg) {
		if (delay > 0) {
			delay--;
			if (delay < 1) {
				f_size += 0.8f;
				box_size = Vector2D(100, 100);
				f_count++;
				delay = 2;
			}
		}
		if (f_count >= 7)
		{
			box_size = Vector2D(0.0f, 0.0f);
		}
	}
}


void S_Frame::Draw() const
{
	if (f_count == 0)
	{
		DrawRotaGraph(location.x, location.y, 1, 1, image, TRUE);
	}
	DrawRotaGraph(location.x, location.y, f_size, 1, images[f_count], TRUE);
}

void S_Frame::Finalize()
{

}

void S_Frame::Explosion(bool h_flg)
{
	f_flg = h_flg;
}

Vector2D S_Frame::GetLocation() const
{
	return Vector2D(this->location);
}

Vector2D S_Frame::GetBoxSize() const
{
	return Vector2D(box_size);
}

int S_Frame::GetDamage() const
{
	return int(damage);
}

int S_Frame::GetF_Count()
{
	return f_count;
}

bool S_Frame::GetF_Flg()
{
	return f_flg;
}
