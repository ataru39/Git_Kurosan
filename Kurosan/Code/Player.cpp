#include "Player.h"
#include "../Utility/InputControl.h"
#include "Dxlib.h"
#include"stdio.h"
#define PI    3.1415926535897932384626433832795f


Player::Player()
{
	image = LoadGraph("Resources/Images/wizard.png");
	LoadDivGraph("Resources/Images/kamifubuki.png",12,1,12,1920,480,l_image);

}

Player::~Player()
{

}

//����������
void Player::Initialize()
{
	location = Vector2D(80.0f, 410.0f);
	box_size = Vector2D(50.0f, 100.0f);

	// EXP�̏�����
	exp = 0;
	// ���x���A�b�v�K�vEXP�̏�����
	need_exp = 5;
	// ���x��������
	level = 1;
	// �X�s�[�h������
	speed = 7.5f;
}

//�X�V����
void Player::Update()
{
	Movement();
	if (Levelup())
	{
		PlaySoundMem(levelsound, DX_PLAYTYPE_NORMAL, TRUE);
	}
}

//�`�揈��
void Player::Draw()
{
	DrawRotaGraph(location.x, location.y, 2, PI / 2, image, TRUE);

	if (Levelup() == true)
	{
		for(int i=0;i<11;i++)
		{
			DrawGraph(0, 0, l_image[i], TRUE);
		}
	}
}

//�I��������
void Player::Finalize()
{
	DeleteGraph(image);
	for (int i = 0; i < 11; i++) {
		DeleteGraph(l_image[i]);
	}
}

//�ʒu���擾����
Vector2D Player::GetLocation()const
{
	return this->location;
}

Vector2D Player::GetBoxSize()const
{
	return this->box_size;
}

//�ړ�����
void Player::Movement()
{
	Vector2D move = Vector2D(0.0f);

	if (InputControl::GetLeftStick().y > 0.2 && location.y < 670)
	{
		move += Vector2D(0.0f, +speed);
	}

	if (InputControl::GetLeftStick().y < -0.2 && location.y > 150)
	{
		move += Vector2D(0.0f, -speed);
	}

		location += move;
}

int Player::GetLevel()
{
	return this->level;
}

int Player::GetExp()
{
	return this->exp;
}

int Player::RcvExp(int exp)
{
	return this->exp += exp;
}

bool Player::Levelup()
{
	if (exp >= need_exp && level < 11)
	{
		// ���x���A�b�v
		level += 1;
		// ���x���A�b�v�K�vEXP�㏸
		need_exp += 5;
		// EXP���[���ɂ���
		exp = 0;

		return true;
	}
	return false;
}
