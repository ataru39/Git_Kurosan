#include "Title.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

Title::Title()
{

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
	//���݂̃V�[���^�C�v��Ԃ�
	return GetNowScene();
}

//�`�揈��
void Title::Draw()const
{
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
