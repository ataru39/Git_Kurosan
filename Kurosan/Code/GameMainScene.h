#pragma once

#include "SceneBase.h"
#include "Player.h"
#include "Wall.h"
#include "Enemy.h"
#include "UI.h"
#include "S_Bullet.h"
#include "S_21Fist.h"
#include "S21_FistL.h"
#include "S_Frame.h"
#include <math.h>

class GameMainScene : public SceneBase
{
private:
	Player* player;
	Wall* wall;
	Enemy** enemy;

	int enemymax;
	int e_delay;

	UI* ui;
	S_Bullet** bullet;
	S_21Fist** fist;
	S_21FistL** fistl;
	S_Frame** frame;

	//�e
	int b_cooltime;
	Vector2D b_location;

	//��
	int f_cooltime;
	int f_drey;
	Vector2D f_location;

	//����
	int l_cooltime;
	Vector2D l_location;

	//��
	int h_cooltime;
	Vector2D h_location;

	int grace;

	// ���x���A�b�v������
	bool is_levelup;

	// �Q�[���N���A������
	bool is_clear;

	//�Q�[���I�[�o�[
	bool is_over;

	// �Q�[���N���A�J�E���^�[
	int cnt;

	// �Q�[�����C��BGM
	int bgm_gm;

	// �Q�[���N���ASE
	int se_clear;

	// �Q�[���I�[�o�[SE
	int se_over;

	// �e����SE
	int se_bullet;

	// ������SE
	int se_fist;
	// ���q�b�gSE
	int se_fist_hit;

	// ������SE
	int se_flame;
	// ���q�b�gSE
	int se_flame_hit;

	int fun;
	int e_type;

public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	bool WhitCheck(Enemy* e, Wall* w);
	bool BhitCheck(Enemy* e, S_Bullet* b);
	bool FhitCheck(Enemy* e, S_21Fist* f);
	bool FlhitCheck(Enemy* e, S_21FistL* l);
	bool HhitCheck(Enemy* e, S_Frame* h);
	virtual eSceneType GetNowScene() const override;
};
