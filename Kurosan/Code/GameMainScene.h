#pragma once

#include "SceneBase.h"
#include"Player.h"
#include "Obstacle.h"
#include "Item.h"

class GameMainScene : public SceneBase
{
private:
	int high_score;				//�n�C�X�R�A
	int back_ground;			//�w�i�摜
	int barrier_image;			//�o���A�摜
	int mileage;				//���s����
	int nowscore;				//���݂̃X�R�A
	int coin;					//�l���R�C������
	int obstacle_image[3];		//��Q���̉摜
	int obstacle_count[3];		//���������Q���̃J�E���g
	int item_image[2];			//�A�C�e���̉摜
	int item_get_se;			//�A�C�e�����莞��SE
	int BGM;					//BGM
	bool getkey;				//���l��
	Player* player;				//�v���C���[
	Obstacle** obstacle;		//��Q��
	Item** item;				//�A�C�e��


public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

	//���l������
	bool GetKey();

private:
	//�n�C�X�R�A�ǂݍ��ݏ���
	void ReadHighScore();
	//�����蔻��
	bool IsHitCheck(Player* p, Obstacle* e);
	//�A�C�e���̓����蔻��
	bool IsItemHitCheck(Player* p, Item* i);
	
};

