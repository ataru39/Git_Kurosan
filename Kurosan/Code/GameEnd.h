#pragma once

#include "SceneBase.h"

class End:public SceneBase
{
public:
	End();
	~End();

	virtual void Initialize() override;
	virtual eSceneType Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

private:

};

