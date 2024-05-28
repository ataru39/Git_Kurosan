#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene()
{
	enemymax = 5;

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

//初期化処理
void GameMainScene::Initialize()
{
	grace = LoadGraph("Resources/Images/background_grace.png");

	player->Initialize();
	wall->Initialize();
	ui->Initialize();
}

//更新処理
eSceneType GameMainScene::Update()
{
	player->Update();
	wall->Update();
	ui->Update();

	//敵生成
	if (e_delay <= 0) {								//間隔
		for (int i = 0; i < enemymax; i++) {		//作る上限
			if (enemy[i] == nullptr)				//配列enemyの中が空の時
			{
				enemy[i] = new Enemy();				//空の配列にエネミーを作る
				enemy[i]->Initialize();				//初期化処理
				e_delay = 60;						//敵を作る間隔
				break;								//forループから抜ける
			}
		}
	}

	// クールタイム減少処理
	if (e_delay > 0)
	{
		e_delay--;
	}

	//敵の更新
	for (int i = 0; i < enemymax; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Update();
		}
	}

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

	//敵と弾の当たり判定
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

	//敵と壁の当たり判定
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

//描画処理
void GameMainScene::Draw()const
{
	//背景画像
	for (int g = 0; g < 1281; g = g + 128) {
		for (int z = 0; z < 751; z = z + 71) {
			DrawRotaGraph(g, z, 2.0, 0, grace, FALSE);
		}
	}
	
	ui->Draw();
	wall->Draw();
	player->Draw();

	//敵の描画
	for (int i = 0; i < enemymax; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	//弾の描画
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw();
		}
	}

}

//終了時処理
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

//現在のシーン情報を取得
eSceneType GameMainScene::GetNowScene()const
{
	return eSceneType::E_MAIN;
}
