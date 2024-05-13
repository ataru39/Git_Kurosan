#pragma once

#include"../Utility/Vector2D.h"

class Skill
{
protected:
	int image;			// �摜
	Vector2D location;	// �ʒu���W
	Vector2D p_location;// �v���C���[�̍��W
	Vector2D box_size;	// �����蔻��̑傫��
	float speed;		// �X�L���̑��x
	float cool_time;	// �X�L���N�[���^�C��
	float damage;		// �_���[�W
	int pen_pow;		// �ђʗ�(penetration_power)

public:
	Skill() { };
	virtual ~Skill() { };

	virtual void Initialize() { };	// ����������
	virtual void Update() { };		// �X�V����
	virtual void Draw() const { };	// �`�揈��
	virtual void Finalize() { };	// �I��������

	virtual Vector2D GetLocation() const	    //�ʒu���W�擾
	{
		return Vector2D();
	}
	virtual Vector2D GetBoxSize() const     //�����蔻��̑傫���擾
	{
		return Vector2D();
	}
	virtual Vector2D GetCoolTime() const  //�����蔻��̑傫���擾
	{
		return Vector2D();
	}
	virtual int GetDamage() const		//�����蔻��̑傫���擾
	{
		return int();
	}
};