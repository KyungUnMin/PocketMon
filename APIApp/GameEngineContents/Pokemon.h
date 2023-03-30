#pragma once
#include <list>
#include "PokeDataBase.h"
// 설명 :
class Pokemon
{
public:
	// constrcuter destructer
	Pokemon();
	~Pokemon();

	// 포켓몬 추가 (데이터베이스)
	void AddPokemon(PokeDataBase _PokeData);
	// 포켓몬 추가 (도감번호, 레벨)
	void AddPokemon(PokeNumber _Number, int _Level);

	// 포켓몬이 가득 찬 경우 (6마리)
	bool IsFull()
	{
		return PokemonMax == PokemonList.size();
	}


	// delete Function
	Pokemon(const Pokemon& _Other) = delete;
	Pokemon(Pokemon&& _Other) noexcept = delete;
	Pokemon& operator=(const Pokemon& _Other) = delete;
	Pokemon& operator=(Pokemon&& _Other) noexcept = delete;

protected:

private:
	std::list<PokeDataBase> PokemonList;
	const int PokemonMax = 6;
};

