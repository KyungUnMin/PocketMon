 #include "PocketMonCore.h"

#include "PokeDataBase.h"
#include "ItemDataBase.h"

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
	CreateLevel<PlayerTestLevel>("PlayerLevel");
	CreateLevel<TextTestLevel>("TextTestLevel");
	CreateLevel<BagLevel>("BagLevel");
	CreateLevel<PokemonLevel>("PokemonLevel");
	CreateLevel<SummaryLevel>("SummaryLevel");
	CreateLevel<BuyLevel>("BuyLevel");
	CreateLevel<EndingLevel>("EndingLevel");
	CreateLevel<OpeningLevel>("OpeningLevel");

	ChangeLevel("CenterLevel");
}

void PocketMonCore::Update()
{
	InputControll::ResetDoubleCheck();
}

void PocketMonCore::End()
{
	// PokeDataBase::GetPtr().Release();
}
