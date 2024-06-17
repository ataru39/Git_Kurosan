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

	//弾
	int b_cooltime;
	Vector2D b_location;
	
	//拳
	int f_cooltime;
	int f_drey;
	Vector2D f_location;

	//左手
	int l_cooltime;
	Vector2D l_location;

	//炎
	int h_cooltime;
	Vector2D h_location;

	int grace;

	// レベルアップしたか
	bool is_levelup;
	// ゲームクリアしたか
	bool is_clear;
	// カウンター
	int cnt;

	int sound;

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
	bool FlhitCheck(Enemy* e ,S_21FistL* l);
	bool HhitCheck(Enemy* e, S_Frame* h);
	virtual eSceneType GetNowScene() const override;
};
