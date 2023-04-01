#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_AirSlash : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_AirSlash();
	~SkillActor_AirSlash();

	// delete Function
	SkillActor_AirSlash(const SkillActor_AirSlash& _Other) = delete;
	SkillActor_AirSlash(SkillActor_AirSlash&& _Other) noexcept = delete;
	SkillActor_AirSlash& operator=(const SkillActor_AirSlash& _Other) = delete;
	SkillActor_AirSlash& operator=(SkillActor_AirSlash&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	float OffTime = 0.0f;
};
