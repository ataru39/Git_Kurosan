#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene()
{
	wall = new Wall;
	player = new Player;
	enemy = new Enemy;
	ui = new UI;
	bullet = new S_Bullet * [10];
	for (int i = 0; i < 10; i++)
	{
		bullet[i] = nullptr;
	}

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

//初期化処理
void GameMainScene::Initialize()
{
	player->Initialize();
	wall->Initialize();
	enemy->Initialize();
	ui->Initialize();
}

//更新処理
eSceneType GameMainScene::Update()
{
	player->Update();
	wall->Update();
	enemy->Update();
	ui->Update();

	// 弾生成処理
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

	// クールタイム減少処理
	if (b_cooltime > 0)
	{
		b_cooltime--;
	}

	// 弾の更新処理
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Update();
		}
	}

	// 弾の消去処理（仮）
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

//描画処理
void GameMainScene::Draw()const
{
	wall->Draw();
	player->Draw();
	enemy->Draw();
	ui->Draw();

	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw();
		}
	}

	DrawBox(0, 0, 1280, 100, 0xff0000, TRUE);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
}

//終了時処理
void GameMainScene::Finalize()
{

}

bool GameMainScene::HitCheck(Player* p,Wall* w)
{
	Vector2D diff_location = p->GetLocation() - w->GetLocation();
	Vector2D box_ex = p->GetBoxSize() + w->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

//現在のシーン情報を取得
eSceneType GameMainScene::GetNowScene()const
{
	return eSceneType::E_MAIN;
}
