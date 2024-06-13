#include "S_Frame.h"
#include "Enemy.h"
#include "DxLib.h"
#include <cmath>

S_Frame::S_Frame()
{
	image = LoadGraph("Resources/Images/F5.png");
	LoadDivGraph("Resources/Images/Flames.png", 7, 7, 1, 50, 50, images);
}

S_Frame::~S_Frame()
{

}

void S_Frame::Initialize(Vector2D p_location,Vector2D e_location)
{
	location = p_location;
	box_size = Vector2D(1.0f, 1.0f);
	speed = 12.0f;
	damage = 10.0f;

	f_count = 0;
	f_size = 1.0f;
	delay = 5;
	a = 0.2;

	destination_location += e_location;
}

void S_Frame::Update()
{
	Vector2D movement_vector = destination_location - location;

	/*ƒxƒNƒgƒ‹‚Ì³‹K‰»*/
	float distance = std::sqrtf(std::powf(movement_vector.x, 2) + (movement_vector.y, 2));
	movement_vector.x *= (1 / distance);
	movement_vector.y *= (1 / distance);

	location += movement_vector * speed;

	//“–‚½‚Á‚½‚ç”š”­
	if (delay > 0) {
		delay--;
		if (delay <= 0) {
			for (f_size = 1; f_size <= 2.4; f_size+=a) {
				f_count++;
				f_size++;
			}
			delay = 5;
		}
	}

	

	
}

void S_Frame::Draw() const
{
	DrawRotaGraph(location.x, location.y, f_size, 1, images[f_count], TRUE);
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