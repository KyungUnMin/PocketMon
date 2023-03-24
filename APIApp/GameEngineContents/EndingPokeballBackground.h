#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class EndingPokeballBackground : public GameEngineActor
{
public:
	enum class PokeColor
	{
		Red,
		Blue,
		Green,
		Yellow
	};

public:
	EndingPokeballBackground();
	~EndingPokeballBackground();

	EndingPokeballBackground(const EndingPokeballBackground& _Other) = delete;
	EndingPokeballBackground(EndingPokeballBackground&& _Other) noexcept = delete;
	EndingPokeballBackground& operator=(const EndingPokeballBackground& _Other) = delete;
	EndingPokeballBackground& operator=(EndingPokeballBackground&& _Other) noexcept = delete;

	void PlayPokeballAnim(PokeColor _Color);
	void SetColor(PokeColor _Color);

	inline void SetAnimSpeed(float _Speed)
	{
		Speed = _Speed;
	}

	inline void SetAlpha(int _Alpha)
	{
		Alpha = _Alpha;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* PokeballRender = nullptr;
	GameEngineRender* EndingRing = nullptr;

	float Progress = 0.0f;
	float Speed = 1.0f;

	int Alpha = 255;

	const float4 StartSize = float4(1280, 1280, 0, 1);
	const float4 DestSize = float4(640, 640, 0, 1);
};