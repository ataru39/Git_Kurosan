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
}

//更新処理
eSceneType GameMainScene::Update()
{
	player->Update();

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

//現在のシーン情報を取得
eSceneType GameMainScene::GetNowScene()const
{
	return eSceneType::E_MAIN;
}
