#include "ResultScene.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

ResultScene::ResultScene()
{

}

ResultScene::~ResultScene()
{

}

//����������
void ResultScene::Initialize()
{
}

//�X�V����
eSceneType ResultScene::Update()
{
	//���݂̃V�[���^�C�v��Ԃ�
	return GetNowScene();
}

//�`�揈��
void ResultScene::Draw()const
{
}

//�I��������
void ResultScene::Finalize()
{
}

//���݂̃V�[�������擾
eSceneType ResultScene::GetNowScene()const
{
	return eSceneType::E_RESULT;
}
