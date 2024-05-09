#include "UI.h"
#include <DxLib.h>

UI::UI()
{
	image = LoadGraph("Resources/Images/kabeblock.png");
}

UI::~UI()
{
	DeleteGraph(image);
}

void UI::Update()
{
	frame++;

	//ŠÔ‚ğ‘‚â‚·ˆ—
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
	y_i = 0;
}

void UI::Draw()const
{
	DrawFormatString(200, 60, 0x00fff0, "@ŠÔ@%d", time);
	for (int x = 0; x < 1280; x+=100) {
		DrawGraph(x, 0, image, TRUE);
	}
}

