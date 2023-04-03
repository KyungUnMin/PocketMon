#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :

class GameEngineRender;
class SkillActor_Ember : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_Ember();
	~SkillActor_Ember();

	void SetEmber(const float4& _StartPos, const float4& _EndPos);

	// delete Function
	SkillActor_Ember(const SkillActor_Ember& _Other) = delete;
	SkillActor_Ember(SkillActor_Ember&& _Other) noexcept = delete;
	SkillActor_Ember& operator=(const SkillActor_Ember& _Other) = delete;
	SkillActor_Ember& operator=(SkillActor_Ember&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	GameEngineRender* EffectRender = nullptr;
	float4 StartPos = { 372, -182 };
	float4 EndPos = { 48, 12 };
	bool IsLeft = false;
	enum class EmberState
	{
		Shoot,
		Burn
	};

	EmberState CurState = EmberState::Shoot;
};

