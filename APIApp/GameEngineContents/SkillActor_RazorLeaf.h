#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_RazorLeaf : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_RazorLeaf();
	~SkillActor_RazorLeaf();

	// delete Function
	SkillActor_RazorLeaf(const SkillActor_RazorLeaf& _Other) = delete;
	SkillActor_RazorLeaf(SkillActor_RazorLeaf&& _Other) noexcept = delete;
	SkillActor_RazorLeaf& operator=(const SkillActor_RazorLeaf& _Other) = delete;
	SkillActor_RazorLeaf& operator=(SkillActor_RazorLeaf&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};
