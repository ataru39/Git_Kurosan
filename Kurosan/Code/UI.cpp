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
	// �b ������
	sec = 0;
	// �� ������
	minute = 3;
	// �t���[��
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
		// �t���[���J�E���g
		frame++;

		// �J�E���g�_�E��
		if (frame % 60 == 0 && sec > -1) {
			sec--;
		}

		// 0�b�̎��A�����J�艺����
		if (sec <= -1 && minute > -1) {
			minute -= 1;
			sec = 59;
		}
	}
}

void UI::Draw()const
{
	// ��̒��F�̂��
	for (int x = 0; x < 1280; x += 100) {
		DrawGraph(x, 0, image, TRUE);
	}
	// ���ԕ\��
	DrawFormatStringToHandle(800, 40, 0xffffff, font, "TIME %d:%2d", minute, sec);
}

int UI::GetTime()
{
	return int(minute);
}
