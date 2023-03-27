#include "LevelUpStatUI.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"

LevelUpStatUI* LevelUpStatUI::LevelUpStatUIPtr = nullptr;

LevelUpStatUI::LevelUpStatUI()
{
	LevelUpStatUIPtr = this;
}

LevelUpStatUI::~LevelUpStatUI()
{
	if (this == LevelUpStatUIPtr)
	{
		LevelUpStatUIPtr = nullptr;
	}
}


void LevelUpStatUI::Start()
{

	GameEngineRender* StatRenderPtr = CreateRender("BattleStatus.bmp", BattleRenderOrder::Battle_UI);
	StatRenderPtr->SetScale((StatRenderPtr->GetImage()->GetImageScale()));
	StatRenderPtr->SetPosition({ 720,360 });





}
void LevelUpStatUI::Update(float _DeltaTime)
{


}