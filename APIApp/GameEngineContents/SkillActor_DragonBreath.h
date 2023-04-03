#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :

class GameEngineRender;
class SkillActor_DragonBreath : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_DragonBreath();
	~SkillActor_DragonBreath();

	void SetDragonBreath(const float4& _StartPos, const float4& _EndPos, float _WaitTime = 0);

	// delete Function
	SkillActor_DragonBreath(const SkillActor_DragonBreath& _Other) = delete;
	SkillActor_DragonBreath(SkillActor_DragonBreath&& _Other) noexcept = delete;
	SkillActor_DragonBreath& operator=(const SkillActor_DragonBreath& _Other) = delete;
	SkillActor_DragonBreath& operator=(SkillActor_DragonBreath&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* EffectRender = nullptr;
	float4 StartPos = { 372, -182 };
	float4 EndPos = { 48, 12 };
	float WaitTime = 0.f;
	bool IsLeft = false;
	enum class DragonBreathState
	{
		Shoot,
		Burn
	};

	DragonBreathState CurState = DragonBreathState::Shoot;
};

