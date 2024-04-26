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
	DrawFormatString(50, 150, 0x00fff0, "Å@éûä‘Å@%d", time);
}

