#pragma once

#include "SceneBase.h"
#include "Player.h"
#include "Wall.h"
#include "Enemy.h"
#include "UI.h"
#include "S_Bullet.h"

class GameMainScene : public SceneBase
{
private:
	Player* player;
	Wall* wall;
	Enemy** enemy;

	int wall_hp;
	int enemymax;
	int e_delay;
	int w_delay;

	UI* ui;
	S_Bullet** bullet;
	
	int b_cooltime;
	Vector2D b_location;
	
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
	virtual eSceneType GetNowScene() const override;
};

