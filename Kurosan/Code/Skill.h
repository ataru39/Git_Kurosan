#pragma once

#include"../Utility/Vector2D.h"

class Skill
{
protected:
	int image;			// �摜
	Vector2D location;	// �ʒu���W
	Vector2D box_size;	// �����蔻��̑傫��
	Vector2D spawn_location;  // �X�|�[���ʒu
	float speed;		// �X�L���̑��x
	float cool_time;	// �X�L���N�[���^�C��
	float damage;		// �_���[�W

public:
	Skill();
	~Skill();

	void Initialize();	// ����������
	void Update();		// �X�V����
	void Draw();		// �`�揈��
	void Finalize();	// �I��������

	Vector2D GetLocation() const;   //�ʒu���W�擾
	Vector2D GetBoxSize() const;    //�����蔻��̑傫���擾
	Vector2D GetCoolTime() const;   //�����蔻��̑傫���擾
	Vector2D GetDamageTime() const; //�����蔻��̑傫���擾
};
