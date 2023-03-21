#include "PokemonUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineLevel.h>
PokemonUI::PokemonUI() 
{
}

PokemonUI::~PokemonUI() 
{
}

void PokemonUI::Start()
{
	// ____________렌더 생성______________
	{
		GameEngineRender* BackUI = CreateRender("PokemonUI_Back.bmp", 0);
		BackUI->SetScaleToImage();
		BackUI->SetPosition(BackUI->GetScale().half());

		// 포켓몬 뒷 배경
		MainPokemonBack = CreateRender("MainPokemon.bmp", 1);
		MainPokemonBack->SetScale({ 336, 228 });
		MainPokemonBack->SetPosition({ 172, 196 });

		for (int i = 0; i < 5; i++)
		{
			SubPokemonBack[i] = CreateRender("SubPokemon.bmp", 1);
			SubPokemonBack[i]->SetScale({ 600, 96 });
			SubPokemonBack[i]->SetPosition({ 652, 84.0f + 96 * i });
		}

		// 포켓몬 이미지
		MainPokemonRender = CreateRender("Bulbasaur_mini.bmp", 2);
		float4 _RenderScale = MainPokemonRender->GetImage()->GetImageScale();
		_RenderScale.x /= 2;
		MainPokemonRender->SetScale(_RenderScale);
		MainPokemonRender->SetPosition({ 52, 172 });

		for (int i = 0; i < 5; i++)
		{
			SubPokemonRender[i] = CreateRender("Bulbasaur_mini.bmp", 2);
			_RenderScale = SubPokemonRender[i]->GetImage()->GetImageScale();
			_RenderScale.x /= 2;
			SubPokemonRender[i]->SetScale(_RenderScale);
			SubPokemonRender[i]->SetPosition({ 408, 98.0f + 96 * i });
		}

		// 포켓몬 이름
		GameEngineLevel* CurrentLevel = GetLevel();
		MainPokemonNameText = CurrentLevel->CreateActor<TextActor>();
		MainPokemonNameText->SetPos({ 108, 172 });
		MainPokemonNameText->SetText("Bulbasaur", "Font_Dialog_White.bmp", false);

		for (int i = 0; i < 5; i++)
		{
			SubPokemonNameText[i] = CurrentLevel->CreateActor<TextActor>();
			SubPokemonNameText[i]->SetPos({ 468, 76.0f + 96 * i });
			SubPokemonNameText[i]->SetText("Bulbasaur", "Font_Dialog_White.bmp", false);
		}

		// 포켓몬 레벨
		MainPokemonLevelText = CurrentLevel->CreateActor<TextActor>();
		MainPokemonLevelText->SetPos({ 212, 212 });
		MainPokemonLevelText->SetText("10", "Font_Dialog_White.bmp", false);

		for (int i = 0; i < 5; i++)
		{
			SubPokemonLevelText[i] = CurrentLevel->CreateActor<TextActor>();
			SubPokemonLevelText[i]->SetPos({ 570, 115.0f + 96 * i });
			SubPokemonLevelText[i]->SetText("5", "Font_Dialog_White.bmp", false);
		}

		TextBarRender = CreateRender("TextBar.bmp", 1);
		TextBarRender->SetScale({ 720, 112 });
		TextBarRender->SetPosition({ 370, 580 });
		TextBarRender->SetFrame(0);
	}
}

void PokemonUI::Update(float _DeltaTime)
{
}

void PokemonUI::LevelChangeEnd(GameEngineLevel* _PrevLevel)
{
}

void PokemonUI::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
}
