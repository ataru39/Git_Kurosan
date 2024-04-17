#pragma once

#include "SceneBase.h"
#include "Player.h"
#include "Wall.h"

class GameMainScene : public SceneBase
{
private:
	Player* player;
	Wall* wall;
public:
	GameMainScene();
	virtual ~GameMainScene();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;
	virtual eSceneType GetNowScene() const override;
};

