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

//‰Šú‰»ˆ—
void GameMainScene::Initialize()
{
	grace = LoadGraph("Resources/Images/background_grace.png");

	player->Initialize();
	wall->Initialize();
	ui->Initialize();
}

//XVˆ—
eSceneType GameMainScene::Update()
{
	player->Update();
	wall->Update();
	ui->Update();

	//“G¶¬
	if (e_delay <= 0) {
		for (int i = 0; i < enemymax; i++) {
			if (enemy[i] == nullptr)
			{
				enemy[i] = new Enemy();
				enemy[i]->Initialize();
				e_delay = 60;
				break;
			}
		}
	}

	// ƒN[ƒ‹ƒ^ƒCƒ€Œ¸­ˆ—
	if (e_delay > 0)
	{
		e_delay--;
	}

	//“G‚ÌXV
	for (int i = 0; i < enemymax; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Update();
		}
	}

	// ’e¶¬ˆ—
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


	// ƒN[ƒ‹ƒ^ƒCƒ€Œ¸­ˆ—
	if (b_cooltime > 0)
	{
		b_cooltime--;
	}

	// ’e‚ÌXVˆ—
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Update();
		}
	}

	// ’e‚ÌÁ‹ˆ—i‰¼j
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

	//“G‚Æ’e‚Ì“–‚½‚è”»’è
	for (int i = 0; i < enemymax; i++) {
		if (enemy[i] != nullptr) {
			for (int j = 0; j < 10; j++)
			{
				if (bullet[j] != nullptr) {
					if (BhitCheck(enemy[i], bullet[j])) {
						enemy[i]->Damage(bullet[j]->GetDamage());
						bullet[j] = nullptr;
						delete bullet[j];
						if(enemy[i]->GetHP() <= 0)
						{
							enemy[i] = nullptr;
							delete enemy[i];
						}
						break;
					}
				}
			}
		}
	}

	//“G‚Æ•Ç‚Ì“–‚½‚è”»’è
	for (int i = 0; i < enemymax; i++) {
		if (enemy[i] != nullptr && enemy[i]->GetAtkFlg()!=true) {
			if (WhitCheck(enemy[i], wall)) {
				enemy[i]->ChengeAtkFlg(true);
				wall->Damage(enemy[i]->GetDamage());
			}
		}
	}

	return GetNowScene();
}

//•`‰æˆ—
void GameMainScene::Draw()const
{
	//”wŒi‰æ‘œ
	for (int g = 0; g < 1281; g = g + 128) {
		for (int z = 0; z < 751; z = z + 71) {
			DrawRotaGraph(g, z, 2.0, 0, grace, FALSE);
		}
	}
	
	ui->Draw();
	wall->Draw();
	player->Draw();

	//“G‚Ì•`‰æ
	for (int i = 0; i < enemymax; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	//’e‚Ì•`‰æ
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw();
		}
	}

}

//I—¹ˆ—
void GameMainScene::Finalize()
{

}

bool GameMainScene::WhitCheck(Enemy* e,Wall* w)
{
	Vector2D diff_location = e->GetLocation() - w->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + w->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

bool GameMainScene::BhitCheck(Enemy* e, S_Bullet* b)
{
	Vector2D diff_location = e->GetLocation() - b->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + b->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

//Œ»İ‚ÌƒV[ƒ“î•ñ‚ğæ“¾
eSceneType GameMainScene::GetNowScene()const
{
	return eSceneType::E_MAIN;
}
