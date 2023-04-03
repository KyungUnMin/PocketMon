#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :

class GameEngineRender;
class SkillActor_DragonBrath : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_DragonBrath();
	~SkillActor_DragonBrath();

	void SetDragonBrath(const float4& _StartPos, const float4& _EndPos, float _WaitTime = 0);

	// delete Function
	SkillActor_DragonBrath(const SkillActor_DragonBrath& _Other) = delete;
	SkillActor_DragonBrath(SkillActor_DragonBrath&& _Other) noexcept = delete;
	SkillActor_DragonBrath& operator=(const SkillActor_DragonBrath& _Other) = delete;
	SkillActor_DragonBrath& operator=(SkillActor_DragonBrath&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* EffectRender = nullptr;
	float4 StartPos = { 372, -182 };
	float4 EndPos = { 48, 12 };
	float WaitTime = 0.f;
	bool IsLeft = false;
	enum class DragonBrathState
	{
		Shoot,
		Burn
	};

	DragonBrathState CurState = DragonBrathState::Shoot;
};

