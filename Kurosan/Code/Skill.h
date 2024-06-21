#pragma once

#include"../Utility/Vector2D.h"
#define PI    3.1415926535897932384626433832795f

class Skill
{
protected:
	int image;			 // �摜
	Vector2D location;	 // �ʒu���W
	Vector2D p_location; // �v���C���[�̍��W
	Vector2D box_size;	 // �����蔻��̑傫��
	float speed;		 // �X�L���̑��x
	float damage;		 // �_���[�W

public:
	Skill() { };
	virtual ~Skill() { };

	virtual void Initialize() { };	// ����������
	virtual void Update() { };		// �X�V����
	virtual void Draw() const { };	// �`�揈��
	virtual void Finalize() { };	// �I��������

	virtual Vector2D GetLocation() const	//�ʒu���W�擾
	{
		return Vector2D();
	}
	virtual Vector2D GetBoxSize() const     //�����蔻��̑傫���擾
	{
		return Vector2D();
	}
	virtual Vector2D GetCoolTime() const	//�����蔻��̑傫���擾
	{
		return Vector2D();
	}
	virtual int GetDamage() const			//�����蔻��̑傫���擾
	{
		return int();
	}
};