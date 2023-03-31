#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_Bubble : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_Bubble();
	~SkillActor_Bubble();

	// delete Function
	SkillActor_Bubble(const SkillActor_Bubble& _Other) = delete;
	SkillActor_Bubble(SkillActor_Bubble&& _Other) noexcept = delete;
	SkillActor_Bubble& operator=(const SkillActor_Bubble& _Other) = delete;
	SkillActor_Bubble& operator=(SkillActor_Bubble&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};
