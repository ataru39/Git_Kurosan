#include "Player.h"
#include "../Utility/InputControl.h"
#include "Dxlib.h"

Player::Player()
{

}

Player::~Player()
{

}

//����������
void Player::Initialize()
{
	location = Vector2D(140.0f, 260.0f);
}

//�X�V����
void Player::Update()
{

}

//�`�揈��
void Player::Draw()
{

}

//�I��������
void Player::Finalize()
{

}

//�ʒu���擾����
Vector2D Player::GetLocation()const
{
	return this->location;
}

//�ړ�����
void Player::Movement()
{
	Vector2D move = Vector2D(0.0f);

	if (InputControl::GetLeftStick().y<0.2)
	{
		move -= Vector2D(0.0f, -3.0f);
	}

	if (InputControl::GetLeftStick().y<-0.2)
	{
		move += Vector2D(0.0f, +3.l0f);
	}
}
