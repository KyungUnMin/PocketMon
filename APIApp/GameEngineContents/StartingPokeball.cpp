#include "StartingPokeball.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "InputControll.h"
#include "PokeDataBase.h"
#include "PokemonScript.h"
#include "Player.h"
#include "SelectStartingUI.h"

StartingPokeball::StartingPokeball() :
	_MyNumber(PokeNumber::Onix)
{
}

StartingPokeball::~StartingPokeball()
{
}

void StartingPokeball::Init(PokeNumber _Number)
{
	_MyNumber = _Number;
}

bool StartingPokeball::EventCheck()
{
	if (false == InputControll::CanControll())
	{
		return false;
	}

	if (true == InputControll::IsCurFrameUsedKey())
	{
		return false;
	}

	if (false == PokeballRender->IsUpdate())
	{
		return false;
	}

	if (true == GameEngineInput::IsDown("NpcTalk") && LookDir::Up == Player::MainPlayer->GetDir())
	{
		return true;
	}

	return false;
}

void StartingPokeball::EventFunc()
{
	SelectStartingUI::MainSelectStartingUI->SelectMonster(_MyNumber,
		std::bind([](StartingPokeball* _This) {
			_This->SelectEvent();
			}, this));
}

void StartingPokeball::SelectEvent()
{
	PokeballRender->Off();
	PokemonScript::EndScript(100);
}

void StartingPokeball::Start()
{
	PokeballRender = CreateRender("Pokeball.bmp", RenderOrder::Monster);
	PokeballRender->SetScale(float4(50, 50));
	PokeballRender->SetPosition(float4(0, 10));
}