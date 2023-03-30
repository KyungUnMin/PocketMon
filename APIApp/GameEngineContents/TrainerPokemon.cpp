#include "TrainerPokemon.h"
#include <GameEngineBase/GameEngineDebug.h>
TrainerPokemon::TrainerPokemon()
{
	Pokemons.reserve(PokemonMax);
}

TrainerPokemon::~TrainerPokemon() 
{
}

void TrainerPokemon::AddPokemon(PokeDataBase _PokeData)
{
	if (true == IsFull())
	{
		MsgAssert("포켓몬을 더이상 추가할 수 없습니다.");
	}
	Pokemons.push_back(_PokeData);
}

void TrainerPokemon::AddPokemon(int _Number, int _Level)
{
	AddPokemon(PokeDataBase::PokeCreate(_Number, _Level));
}

bool TrainerPokemon::IsFull()
{
	return PokemonMax == Pokemons.size();
}

PokeDataBase TrainerPokemon::NextPokemon()
{
	for (int i = 0; i < Pokemons.size(); i++)
	{
		if (false == Pokemons[i].IsMonsterStern())
		{
			return Pokemons[i];
		}
	}
	return Pokemons[0];
}

bool TrainerPokemon::HasNextPokemon()
{
	for (int i = 0; i < Pokemons.size(); i++)
	{
		if (false == Pokemons[i].IsMonsterStern())
		{
			return true;
		}
	}
	return false;
}

