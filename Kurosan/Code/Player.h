#pragma once

#include"../Utility/Vector2D.h"

class Player
{
private:
	int image;				//�`�悷��摜�f�[�^
	int exp;				// �o���l
	int need_exp;			// ���x���A�b�v�K�vEXP
	int level;				// ���x��
	Vector2D location;		//�ʒu���W
	Vector2D box_size;		//�����蔻��̑傫��
	float speed;			// �X�s�[�h

public:
	Player();
	~Player();

	void Initialize();    //����������
	void Update();        //�X�V����
	void Draw();          //�`�揈��
	void Finalize();      //�I��������

public:
	Vector2D GetLocation() const;  //�ʒu���W�擾
	Vector2D GetBoxSize()const;    //�����蔻��̑傫���擾
	void Movement();
	int GetLevel();				   // �v���C���[���x���̎擾
	int GetExp();				   // �o���l�̎擾
	int RcvExp(int exp);		   // �o���l�̎��
	bool Levelup();				   // ���x���A�b�v
};
