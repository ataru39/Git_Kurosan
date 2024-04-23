#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene()
{
	wall = new Wall;
	player = new Player;
	
}

GameMainScene::~GameMainScene()
{
	delete wall;
	delete player;
}

//初期化処理
void GameMainScene::Initialize()
{
	player->Initialize();
	wall->Initialize();
}

//更新処理
eSceneType GameMainScene::Update()
{	
	player->Update();
	wall->Update();

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
