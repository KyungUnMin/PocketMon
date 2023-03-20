#include "EnemyHPBackground.h"

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
EnemyHPBackground* EnemyHPBackground::EnemyPtr = nullptr;

EnemyHPBackground::EnemyHPBackground()
{
	EnemyPtr = this;
}

EnemyHPBackground::~EnemyHPBackground()
{
	if (this == EnemyPtr)
	{
		EnemyPtr = nullptr;
	}
}

void EnemyHPBackground::Start()
{
	GameEngineRender* RenderPtr = CreateRender("EnemyHPBackground.bmp", RenderOrder::Battle_UI);
	RenderPtr->SetScale((RenderPtr->GetImage()->GetImageScale()));
	SetMovePositions({ -600,120 }, { 250,120 });

}