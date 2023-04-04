#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class GameEngineRender;
class SkillActor_RockThrow : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_RockThrow();
	~SkillActor_RockThrow();
	void SetRock(const float4& _Pos, const float4& _Scale, float _Delay, bool _IsLeft);
	// delete Function
	SkillActor_RockThrow(const SkillActor_RockThrow& _Other) = delete;
	SkillActor_RockThrow(SkillActor_RockThrow&& _Other) noexcept = delete;
	SkillActor_RockThrow& operator=(const SkillActor_RockThrow& _Other) = delete;
	SkillActor_RockThrow& operator=(SkillActor_RockThrow&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	GameEngineRender* EffectRender = nullptr;
	const float MaxGravity = 1000.0f;
	float CurrentGravity = 0;
	float GravityForce = 2000.0f;
	float MoveSpeed = 200.0f;
	float Delay = 0.0f;
	bool IsLeft = false;
	enum class SkillState {
		Fall,
		Jump
	};
	SkillState CurState = SkillState::Fall;

	void FallUpdate(float _DeltaTime);
	void JumpUpdate(float _DeltaTime);
};

