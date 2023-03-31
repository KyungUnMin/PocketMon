#include "OakNPC.h"
#include "PokemonScript.h"
#include "FieldDialog.h"
#include "Player.h"

OakNPC::OakNPC()
{
}

OakNPC::~OakNPC()
{
}

void OakNPC::IdleUpdate(float _DeltaTime)
{
	if (true == PokemonScript::IsScriptEnd(100))
	{
		ScriptKey = 1;
	}
	else
	{
		ScriptKey = 0;
	}

	StaticNPC::IdleUpdate(_DeltaTime);
}