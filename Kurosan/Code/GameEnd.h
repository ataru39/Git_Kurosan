#pragma once

#include "SceneBase.h"

class End:public SceneBase
{
public:
	End();
	virtual~End();

	int end_c, end_g;

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	virtual eSceneType GetNowScene() const override;

private:

};

