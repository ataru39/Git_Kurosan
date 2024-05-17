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
	speed = 7.0f;
	damage = 10.0f;
}

void S_21Fist::Update()
{

}

void S_21Fist::Draw() const
{

}
