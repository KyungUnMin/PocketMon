#pragma once
#include <vector>
#include "PokeDataBase.h"
// 설명 :
class TrainerPokemon
{
public:
	// constrcuter destructer
	TrainerPokemon();
	~TrainerPokemon();

	// 포켓몬 추가 (데이터베이스)
	void AddPokemon(PokeDataBase _PokeData);
	// 포켓몬 추가 (도감번호, 레벨)
	void AddPokemon(int _Number, int _Level);

	// 포켓몬이 가득 찬 경우 (6마리)
	bool IsFull();

	// 모든 포켓몬을 받아온다.
	std::vector<PokeDataBase> GetPokemons();

	// 다음 포켓몬을 받아온다.
	PokeDataBase NextPokemon();

	// 다음 포켓몬이 있다면 true를 반환합니다.
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

