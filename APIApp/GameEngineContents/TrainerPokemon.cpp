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
		MsgAssert("���ϸ��� ���̻� �߰��� �� �����ϴ�.");
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

std::vector<PokeDataBase> TrainerPokemon::GetPokemons()
{
	return Pokemons;
}

PokeDataBase* TrainerPokemon::NextPokemon()
{
	for (int i = 0; i < Pokemons.size(); i++)
	{
		if (false == Pokemons[i].IsMonsterStern())
		{
			if (i != 0)
			{
				PokeDataBase _Pokemon = Pokemons[i];
				Pokemons[i] = Pokemons[0];
				Pokemons[0] = _Pokemon;
			}
			return &Pokemons[0];
		}
	}
	MsgAssert("���� ���ϸ��� �����ϴ�.");
	return nullptr;
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

void TrainerPokemon::AllRecovery()
{
	for (int i = 0; i < Pokemons.size(); i++)
	{
		Pokemons[i].ForInven_AllPowerPointRecovery();
		Pokemons[i].SetMonsterCurrentHP(Pokemons[i].GetMonsterMaxHP_int());
	}
}

