#include "Player.h"
#include "../Utility/InputControl.h"
#include "Dxlib.h"
#include"stdio.h"
#define PI    3.1415926535897932384626433832795f


Player::Player()
{
	image = LoadGraph("Resources/Images/wizard.png");
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
	speed = 4.0f + level * 4;
}

//�X�V����
void Player::Update()
{
	Movement();
}

//�`�揈��
void Player::Draw()
{
	DrawRotaGraph(location.x, location.y, 2, PI / 2, image, TRUE);
}

//�I��������
void Player::Finalize()
{
	DeleteGraph(image);
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
	if (exp >= need_exp)
	{
		// ���x���A�b�v
		level += 1;
		// ���x���A�b�v�K�vEXP�㏸
		need_exp += 5;
		// EXP���[���ɂ���
		exp = 0;

		return true;
	}
}
