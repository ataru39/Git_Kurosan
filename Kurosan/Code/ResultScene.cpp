#include"ResultScene.h"
#include"RankingData.h"
#include"../Utility/InputControl.h"
#include"DxLib.h"

ResultScene::ResultScene() : back_ground(NULL),cursor_image(NULL),score(0), menu_cursor(0)
{
	for (int i = 0; i < 3; i++)
	{
		enemy_image[i] = NULL;
		enemy_count[i] = NULL;
	}
}

ResultScene::~ResultScene()
{

}

//����������
void ResultScene::Initialize()
{

	//�摜�̓ǂݍ���
	back_ground = LoadGraph("Resource/images/back.bmp");
	cursor_image = LoadGraph("Resource/images/cone.bmp");
	int result = LoadDivGraph("Resource/images/obstacle.png", 3, 3, 1, 104, 72, enemy_image);

	//�G���[�`�F�b�N
	if (back_ground == -1)
	{
		throw("Resource/images/back.bmp������܂���\n");
	}
	if (cursor_image == -1)
	{
		throw("Resource/images/cone.bmp������܂���\n");
	}
	if (result == -1)
	{
		throw("Resource/images/obstacle.png������܂���\n");
	}
	//�Q�[�����ʂ̓ǂݍ���
	ReadResultData();
}

//�X�V����
eSceneType ResultScene::Update()
{
	//B�{�^���Ń����L���O�ɑJ�ڂ���
	if (InputControl::GetButtonDown(XINPUT_BUTTON_B))
	{
		switch (menu_cursor)
		{
		case 0:
			return eSceneType::E_MAIN;
		case 1:
			return eSceneType::E_RANKING_INPUT;
		case 2:
			return eSceneType::E_TITLE;
		}
	}

	//�J�[�\�����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_DOWN))
	{
		menu_cursor++;
		//1�ԉ��ɓ��B������A��ԏ�ɂ���
		if (menu_cursor > 2)
		{
			menu_cursor = 0;
		}
	}

	//�J�[�\����ړ�
	if (InputControl::GetButtonDown(XINPUT_BUTTON_DPAD_UP))
	{
		menu_cursor--;
		//1�ԏ�ɓ��B������A��ԉ��ɂ���
		if (menu_cursor < 0)
		{
			menu_cursor = 2;
		}
	}
	
	return GetNowScene();
}

//�`�揈��
void ResultScene::Draw()const
{
	//�w�i�摜��`��
	DrawGraph(0, 0, back_ground, TRUE);

	//�X�R�A���\���̈�
	DrawBox(150, 150, 490, 420, GetColor(0, 153, 0), TRUE);
	DrawBox(150, 150, 490, 420, GetColor(0, 0, 0), FALSE);

	DrawBox(500, 0, 640, 480, GetColor(0, 153, 0), TRUE);

	SetFontSize(20);
	DrawString(220, 170, "�Q�[���I�[�o�[", GetColor(204, 0, 0));

	SetFontSize(16);
	DrawString(185, 200, "���s����      ", GetColor(0, 0, 0));

	for (int i = 0; i < 3; i++)
	{
		DrawRotaGraph(230, 230 + (i * 20), 0.3f,0, enemy_image[i], TRUE);
		DrawFormatString(260, 222 + (i * 21), GetColor(255, 255, 255), "%6d x %4d=%6d", enemy_count[i], (i + 1) * 50, (i + 1) * 50 * enemy_count[i]);
	}

	//�J�[�\���摜�̕`��
	DrawRotaGraph(170, 327 + menu_cursor * 40, 0.4, DX_PI / 2.0, cursor_image, TRUE);

	DrawString(185, 290, "�X�R�A", GetColor(0, 0, 0));
	DrawFormatString(185, 290, 0xFFFFFF, "      =%6d", score);

	DrawString(185, 320, "���X�^�[�g",GetColor(0, 0, 0));
	DrawString(185, 360, "�����L���O�Ɉړ�", GetColor(0, 0, 0));
	DrawString(185, 400, "�^�C�g���ɖ߂�", GetColor(0, 0, 0));
}

//�I��������
void ResultScene::Finalize()
{
	//�ǂݍ��񂾉摜���폜
	DeleteGraph(back_ground);
	for (int i = 0; i < 3; i++)
	{
		DeleteGraph(enemy_image[i]);
	}
}

//���݂̃V�[�������擾
eSceneType ResultScene::GetNowScene()const
{
	return eSceneType::E_RESULT;
}

//���U���g�f�[�^�̓ǂݍ���
void ResultScene::ReadResultData()
{
	//�t�@�C���I�[�v��
	FILE* fp = nullptr;
	errno_t result = fopen_s(&fp, "Resource/dat/result_data.csv", "r");

	//�G���[�`�F�b�N
	if (result != 0)
	{
		throw("Resource/dat/result_data.csv���ǂݍ��߂܂���\n");
	}

	//���ʂ�ǂݍ���
	fscanf_s(fp, "%d,\n", &score);

	//���������Ɠ��_���擾
	for (int i = 0; i < 3; i++)
	{
		fscanf_s(fp, "%d,\n", &enemy_count[i]);
	}

	//�t�@�C���N���[�X
	fclose(fp);
}
