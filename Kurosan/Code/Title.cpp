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

//����������
void Title::Initialize()
{
	
}
//�X�V����
eSceneType Title::Update()
{
	//A�{�^���ŃQ�[�����C����
	if (InputControl::GetButtonDown(XINPUT_BUTTON_A)) {
		return eSceneType:: E_MAIN;
	}
	//���݂̃V�[���^�C�v��Ԃ�
	return GetNowScene();
}

//�`�揈��
void Title::Draw()const
{
	//�w�i�摜
	for (int g = 0; g < 1280; g = g + 50) {
		for (int z = 0; z < 750; z = z + 50) {
			DrawRotaGraph(g, z, 1.0, 0, title_g, FALSE);
		}
	}

	/*for (int c = 50; c < 1281; c = c + 100) {
		DrawRotaGraph(c, 500, 2.0, 0, title_c, TRUE);
	}

	for (int g = 50; g < 1280; g = g + 100) {
		for (int z = 600; z < 751; z = z + 71) {
			DrawRotaGraph(g, z, 2.0, 0, title_cc, TRUE);
		}
	}*/

	SetFontSize(64);
	DrawString(410, 200, "�Y�c�̃}�W�b�N", 0x0000ff, TRUE);
	SetFontSize(70);
	DrawFormatString(220, 400, 0xff0000, "A�{�^���������ăX�^�[�g", FALSE);

}

//�I��������
void Title::Finalize()
{

}

//���݂̃V�[�������擾
eSceneType Title::GetNowScene()const
{
	return eSceneType::E_TITLE;
}
