#pragma once

#include"../Utility/Vector2D.h"
#include"Barrier.h"

class Player
{
private:
	bool is_active;			//�L����Ԃ�?
	int image;				//�`�悷��摜�f�[�^
	Vector2D location;		//�ʒu���W
	Vector2D box_size;		//�����蔻��̑傫��
	float angle;			//�p�x
	float speed;			//����
	float hp;				//�̗�
	float fuel;				//�R��
	int barrier_count;		//�o���A�̖���
	Barrier* barrier;		//�o���A

	int images[20];			//�摜�f�[�^
	int situation;			//�v���C���[�̏��
	bool hit;				//�q�b�g�������̔���
	bool red;				//�Ԃ��_�ł��邩�̔���

	float run_span;			//����摜�̐ؑ֊Ԋu
	float hit_span;			//�q�b�g�摜�̐ؑ֊Ԋu
	float jump_span;		//�W�����v�L������
	float sliding_span;		//�X���C�f�B���O�L������

	float invincibletime;	//���G����

public:
	Player();
	~Player();

	void Initialize();    //����������
	void Update();        //�X�V����
	void Draw();          //�`�揈��
	void Finalize();      //�I��������

public:
	void SetActive(bool flg);      //�L���t���O�ݒ�
	void DecreaseHp(float value);  //�̗͌�������
	void GetKey();		   //���擾
	Vector2D GetLocation() const;  //�ʒu���W�擾
	Vector2D GetBoxSize()const;    //�����蔻��̑傫���擾
	float GetSpeed()const;         //�����擾����
	float GetFuel()const;          //�R���擾
	float GetHp()const;            //�̗͎擾
	int GetBarriarCount()const;    //�o���A�̖����擾
	bool IsBarrier()const;         //�o���A�L����?���擾

	bool IsJump()const;				//�W�����v�̐^�U���擾
	bool IsSliding()const;			//�X���C�f�B���O�̐^�U���擾
	bool IsCarMode();				//�ԃ��[�h�̐^�U���擾
	bool IsInvincible();			//���G��Ԃ̐^�U���擾

private:
	void Movement();       //�ړ�����
	void Acceleration();   //��������
	
	void Jump();			//�W�����v����
	void Sliding();			//�X���C�f�B���O����
	void RunAnimation();	//����A�j���[�V����
	void HitAnimation();	//�q�b�g�A�j���[�V����
	void JumpAnimation();	//�W�����v�A�j���[�V����
};

