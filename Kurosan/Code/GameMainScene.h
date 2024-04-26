#pragma once

#include "SceneBase.h"
#include "Player.h"
#include "Wall.h"
#include "Enemy.h"
#include "UI.h"

class GameMainScene : public SceneBase
{
private:
	Player* player;
	Wall* wall;
	Enemy* enemy;
	UI* ui;
	int Espawn[10];
	int spawn;


public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	bool HitCheck(Player* p ,Wall* w);
	virtual eSceneType GetNowScene() const override;
};

