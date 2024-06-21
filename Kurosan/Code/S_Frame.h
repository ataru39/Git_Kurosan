#pragma once

#include "Skill.h"
#include "Enemy.h"

class S_Frame : public Skill
{
public:
	S_Frame();
	virtual ~S_Frame();

	Vector2D destination_location; //–Ú“I’n
	Vector2D movement_vector;

	virtual void Initialize(Vector2D p_location, Vector2D e_location);
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	void Explosion(bool h_flg);

	virtual Vector2D GetLocation() const override;
	virtual Vector2D GetBoxSize() const override;
	virtual int GetDamage() const override;
	int GetF_Count();
	bool GetF_Flg();

	int f_count;

private:
	int images[7];

	float f_size;
	int delay;
	int a;
	bool f_flg;
};
