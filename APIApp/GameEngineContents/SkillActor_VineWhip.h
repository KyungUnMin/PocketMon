#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_VineWhip : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_VineWhip();
	~SkillActor_VineWhip();

	// delete Function
	SkillActor_VineWhip(const SkillActor_VineWhip& _Other) = delete;
	SkillActor_VineWhip(SkillActor_VineWhip&& _Other) noexcept = delete;
	SkillActor_VineWhip& operator=(const SkillActor_VineWhip& _Other) = delete;
	SkillActor_VineWhip& operator=(SkillActor_VineWhip&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};