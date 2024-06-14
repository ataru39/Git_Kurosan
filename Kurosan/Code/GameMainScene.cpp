#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>
#include "../Utility/InputControl.h"

GameMainScene::GameMainScene()
{
	// 敵の生成上限数
	enemymax = 200;

	// オブジェクトの生成
	wall = new Wall;
	player = new Player;
	ui = new UI;
	enemy = new Enemy * [enemymax];

	// 敵オブジェクト配列の初期化
	for (int i = 0; i < enemymax; i++) {
		enemy[i] = nullptr;
	}

	// 弾オブジェクト
	bullet = new S_Bullet * [10];
	// 初期化
	for (int i = 0; i < 10; i++)
	{
		bullet[i] = nullptr;
	}

	// 拳オブジェクト
	fist = new S_21Fist * [10];
	// 初期化
	for (int i = 0; i < 10; i++)
	{
		fist[i] = nullptr;
	}

	// 炎オブジェクト
	frame = new S_Frame * [10];
	// 初期化
	for (int i = 0; i < 10; i++)
	{
		frame[i] = nullptr;
	}

	// 敵のスポーンディレイ初期化
	e_delay = 0;
	// 弾のクールタイム初期化
	b_cooltime = 0;
	// 拳のクールタイム初期化
	f_cooltime = 0;

}

GameMainScene::~GameMainScene()
{
	delete wall;
	delete player;
	delete enemy;
	delete ui;
	delete bullet;
	delete fist;
	delete frame;
}

// 初期化処理
void GameMainScene::Initialize()
{
	grace = LoadGraph("Resources/Images/background_grace.png");
	sound = LoadSoundMem("Resources/Images/Sounds/ファンタジー4-進展-.mp3");

	player->Initialize();
	wall->Initialize();
	ui->Initialize();
}

