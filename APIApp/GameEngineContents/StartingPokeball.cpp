#include "StartingPokeball.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "InputControll.h"
#include "PokeDataBase.h"
#include "PokemonScript.h"
#include "Player.h"
#include "SelectStartingUI.h"
#include "BgmPlayer.h"

int2 StartingPokeball::StaticRivalMovelIndex = int2(0, 0);
StartingPokeball* StartingPokeball::StaticRivalPokeball = nullptr;

StartingPokeball::StartingPokeball() :
	PokemonNumber(PokeNumber::Onix)
{
}

StartingPokeball::~StartingPokeball()
{
}

void StartingPokeball::Init(PokeNumber _Number, int2 _RivalIndex, StartingPokeball* _RivalPokeball)
{
	PokemonNumber = _Number;
	RivalBallIndex = _RivalIndex;
	RivalPokeball = _RivalPokeball;
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
	SelectStartingUI::MainSelectStartingUI->SelectMonster(PokemonNumber,
		std::bind([](StartingPokeball* _This) {
			_This->SelectEvent();
			}, this));

	StaticRivalPokeball = RivalPokeball;
	StaticRivalMovelIndex = RivalBallIndex;
}

void StartingPokeball::SelectEvent()
{
	PokeballRender->Off();
	PokemonScript::EndScript(100);
	BgmPlayer::SoundPlayBgmPauseFade("GetFirstPokemon.mp3");
}

void StartingPokeball::RenderOff()
{
	PokeballRender->Off();
}

void StartingPokeball::Start()
{
	PokeballRender = CreateRender("Pokeball.bmp", RenderOrder::Monster);
	PokeballRender->SetScale(float4(50, 50));
	PokeballRender->SetPosition(float4(0, 10));
}