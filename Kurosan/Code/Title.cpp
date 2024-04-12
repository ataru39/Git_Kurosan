#include "Title.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

Title::Title() : background_image(NULL), menu_image(NULL), cursor_image(NULL), menu_cursor(0),credit_time(0),credit_image(NULL),end(NULL),title_image(0),title_car(0),
				 cursol_se(0), kettei_se(0)
{

}
Title::~Title()
{

}

//����������
void Title::Initialize()
{
	credit_time = -1;
	end = FALSE;
	//�摜�̓ǂݍ���
	title_car = LoadGraph("Resource/Title/T_Car.png");
	background_image = LoadGraph("Resource/Title/T_Fire.bmp");
	title_image = LoadGraph("Resource/Font/title.png");
	menu_image = LoadGraph("Resource/Font/F_Menu.png");
	cursor_image = LoadGraph("Resource/images/cone.bmp");
	credit_image = LoadGraph("Resource/Title/credit.png");

	// �T�E���h�̓ǂݍ���
	cursol_se = LoadSoundMem("Resource/sounds/se/cursor.mp3");
	kettei_se = LoadSoundMem("Resource/sounds/se/kettei.mp3");

	//�G���[�`�F�b�N
	if (background_image == -1)
	{
		throw("Resource/Title/T_Car.png������܂���\n");
	}
	if (background_image == -1)
	{
		throw("Resource/Title/T_Fire.bmp������܂���\n");
	}
	if (title_image == -1)
	{
		throw("Resource/image/title.png������܂���\n");
	}
	if (menu_image == -1)
	{
		throw("Resource/Font/F_Menu.png������܂���\n");
	}
	if (cursor_image == -1)
	{
		throw("Resorce/images/cone.bmp������܂���\n");
	}
	if (credit_image == -1)
	{
		throw("Resource/Title/credit.png������܂���\n");
	}
}
//�X�V����
eSceneType Title::Update()
{
	if (credit_time > 0)
	{
		credit_time -= 1;
	}
	
	//�J�[�\�����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		menu_cursor++;
		PlaySoundMem(cursol_se, DX_PLAYTYPE_BACK);
		//1�ԉ��ɓ��B������A��ԏ�ɂ���
		if (menu_cursor > 3)
		{
			menu_cursor = 0;
		}
	}

	//�J�[�\����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		menu_cursor--;
		PlaySoundMem(cursol_se, DX_PLAYTYPE_BACK);
		//1�ԏ�ɓ��B������A��ԉ��ɂ���
		if (menu_cursor < 0)
		{
			menu_cursor = 3;
		}
	}

	//�J�[�\������i���肵����ʂɑJ�ڂ���j
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		PlaySoundMem(kettei_se, DX_PLAYTYPE_BACK);
		switch (menu_cursor)
		{
		case 0:
			return eSceneType::E_MAIN;
		case 1:
			return eSceneType::E_RULE;
		case 2:
			return eSceneType::E_RANKING_DISP;;
		default:
			credit_time = 180;    //3�b�ԃZ�b�g
			end = TRUE;
			//return eSceneType::E_END;
		}
	}
	//3�b��Q�[���𗎂Ƃ�
	if (credit_time == 0)           
	{
		return eSceneType::E_END;
	}

	//���݂̃V�[���^�C�v��Ԃ�
	return GetNowScene();
}

//�`�揈��
void Title::Draw()const
{
	//�^�C�g����ʂ̕`��
	DrawGraph(0, 0, background_image, FALSE);

	//�薼�̕`��
	DrawGraph(5, 30, title_image, TRUE);

	//�Ԃ̕`��
	DrawGraph(200, 90, title_car, TRUE);

	//���j���[�摜�̕`��
	DrawGraph(55, 200, menu_image, TRUE);

	//�J�[�\���摜�̕`��
	DrawRotaGraph(35, 220 + menu_cursor * 40, 0.7, DX_PI / 2.0, cursor_image, TRUE);

	//�N���W�b�g�摜�̕`��
	if (end == TRUE)
	{
		DrawGraph(0, 0, credit_image, FALSE);

		SetFontSize(20);
		DrawString(150, 50, "�g�p�����Ă����������T�C�g", 0xffffff, 0);

		DrawString(20, 160, "silhouetteAC�l", 0xffffff, 0);
		DrawString(400, 160, "illustimage�l", 0xffffff, 0);
		DrawString(20, 200, "illustAC�l", 0xffffff, 0);
		DrawString(400, 200, "���S�쐬�l", 0xffffff, 0);
		DrawString(20, 250, "�������l", 0xffffff, 0);
			DrawString(400, 250, "�j�R�j�E�R�����Y�l", 0xffffff, 0);

		DrawString(150, 450, "---- thank you for playing BurnOut ----", 0xffffff, 0);
	}
}

//�I��������
void Title::Finalize()
{
	//�ǂݍ��񂾉摜���폜
	DeleteGraph(background_image);
	DeleteGraph(menu_image);
	DeleteGraph(cursor_image);
	DeleteGraph(credit_image);
}

//���݂̃V�[�������擾
eSceneType Title::GetNowScene()const
{
	return eSceneType::E_TITLE;
}
