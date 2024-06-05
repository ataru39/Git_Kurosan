#pragma once

#include "SceneBase.h"
#include "Player.h"
#include "Wall.h"
#include "Enemy.h"
#include "UI.h"
#include "S_Bullet.h"
#include "S_21Fist.h"
#include "S_Frame.h"

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
	S_Frame** frame;

	//íe
	int b_cooltime;
	Vector2D b_location;
	
	//åù
	int f_cooltime;
	int f_drey;
	Vector2D f_location;

	//âä
	int h_cooltime;
	Vector2D h_location;


	int grace;

public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	bool WhitCheck(Enemy* e ,Wall* w);
	bool BhitCheck(Enemy* e ,S_Bullet* b);
	bool FhitCheck(Enemy* e ,S_21Fist* f);
	bool HhitCheck(Enemy* e, S_Frame* h);
	virtual eSceneType GetNowScene() const override;
};

