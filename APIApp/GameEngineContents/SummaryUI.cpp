#include "SummaryUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "PocketMonCore.h"
#include "TextActor.h"
SummaryUI::SummaryUI() 
{
}

SummaryUI::~SummaryUI() 
{
}

void SummaryUI::Start()
{
	CurrentLevel = GetLevel();

	InfoBack = CreateRender("PokemonInfo.bmp", 14);
	InfoBack->SetScaleToImage();
	InfoBack->SetPosition(InfoBack->GetScale().half());

	TextActor* NewText = CurrentLevel->CreateActor<TextActor>();
	NewText->SetPos({ 100, 100 });
	NewText->SetText("zzzzzzzz");
}

void SummaryUI::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("B"))
	{
		PocketMonCore::GetInst().ChangeLevel("PokemonLevel");
	}
}

