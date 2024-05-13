#pragma once

#include "Skill.h"

class S_Bullet : public Skill
{
public:
	S_Bullet();
	virtual ~S_Bullet();

	virtual void Initialize(Vector2D p_location);
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual Vector2D GetLocation() const override;
	virtual Vector2D GetBoxSize() const override;
	virtual int GetDamage() const override;
};
