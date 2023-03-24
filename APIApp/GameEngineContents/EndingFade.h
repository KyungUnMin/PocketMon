#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;
class EndingFade : public GameEngineActor
{
public:
	EndingFade();
	~EndingFade();

	EndingFade(const EndingFade& _Other) = delete;
	EndingFade(EndingFade&& _Other) noexcept = delete;
	EndingFade& operator=(const EndingFade& _Other) = delete;
	EndingFade& operator=(EndingFade&& _Other) noexcept = delete;

	void SetProgress(float _Progress);

	inline void SetSpeed(float _Speed)
	{
		Speed = _Speed;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* FadeRender = nullptr;

	float Progress = 0.0f;
	float Speed = 1.0f;

	void CalculationAlpha();
};