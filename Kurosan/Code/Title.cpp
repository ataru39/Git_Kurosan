#include "Title.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

Title::Title()
{
	title_c = LoadGraph("Resources/Images/title_C.png");
	title_g = LoadGraph("Resources/Images/kabeblock.png");
	title_cc = LoadGraph("Resources/Images/title_C2.png");
}

Title::~Title()
{

}

//初期化処理
void Title::Initialize()
{

}
//更新処理
eSceneType Title::Update()
{
	//Aボタンでゲームメインへ
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A)) {
		return eSceneType::E_MAIN;
	}
	//Xボタンでゲームメインへ
	if (InputControl::GetButtonDown(XINPUT_BUTTON_X)) {
		return eSceneType::E_END;
	}

	//現在のシーンタイプを返す
	return GetNowScene();
}

//描画処理
void Title::Draw()const
{
	//背景画像
	for (int g = 0; g < 1280; g = g + 50) {
		for (int z = 0; z < 750; z = z + 50) {
			DrawRotaGraph(g, z, 1.0, 0, title_g, FALSE);
		}
	}

	SetFontSize(64);
	DrawString(410, 200, "Dokkan Magic", 0x0000ff, TRUE);
	SetFontSize(70);
	DrawFormatString(220, 400, 0xff0000, "Aボタンを押してスタート", FALSE);
	SetFontSize(40);
	DrawFormatString(420, 500, 0xff0000, "Xボタンを押して終了", FALSE);

}

//終了時処理
void Title::Finalize()
{

}

//現在のシーン情報を取得
eSceneType Title::GetNowScene()const
{
	return eSceneType::E_TITLE;
}
