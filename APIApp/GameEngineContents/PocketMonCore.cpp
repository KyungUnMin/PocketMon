 #include "PocketMonCore.h"

#include "PokeDataBase.h"

#include "CenterLevel.h"
#include "FieldmapLevel.h"
#include "BattleLevel.h"
#include "PlayerTestLevel.h"
#include "TextTestLevel.h"
#include "BagLevel.h"
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

	ChangeLevel("CenterLevel");
}

void PocketMonCore::Update()
{

}

void PocketMonCore::End()
{
	PokeDataBase::GetPtr().Release();
}
