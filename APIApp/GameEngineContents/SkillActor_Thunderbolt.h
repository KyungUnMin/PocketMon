#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_Thunderbolt : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_Thunderbolt();
	~SkillActor_Thunderbolt();

	// delete Function
	SkillActor_Thunderbolt(const SkillActor_Thunderbolt& _Other) = delete;
	SkillActor_Thunderbolt(SkillActor_Thunderbolt&& _Other) noexcept = delete;
	SkillActor_Thunderbolt& operator=(const SkillActor_Thunderbolt& _Other) = delete;
	SkillActor_Thunderbolt& operator=(SkillActor_Thunderbolt&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};
