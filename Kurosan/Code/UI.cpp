#include "UI.h"
#include <DxLib.h>

UI::UI()
{
	image = LoadGraph("Resources/Images/tile_0.png");
	font = CreateFontToHandle(NULL, 40, 2);

}

UI::~UI()
{
	DeleteGraph(image);
}

void UI::Initialize()
{
	// 秒 初期化
	sec = 0;
	// 分 初期化
	minute = 3;
	// フレーム
	frame = 0;
}

bool UI::GetIsClear()
{
	if (minute == 0 && sec == 0)
	{
		return true;
	}
	return false;
}

void UI::Update()
{
	if(GetIsClear() == false)
	{
		// フレームカウント
		frame++;

		// カウントダウン
		if (frame % 60 == 0 && sec > -1) {
			sec--;
		}

		// 0秒の時、分を繰り下げる
		if (sec <= -1 && minute > -1) {
			minute -= 1;
			sec = 59;
		}
	}
}

void UI::Draw()const
{
	// 上の茶色のやつ
	for (int x = 0; x < 1280; x += 100) {
		DrawGraph(x, 0, image, TRUE);
	}
	// 時間表示
	DrawFormatStringToHandle(800, 40, 0xffffff, font, "TIME %d:%2d", minute, sec);
}

int UI::GetTime()
{
	return int(minute);
}
