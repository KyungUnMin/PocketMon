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
	float GravityForce = 5000.0f;
	float MoveSpeed = 300.0f;
	float Timer = 0;

	enum class SkillState {
		Fall,
		Jump
	};
	SkillState CurState = SkillState::Fall;

	void FallUpdate(float _DeltaTime);
	void JumpUpdate(float _DeltaTime);
};

