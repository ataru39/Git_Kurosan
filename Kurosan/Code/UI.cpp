#include "UI.h"
#include <DxLib.h>

UI::UI()
{
	image = LoadGraph("Resources/Images/kabeblock.png");
	whight = 0;
}

UI::~UI()
{
}

void UI::Update()
{
	frame++;

	if (frame % 60 == 0) {
		time++;
	}
}

int UI::Time()
{
	return time;
}

void UI::Initialize()
{
	time = 0;
	frame = 0;
}

void UI::Finalize()
{
	DeleteGraph(image);
}

void UI::Draw()
{	
	//DrawBox(0, 0, 1280, 100, 0xff0000, TRUE);
	if (whight < 1200) {
		whight += 100;
	}
	DrawGraph(whight, 0, image, TRUE);
	DrawFormatString(50, 50, 0xffffff, "@ŽžŠÔ@%d", time);
}

