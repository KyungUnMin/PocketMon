#include "SummaryUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "PokemonLevel.h"
SummaryUI::SummaryUI() 
{
}

SummaryUI::~SummaryUI() 
{
}

void SummaryUI::Start()
{
	CurrentLevel = dynamic_cast<PokemonLevel*>(GetLevel());
	GameEngineRender* Ex = CreateRender("SummaryExample.bmp", 14);
	Ex->SetScaleToImage();
	Ex->SetPosition(Ex->GetScale().half());
}

void SummaryUI::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("B"))
	{
		CurrentLevel->SummaryOff();
	}
}

