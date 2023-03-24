#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class EndingPokemonRender : public GameEngineActor
{
public:
	EndingPokemonRender();
	~EndingPokemonRender();

	EndingPokemonRender(const EndingPokemonRender& _Other) = delete;
	EndingPokemonRender(EndingPokemonRender&& _Other) noexcept = delete;
	EndingPokemonRender& operator=(const EndingPokemonRender& _Other) = delete;
	EndingPokemonRender& operator=(EndingPokemonRender&& _Other) noexcept = delete;

	inline void SetPokemonImageName(const std::string_view& _ImageName)
	{
		PokemonImageName = _ImageName;
	}

	inline void SetAnimSpeed(float _Speed)
	{
		Speed = _Speed;
	}

	inline void SetAlpha(int _Alpha)
	{
		Alpha = _Alpha;
	}

	void PlayAnim(const std::string_view& _ImageName);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* PokemonRender = nullptr;
	std::string PokemonImageName;

	float Progress = 0.0f;
	float Speed = 1.0f;

	int Alpha = 255;
};