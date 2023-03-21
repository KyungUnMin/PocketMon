#include "PokemonLevel.h"
#include "PokemonUI.h"
PokemonLevel::PokemonLevel() 
{
}

PokemonLevel::~PokemonLevel() 
{
}

void PokemonLevel::Loading()
{
	CreateActor<PokemonUI>();
}

void PokemonLevel::Update(float _DeltaTime)
{
	DebugTextPush(GetMousePos().ToString());
}

void PokemonLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
}

void PokemonLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
}