// 更新処理
eSceneType GameMainScene::Update()
{
	player->Update();
	wall->Update();
	ui->Update();

	// 敵の生成
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

	// 敵の生成ディレイ減少
	if (e_delay > 0)
	{
		e_delay--;
	}

	// 敵の更新
	for (int i = 0; i < enemymax; i++) {
		if (enemy[i] != nullptr) {
			enemy[i]->Update();
		}
	}

	// 弾生成
	if (b_cooltime <= 0)
	{
		for (int i = 0; i < 10; i++)
		{
			if (bullet[i] == nullptr)
			{
				bullet[i] = new S_Bullet();
				bullet[i]->Initialize(player->GetLocation(), player->GetLevel());
				b_cooltime = 60 - player->GetLevel();
				break;
			}
		}
	}

	// 弾クールタイム減少処理
	if (b_cooltime > 0)
	{
		b_cooltime--;
	}

	// 拳生成処理
	if (player->GetLevel() > 3) {
		if (f_cooltime <= 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (fist[i] == nullptr)
				{
					fist[i] = new S_21Fist();
					fist[i]->Initialize(player->GetLocation());
					f_cooltime = 300;
					break;
				}
			}
		}
	}

	// クールタイム減少処理
	if (f_cooltime > 0)
	{
		f_cooltime--;
	}

	// 炎生成処理
	if (player->GetLevel() > 4) {
		if (h_cooltime <= 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (frame[i] == nullptr)
				{
					frame[i] = new S_Frame();
					frame[i]->Initialize(player->GetLocation(), enemy[i]->GetLocation());
					h_cooltime = 60;
					break;
				}
			}
		}
	}

	// クールタイム減少処理
	if (h_cooltime > 0)
	{
		h_cooltime--;
	}

	// 弾の更新処理
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Update();
		}
	}

	// 拳の更新処理
	for (int i = 0; i < 10; i++)
	{
		if (fist[i] != nullptr)
		{
			fist[i]->Update();
		}
	}

	// 炎の更新処理
	for (int i = 0; i < 10; i++)
	{
		if (frame[i] != nullptr)
		{
			frame[i]->Update();
		}
	}

	// 弾の消去処理（仮）
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i] != nullptr)
		{
			if (bullet[i]->GetLocation().x > 1300)
			{
				bullet[i] = nullptr;
			}
		}
	}

	//拳の削除処理
	for (int i = 0; i < 10; i++)
	{
		if (fist[i] != nullptr)
		{
			f_location = fist[i]->GetLocation();
			if (fist[i]->FadeOut() <= 0) {
				fist[i] = nullptr;
			}
		}
	}

	// 炎の消去処理（仮）
	for (int i = 0; i < 10; i++)
	{
		if (frame[i] != nullptr)
		{
			if (frame[i]->GetLocation().x > 1300)
			{
				frame[i] = nullptr;
			}
		}
	}

	//敵と弾の当たり判定
	for (int i = 0; i < enemymax; i++) {
		if (enemy[i] != nullptr) {
			for (int j = 0; j < 10; j++)
			{
				if (bullet[j] != nullptr) {
					if (BhitCheck(enemy[i], bullet[j])) { // 敵と弾が接触した時
						enemy[i]->Damage(bullet[j]->GetDamage());// 敵にダメージを与える
						bullet[j] = nullptr;
						delete bullet[j];
						if (enemy[i]->GetHP() <= 0) // 敵が死んだとき
						{
							player->RcvExp(enemy[i]->GetExp());	// プレイヤーにEXPを渡す
							is_levelup = player->Levelup();
							enemy[i] = nullptr;
							delete enemy[i];
						}
						break;
					}
				}

				if (fist[j] != nullptr) {
					//fist[i]->Level(player->GetLevel());
					if (FhitCheck(enemy[i], fist[j])) {
						enemy[i]->Damage(fist[j]->GetDamage());
						if (enemy[i]->GetHP() <= 0)
						{
							player->RcvExp(enemy[i]->GetExp());	// プレイヤーにEXPを渡す
							is_levelup = player->Levelup();
							enemy[i] = nullptr;
							delete enemy[i];
						}
						break;
					}
				}

				if (frame[j] != nullptr) {
					if (HhitCheck(enemy[i], frame[j])) {
						enemy[i]->Damage(frame[j]->GetDamage());
						frame[j] = nullptr;
						delete frame[j];
						if (enemy[i]->GetHP() <= 0)				// 敵が死んだとき
						{
							player->RcvExp(enemy[i]->GetExp());	// プレイヤーにEXPを渡す
							is_levelup = player->Levelup();
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
		if (enemy[i] != nullptr && enemy[i]->GetAtkFlg() != true) {
			if (WhitCheck(enemy[i], wall)) {
				enemy[i]->ChengeAtkFlg(true);
				wall->Damage(enemy[i]->GetDamage());
			}
		}
	}

	// レベルアップした時
	if (is_levelup)
	{
		Levelup();
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

	//拳の描画
	for (int i = 0; i < 10; i++)
	{
		if (fist[i] != nullptr)
		{
			fist[i]->Draw();
		}
	}

	//炎の描画
	for (int i = 0; i < 10; i++)
	{
		if (frame[i] != nullptr)
		{
			frame[i]->Draw();
		}
	}

	// レベルとEXP
	DrawFormatString(0, 0, 0x000000, "%d", player->GetExp());
	DrawFormatString(0, 15, 0x000000, "%d", player->GetLevel());
}

//終了時処理
void GameMainScene::Finalize()
{

}

bool GameMainScene::WhitCheck(Enemy* e, Wall* w)
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

bool GameMainScene::FhitCheck(Enemy* e, S_21Fist* f)
{
	Vector2D diff_location = e->GetLocation() - f->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + f->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

bool GameMainScene::HhitCheck(Enemy* e, S_Frame* h)
{
	Vector2D diff_location = e->GetLocation() - h->GetLocation();
	Vector2D box_ex = e->GetBoxSize() + h->GetBoxSize();
	return ((fabsf(diff_location.x) < box_ex.x) && (fabsf(diff_location.y) < box_ex.y));
}

//現在のシーン情報を取得
eSceneType GameMainScene::GetNowScene()const
{
	return eSceneType::E_MAIN;
}

void GameMainScene::Levelup()
{
	e_delay -= player->GetLevel() * 2;
	is_levelup = false;
}