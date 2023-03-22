#include "PokemonLevel.h"
#include "PokemonUI.h"
#include "SummaryUI.h"
#include "PokeDataBase.h"
PokemonLevel::PokemonLevel() 
{
}

PokemonLevel::~PokemonLevel() 
{
}

void PokemonLevel::SummaryOn()
{
	Summary->On();
	Pokemon->Off();
}

void PokemonLevel::SummaryOff()
{
	Summary->Off();
	Pokemon->On();
}

void PokemonLevel::Loading()
{

	Pokemons.resize(5);
	Pokemons[0] = PokeDataBase::PokeCreate(1, 5);
	Pokemons[1] = PokeDataBase::PokeCreate(4, 5);
	Pokemons[2] = PokeDataBase::PokeCreate(7, 5);
	Pokemons[3] = PokeDataBase::PokeCreate(10, 2);
	Pokemons[4] = PokeDataBase::PokeCreate(11, 3);

	Pokemon = CreateActor<PokemonUI>();
	Summary = CreateActor<SummaryUI>();
	Summary->Off();
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
