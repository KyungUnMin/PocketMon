#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_Thunder : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_Thunder();
	~SkillActor_Thunder();

	// delete Function
	SkillActor_Thunder(const SkillActor_Thunder& _Other) = delete;
	SkillActor_Thunder(SkillActor_Thunder&& _Other) noexcept = delete;
	SkillActor_Thunder& operator=(const SkillActor_Thunder& _Other) = delete;
	SkillActor_Thunder& operator=(SkillActor_Thunder&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};
