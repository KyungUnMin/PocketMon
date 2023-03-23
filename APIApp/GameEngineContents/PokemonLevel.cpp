#include "PokemonLevel.h"
#include "PokemonUI.h"
#include "PokeDataBase.h"
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
}

void PokemonLevel::LevelChangeEnd(GameEngineLevel* _NextLevel)
{
}

void PokemonLevel::LevelChangeStart(GameEngineLevel* _PrevLevel)
{
}
