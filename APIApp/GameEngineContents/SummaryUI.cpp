#include "SummaryUI.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "PocketMonCore.h"
#include "PokeDataBase.h"
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

	//_______테스트용 포켓몬 생성
	Pokemons.resize(5);
	Pokemons[0] = PokeDataBase::PokeCreate(1, 5);
	Pokemons[1] = PokeDataBase::PokeCreate(4, 5);
	Pokemons[2] = PokeDataBase::PokeCreate(7, 5);
	Pokemons[3] = PokeDataBase::PokeCreate(10, 2);
	Pokemons[4] = PokeDataBase::PokeCreate(11, 3);

	InfoBack = CreateRender("PokemonInfo.bmp", 0);
	InfoBack->SetScaleToImage();
	InfoBack->SetPosition(InfoBack->GetScale().half());

	PokemonRender = CreateRender("BattleBulbasaurFront.bmp", 1);
	PokemonRender->SetScaleToImage();
	PokemonRender->SetPosition({230, 278});

	TextActor* NewText = CurrentLevel->CreateActor<TextActor>();
	NewText->SetPos({ 132, 104 });
	NewText->SetText("BULBASAUR", "Font_Dialog_White.bmp", false);

	NewText = CurrentLevel->CreateActor<TextActor>();
	NewText->SetPos({ 72, 100 });
	NewText->SetText("5", "Font_Dialog_White.bmp", false);

	NewText = CurrentLevel->CreateActor<TextActor>();
	NewText->SetPos({ 684, 110 });
	NewText->SetText("001", false);

	NewText = CurrentLevel->CreateActor<TextActor>();
	NewText->SetPos({ 684, 174 });
	NewText->SetText("BULBASAUR", false);

	NewText = CurrentLevel->CreateActor<TextActor>();
	NewText->SetPos({ 684, 412 });
	NewText->SetText("NONE", false);

	NewText = CurrentLevel->CreateActor<TextActor>();
	NewText->SetPos({ 48, 484 });
	NewText->SetText("ABCDefewrASDJASDLqiwejskljASDJFaslkfashfljewfheaaaaaaaaaasssssssawifufasfasj", false);
}

void SummaryUI::Update(float _DeltaTime)
{
	if (GameEngineInput::IsDown("B"))
	{
		PocketMonCore::GetInst().ChangeLevel("PokemonLevel");
	}
}

void SummaryUI::NextPage()
{
}

void SummaryUI::PrevPage()
{
}

void SummaryUI::MovePage()
{
}

void SummaryUI::NextPokemon()
{
}

void SummaryUI::PrevPokemon()
{
}

void SummaryUI::MovePokemon()
{
}

