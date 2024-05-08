#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene()
{
	enemymax = 100;

	wall = new Wall;
	player = new Player;
	ui = new UI;
	enemy = new Enemy * [enemymax];
	for (int i = 0; i < enemymax; i++) {
		enemy[i] = nullptr;
	}

	bullet = new S_Bullet * [10];
	for (int i = 0; i < 10; i++)
	{
		bullet[i] = nullptr;
	}
	e_delay = 0;
	b_cooltime = 0;
}

GameMainScene::~GameMainScene()
{
	delete wall;
	delete player;
	delete enemy;
	delete ui;
	delete bullet;
}

//����������
void GameMainScene::Initialize()
{
	player->Initialize();
	wall->Initialize();
	ui->Initialize();
}

//�X�V����
eSceneType GameMainScene::Update()
{
	player->Update();
	wall->Update();
	ui->Update();

	//�G����
	if (e_delay <= 0) {
		for (int i = 0; i < enemymax; i++) {
			if (enemy[i] == nullptr)
			{
				enemy[i] = new Enemy();
				enemy[i]->Initialize();
				e_delay = 10;
				break;
			}
		}
	}

	// �N�[���^�C����������
	if (e_delay > 0)
	{
		e_delay--;
	}

	//�G�̍X�V
	for (int i = 0; i < enemymax; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Update();
		}
	}

	// �e��������
	if (b_cooltime <= 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (bullet[i] == nullptr)
			{
				bullet[i] = new S_Bullet();
				bullet[i]->Initialize(player->GetLocation());
				b_cooltime = 90;
				break;
			}
		}
	}


	// �N�[���^�C����������
	if (b_cooltime > 0)
	{
		b_cooltime--;
	}

	// �e�̍X�V����
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Update();
		}
	}

	// �e�̏��������i���j
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			b_location = bullet[i]->GetLocation();
			if (b_location.x > 1300)
			{
				bullet[i] = nullptr;
			}
		}
	}

	if (HitCheck(player, wall)) {
		DrawString(300, 500, "ataridesuyogohandesuyo", 0x000000);
	}

	return GetNowScene();
}

//�`�揈��
void GameMainScene::Draw()const
{
	wall->Draw();
	player->Draw();
	ui->Draw();

	//�G�̕`��
	for (int i = 0; i < enemymax; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	//�e�̕`��
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw();
		}
	}

	DrawBox(0, 0, 1280, 100, 0xff0000, TRUE);
}

//�I��������
void GameMainScene::Finalize()
{

}

bool GameMainScene::HitCheck(Player* p,Wall* w)
{
	Vector2D diff_location = p->GetLocation() - w->GetLocation();
	Vector2D box_ex = p->GetBoxSize() + w->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

//���݂̃V�[�������擾
eSceneType GameMainScene::GetNowScene()const
{
	return eSceneType::E_MAIN;
}
