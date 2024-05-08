#include "UI.h"
#include <DxLib.h>

UI::UI()
{

}

UI::~UI()
{
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
	time = 50;
	frame = 0;
}

void UI::Draw()
{
	DrawFormatString(400, 400, 0x00fff0, "　時間　%d", time);
}

