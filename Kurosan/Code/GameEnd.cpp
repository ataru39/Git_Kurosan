#include "GameEnd.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

End::End()
{
	end_c = LoadGraph("Resources/Images/title_C.png");
}

void End::Initialize()
{
}

eSceneType End::Update()
{
	return GetNowScene();
}

void End::Draw() const
{
}

void End::Finalize()
{
}

eSceneType End::GetNowScene() const
{
	return eSceneType::E_END;
}
