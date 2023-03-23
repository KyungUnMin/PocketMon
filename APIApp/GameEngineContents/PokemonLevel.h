#pragma once
#include <GameEngineCore/GameEngineLevel.h>

#include <vector>
// Ό³Έν :
class PokeDataBase;
class PokemonLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	PokemonLevel();
	~PokemonLevel();

	// delete Function
	PokemonLevel(const PokemonLevel& _Other) = delete;
	PokemonLevel(PokemonLevel&& _Other) noexcept = delete;
	PokemonLevel& operator=(const PokemonLevel& _Other) = delete;
	PokemonLevel& operator=(PokemonLevel&& _Other) noexcept = delete;

protected:
	void Loading() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _NextLevel) override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
private:
};

