#include "PokemonCenterNPC.h"
#include "BattleLevel.h"

PokemonCenterNPC::PokemonCenterNPC()
{
}

PokemonCenterNPC::~PokemonCenterNPC()
{
}

void PokemonCenterNPC::Start()
{
	InitNPC("PoketmonCenterNpc", "Nurse.bmp", BattleNpcType::NPC3);
	AddNPC("PewterCity_PokemonCenter", { 8,4 });
	AddScript("Hi", 0);
	AddScript("Hi1", 1);
	AddScript("Hi2", 2);
	AddScript("Hi3", 3);
	//SetBaseDir(LookDir::Down);
	Look(LookDir::Down);
}
void PokemonCenterNPC::IdleUpdate(float _DeltaTime)
{
	
}