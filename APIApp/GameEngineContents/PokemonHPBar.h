#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class PokemonHPBar : public GameEngineActor
{
public:
	// constrcuter destructer
	PokemonHPBar();
	~PokemonHPBar();

	void SetValue(float _Value);
	void SetTargetValue(float _Value);

	// delete Function
	PokemonHPBar(const PokemonHPBar& _Other) = delete;
	PokemonHPBar(PokemonHPBar&& _Other) noexcept = delete;
	PokemonHPBar& operator=(const PokemonHPBar& _Other) = delete;
	PokemonHPBar& operator=(PokemonHPBar&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	GameEngineRender* BarRender = nullptr;
	float CurrentValue = 0.0f;
	float StartValue = 0.0f;
	float TargetValue = 0.0f;
	float Timer = 0;
};

