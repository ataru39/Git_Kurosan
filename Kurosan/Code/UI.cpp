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

void UI::Update()
{
	frame++;

	//時間を増やす処理
	if (frame % 60 == 0) {
		time++;
	}

	if (time == 61) {
		time = 0;
	}
	
}

void UI::Initialize()
{
	time = 0;
	frame = 0;
	y_i = 0;
}

void UI::Draw()const
{
	for (int x = 0; x < 1280; x+=100) {
		DrawGraph(x, 0, image, TRUE);
	}
	//DrawFormatString(200, 60, 0x00fff0, "　時間　%d", time);
	DrawFormatStringToHandle(30, 40, 0xffffff, font, "　時間：%d", time);

}
