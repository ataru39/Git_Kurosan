#include "Skill.h"
#include "Dxlib.h"

Skill::Skill()
{
	image = 0;
	location = Vector2D(0.0f, 0.0f);
	box_size = Vector2D(50.0f, 50.0f);
	spawn_location = Vector2D(0.0f, 0.0f);
}

Skill::~Skill()
{
}

void Skill::Initialize()
{
}

void Skill::Update()
{
}

void Skill::Draw()
{
}

void Skill::Finalize()
{
}

Vector2D Skill::GetLocation() const
{
	return Vector2D();
}

Vector2D Skill::GetBoxSize() const
{
	return Vector2D();
}

Vector2D Skill::GetCoolTime() const
{
	return Vector2D();
}
