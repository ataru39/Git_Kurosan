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

void UI::Draw()
{	
	DrawBox(0, 0, 1280, 100, 0xff0000, TRUE);

	DrawFormatString(50, 50, 0xffffff, "Å@éûä‘Å@%d", time);
}

