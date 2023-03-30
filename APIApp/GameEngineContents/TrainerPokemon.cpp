#include "TrainerPokemon.h"

TrainerPokemon::TrainerPokemon()
{
}

TrainerPokemon::~TrainerPokemon() 
{
}

void TrainerPokemon::AddPokemon(PokeDataBase _PokeData)
{
}

void TrainerPokemon::AddPokemon(int _Number, int _Level)
{
}

bool TrainerPokemon::IsFull()
{
	return false;
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

