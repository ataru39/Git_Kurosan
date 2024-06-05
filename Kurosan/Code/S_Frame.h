#pragma once

#include "Skill.h"
#include "Enemy.h"

class S_Frame : public Skill
{
public:
	S_Frame();
	virtual ~S_Frame();

	virtual void Initialize(Vector2D p_location);
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual Vector2D GetLocation() const override;
	virtual Vector2D GetBoxSize() const override;
	virtual int GetDamage() const override;
};
