#pragma once

#include "Skill.h"

class S_Bullet : public Skill
{
private:

public:
	S_Bullet();
	virtual ~S_Bullet();

	virtual void Initialize(Vector2D p_location);
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual Vector2D GetLocation() const override;
	virtual Vector2D GetBoxSize() const override;
	//virtual Vector2D GetCoolTime() const override;
	virtual Vector2D GetDamage() const override;
};
