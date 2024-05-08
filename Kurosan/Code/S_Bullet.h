#pragma once

#include "Skill.h"

class S_Bullet : public Skill
{
private:
	int type;            //�^�C�v
	int image;           //�摜
	float speed;         //����
	Vector2D location;   //�ʒu���
	Vector2D box_size;   //�����蔻��̑傫��

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
