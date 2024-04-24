#include "Player.h"
#include "../Utility/InputControl.h"
#include "Dxlib.h"

Player::Player()
{
	image = LoadGraph("Resources/Images/PTamesi.png");
}

Player::~Player()
{

}

//����������
void Player::Initialize()
{
	location = Vector2D(140.0f, 260.0f);
	box_size = Vector2D(50.0f, 50.0f);
	level = 1;
}

//�X�V����
void Player::Update()
{
	Movement();
}

//�`�揈��
void Player::Draw()
{
	DrawGraph(location.x, location.y, image, TRUE);
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
		move += Vector2D(0.0f, +3.0f);
	}

	if (InputControl::GetLeftStick().y < -0.2 && location.y > 100)
	{
		move += Vector2D(0.0f, -3.0f);
	}
	//if (location.y < 100)
	//{
	//	location.y = 100;
	//}
	//if (location.y > 1230)
	//{
	//	location.y = 1230;
	//}

		location += move;
}

void Player::LevelUP()
{
	if (InputControl::GetButton(XINPUT_BUTTON_B)==TRUE)
	{
		level++;

	}
}
