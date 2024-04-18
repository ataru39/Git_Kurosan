#include "GameMainScene.h"
#include "DxLib.h"
#include <math.h>

GameMainScene::GameMainScene()
{
	wall = new Wall;
	player = new Player;
}

GameMainScene::~GameMainScene()
{
	delete wall;
	delete player;
}

//����������
void GameMainScene::Initialize()
{
	player->Initialize();
}

//�X�V����
eSceneType GameMainScene::Update()
{
	player->Update();

	return GetNowScene();
}

//�`�揈��
void GameMainScene::Draw()const
{
	wall->Draw();
	player->Draw();
	DrawBox(0, 0, 1280, 100, 0xff0000, TRUE);
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
