#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;

class Battle_MonsterAppearEffect : public GameEngineActor
{
public:
	Battle_MonsterAppearEffect();
	~Battle_MonsterAppearEffect() override;

	Battle_MonsterAppearEffect(const Battle_MonsterAppearEffect& _Other) = delete;
	Battle_MonsterAppearEffect(Battle_MonsterAppearEffect&& _Other) noexcept = delete;
	Battle_MonsterAppearEffect& operator=(const Battle_MonsterAppearEffect& _Other) = delete;
	Battle_MonsterAppearEffect& operator=(const Battle_MonsterAppearEffect&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	enum class FadeState
	{
		FadeIn,
		FadeOut,
	};

	float FadeTime = 0.f;
	FadeState CurState = FadeState::FadeIn;

	GameEngineRender* WhiteFade = nullptr;

	bool Update_Fade(float _StartAlpha, float _DestAlpha);
};

