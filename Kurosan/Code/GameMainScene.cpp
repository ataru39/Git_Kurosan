#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene()
{

}

GameMainScene::~GameMainScene()
{

}

//����������
void GameMainScene::Initialize()
{

}

//�X�V����
eSceneType GameMainScene::Update()
{
	return GetNowScene();
}

//�`�揈��
void GameMainScene::Draw()const
{

}

//�I��������
void GameMainScene::Finalize()
{

}

//���݂̃V�[�������擾
eSceneType GameMainScene::GetNowScene()const
{
	return eSceneType::E_MAIN;
}
