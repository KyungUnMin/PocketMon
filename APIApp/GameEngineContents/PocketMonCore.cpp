 #include "PocketMonCore.h"

#include "InputControll.h"

#include "CenterLevel.h"
#include "FieldmapLevel.h"
#include "BattleLevel.h"
#include "PlayerTestLevel.h"
#include "TextTestLevel.h"
#include "BagLevel.h"
#include "PokemonLevel.h"
#include "SummaryLevel.h"
#include "BuyLevel.h"
#include "EndingLevel.h"
#include "OpeningLevel.h"
#include "TrainerCardLevel.h"
#include "PlayTime.h"
#include "BgmPlayer.h"

PocketMonCore PocketMonCore::Core;

PocketMonCore::PocketMonCore()
{

}

PocketMonCore::~PocketMonCore()
{

}

void PocketMonCore::Start()
{
	bool* FOR_DEBUG = new bool;

	CreateLevel<CenterLevel>("CenterLevel");
	CreateLevel<FieldmapLevel>("FieldmapLevel");
	CreateLevel<BattleLevel>("BattleLevel");
	CreateLevel<BagLevel>("BagLevel");
	CreateLevel<PokemonLevel>("PokemonLevel");
	CreateLevel<SummaryLevel>("SummaryLevel");
	CreateLevel<BuyLevel>("BuyLevel");
	CreateLevel<EndingLevel>("EndingLevel");
	CreateLevel<OpeningLevel>("OpeningLevel");
	CreateLevel<TrainerCardLevel>("TrainerCardLevel");

	ChangeLevel("OpeningLevel");
}

void PocketMonCore::Update(float _DeltaTime)
{
	InputControll::ResetDoubleCheck();
	PlayTime::MianPlayTime->Update(_DeltaTime);
	BgmPlayer::Update(_DeltaTime);
}

void PocketMonCore::End()
{
}
