#include "Enemy.h"
#include "DxLib.h"

Enemy::Enemy() :type(0), image(0), speed(0.0f), location(0.0f), box_size(0.0f)
{
	image = LoadGraph("Resources/Images/Slime.png");

	enemymax = 10;
}

Enemy::~Enemy()
{

}

//����������
void Enemy::Initialize()
{
	//�o��������X���W�p�^�[�����擾
	float random_y = (float)(GetRand(4) * 105 + 40);
	//�����ʒu�̐ݒ�
	location = Vector2D(1300.0f, random_y);
	//�����蔻��̐ݒ�
	box_size = Vector2D(31.0f, 60.0f);
	//�����̐ݒ�
	speed = 2.0f;

}

void Enemy::Update()
{
	//�ʒu���Ɉړ��ʂ����Z����
	location += Vector2D(-speed , 0.0f);
	for (int i = 0; i < enemymax; i++) {
	}

	if (location.x <= 200) {
		location.x = 200;
	}
}

void Enemy::Draw()const
{
	//�G�摜��`��
	//DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE);
	
	DrawGraph(location.x, location.y, image, TRUE);
}

void Enemy::Finalize()
{
	DeleteGraph(image);
}

void Enemy::Movement()
{

}

void Enemy::Spawn()
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