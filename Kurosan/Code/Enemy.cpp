#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy() :type(0), image(0), speed(0.0f), location(0.0f), box_size(0.0f)
{
	image = LoadGraph("Resources/Images/�X���C��.png");
}

Enemy::~Enemy()
{

}

//����������
void Enemy::Initialize()
{
	//�o��������X���W�p�^�[�����擾
	float random_x = (float)(GetRand(4) * 105 + 40);
	//�����ʒu�̐ݒ�
	location = Vector2D(random_x, 1290.0f);
	//�����蔻��̐ݒ�
	box_size = Vector2D(31.0f, 60.0f);
	//�����̐ݒ�
	speed = 2.0f;

}

void Enemy::Update()
{
	//�ʒu���Ɉړ��ʂ����Z����
	location += Vector2D(-speed , 0.0f);
}

void Enemy::Draw()const
{
	//�G�摜��`��
	//DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);

	DrawGraph(location.x, 1200,image,TRUE);
}

void Enemy::Finalize()
{
	DeleteGraph(image);
}

void Enemy::Movement()
{

}

//�G�^�C�v���擾
int Enemy::GetType()const
{
	return type;
}

//�ʒu�����擾
Vector2D Enemy::GetLocation()const
{
	return location;
}

//�����蔻��̑傫�����擾
Vector2D Enemy::GetBoxSize()const
{
	return box_size;
}