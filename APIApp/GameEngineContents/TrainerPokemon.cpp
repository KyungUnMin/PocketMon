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
	MsgAssert("다음 포켓몬이 없습니다.");
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
		Pokemons[i].SternRecorvery();
		Pokemons[i].ForInven_AllPowerPointRecovery();
		Pokemons[i].SetMonsterCurrentHP(Pokemons[i].GetMonsterMaxHP_int());
	}
}

