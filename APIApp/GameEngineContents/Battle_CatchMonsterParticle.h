#pragma once
#include <GameEngineCore/GameEngineActor.h>

class Battle_CatchMonsterParticle : public GameEngineActor
{
public:
	Battle_CatchMonsterParticle();
	~Battle_CatchMonsterParticle() override;

	Battle_CatchMonsterParticle(const Battle_CatchMonsterParticle& _Other) = delete;
	Battle_CatchMonsterParticle(Battle_CatchMonsterParticle&& _Other) noexcept = delete;
	Battle_CatchMonsterParticle& operator=(const Battle_CatchMonsterParticle& _Other) = delete;
	Battle_CatchMonsterParticle& operator=(const Battle_CatchMonsterParticle&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	const float4 RenderScale = float4{ 24.f, 24.f };
	const float Duration = 1.5f;
	std::vector<std::pair<GameEngineRender*, float4>> Particles;
};

