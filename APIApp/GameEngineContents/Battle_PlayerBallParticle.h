#pragma once
#include <GameEngineCore/GameEngineActor.h>

class GameEngineRender;

class Battle_PlayerBallParticle : public GameEngineActor
{
public:
	Battle_PlayerBallParticle();
	~Battle_PlayerBallParticle() override;

	Battle_PlayerBallParticle(const Battle_PlayerBallParticle& _Other) = delete;
	Battle_PlayerBallParticle(Battle_PlayerBallParticle&& _Other) noexcept = delete;
	Battle_PlayerBallParticle& operator=(const Battle_PlayerBallParticle& _Other) = delete;
	Battle_PlayerBallParticle& operator=(const Battle_PlayerBallParticle&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	const float4 RenderScale = float4{ 24.f, 24.f };
	const float Duration = 1.5f;
	std::vector<std::pair<GameEngineRender*, float4>> Particles;
};

