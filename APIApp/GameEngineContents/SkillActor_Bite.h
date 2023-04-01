#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_Bite : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_Bite();
	~SkillActor_Bite();

	// delete Function
	SkillActor_Bite(const SkillActor_Bite& _Other) = delete;
	SkillActor_Bite(SkillActor_Bite&& _Other) noexcept = delete;
	SkillActor_Bite& operator=(const SkillActor_Bite& _Other) = delete;
	SkillActor_Bite& operator=(SkillActor_Bite&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};
