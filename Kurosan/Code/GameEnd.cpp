#include "GameEnd.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

End::End()
{

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
