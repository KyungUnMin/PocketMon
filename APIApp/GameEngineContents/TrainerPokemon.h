#pragma once
#include <vector>
#include "PokeDataBase.h"
// ���� :
class TrainerPokemon
{
	friend class PokemonUI;
	friend class SummaryUI;
public:
	// constrcuter destructer
	TrainerPokemon();
	~TrainerPokemon();

	// ���ϸ� �߰� (�����ͺ��̽�)
	void AddPokemon(PokeDataBase _PokeData);
	// ���ϸ� �߰� (������ȣ, ����)
	void AddPokemon(int _Number, int _Level);

	// ���ϸ��� ���� �� ��� (6����)
	bool IsFull();

	// ��� ���ϸ��� �޾ƿ´�.
	std::vector<PokeDataBase> GetPokemons();

	// ���� ���ϸ��� �޾ƿ´�.
	PokeDataBase NextPokemon();

	// ���� ���ϸ��� �ִٸ� true�� ��ȯ�մϴ�.
	bool HasNextPokemon();

	inline size_t GetPokemonCount() const
	{
		return Pokemons.size();
	}

	// delete Function
	TrainerPokemon(const TrainerPokemon& _Other) = delete;
	TrainerPokemon(TrainerPokemon&& _Other) noexcept = delete;
	TrainerPokemon& operator=(const TrainerPokemon& _Other) = delete;
	TrainerPokemon& operator=(TrainerPokemon&& _Other) noexcept = delete;

protected:

private:
	std::vector<PokeDataBase> Pokemons;
	const int PokemonMax = 6;
};

