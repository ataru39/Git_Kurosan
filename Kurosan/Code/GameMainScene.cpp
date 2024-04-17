#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene()
{
	wall = new Wall;
}

GameMainScene::~GameMainScene()
{
	delete wall;
}

//初期化処理
void GameMainScene::Initialize()
{

}

//更新処理
eSceneType GameMainScene::Update()
{
	return GetNowScene();
}

//描画処理
void GameMainScene::Draw()const
{
	wall->Draw();
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
