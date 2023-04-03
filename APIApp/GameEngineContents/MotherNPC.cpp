#include "MotherNPC.h"
#include "PokemonScript.h"
#include "Player.h"

MotherNPC::MotherNPC()
{
}

MotherNPC::~MotherNPC()
{
}

void MotherNPC::IdleUpdate(float _DeltaTime)
{
	if (true == PokemonScript::IsScriptEnd(100))
	{
		ScriptKey = 1;
	}

	StaticNPC::IdleUpdate(_DeltaTime);
}

void MotherNPC::InteractionEnd()
{
	if (true == PokemonScript::IsScriptEnd(100))
	{
		Player::MainPlayer->GetPlayerPokemon()->AllRecovery();
	}

	StaticNPC::InteractionEnd();
}
