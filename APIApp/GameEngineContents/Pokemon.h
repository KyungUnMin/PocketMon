#pragma once
#include <list>
#include "PokeDataBase.h"
// ���� :
class Pokemon
{
public:
	// constrcuter destructer
	Pokemon();
	~Pokemon();

	// ���ϸ� �߰� (�����ͺ��̽�)
	void AddPokemon(PokeDataBase _PokeData);
	// ���ϸ� �߰� (������ȣ, ����)
	void AddPokemon(PokeNumber _Number, int _Level);

	// ���ϸ��� ���� �� ��� (6����)
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

