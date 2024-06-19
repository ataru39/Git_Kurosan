#pragma once

#include"../Utility/Vector2D.h"
#define ENEMY_MAX 100

class Enemy
{
private:
	int type;            //�^�C�v
	int image,image_g,image_m;			//�ʏ�摜
	int image2, image_g2, image_m2;		//�_���[�W�摜
	float speed;         //����
	Vector2D location;   //�ʒu���
	Vector2D box_size;   //�����蔻��̑傫��
	int hp;				 // HP
	bool dmgflg;		 //�_���[�W���󂯂���
	int dmgcnt;			 //�_���[�W�J�E���^�[	
	int reverse;
	int dmg;
	bool atk_flg;
	int delay;
	bool angflg;
	int angcnt;
	int exp;
	int e_type[4][5];



public:
	Enemy();
	~Enemy();

	void Initialize(int minute,int plevel);          //����������
	void Update();   //�X�V����
	void Draw()const;           //�`�揈��
	void Finalize();            //�I��������
	void Movement();			//�ړ�����
	void Spawn();

	Vector2D GetLocation();    //�ʒu���̎擾
	Vector2D GetBoxSize()const;     //�����蔻��̑傫�����擾
	int GetHP();					// HP�̎擾
	void Damage(int damage);		// �_���[�W����
	int GetDamage()const;
	bool GetAtkFlg();
	void ChengeAtkFlg(bool flg);
	int GetExp();					// �o���l�̎擾
};