#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class PokemonUI : GameEngineActor
{
public:
	// constrcuter destructer
	PokemonUI();
	~PokemonUI();

	// delete Function
	PokemonUI(const PokemonUI& _Other) = delete;
	PokemonUI(PokemonUI&& _Other) noexcept = delete;
	PokemonUI& operator=(const PokemonUI& _Other) = delete;
	PokemonUI& operator=(PokemonUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	void LevelChangeEnd(GameEngineLevel* _PrevLevel) override;
	void LevelChangeStart(GameEngineLevel* _PrevLevel) override;
private:

};

