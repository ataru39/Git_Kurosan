#pragma once

#include "Skill.h"
#include "DxLib.h"

class S_21Fist :public Skill
{
public:
	S_21Fist();
	virtual~S_21Fist();

	virtual void Initialize(Vector2D p_location);
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual Vector2D GetLocation() const override;
	virtual Vector2D GetBoxSize() const override;
	virtual int GetDamage() const override;
	
	void R_Fist();
	void L_Fist();
	int FadeOut();
	int Level(int level);
	int GetLevel();

private:
	int bright_fadeout;
	float kaiten;
	float kaiten2;
	int image2;
	int level;
	bool atk;
};