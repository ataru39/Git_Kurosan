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
		time--;
	}
}

void UI::Initialize()
{
	time = 60;
	frame = 0;
}

void UI::Draw()
{
	DrawFormatString(400, 400, 0x00fff0, "Å@éûä‘Å@%d", time);
}

