#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_DragonBrath : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_DragonBrath();
	~SkillActor_DragonBrath();

	// delete Function
	SkillActor_DragonBrath(const SkillActor_DragonBrath& _Other) = delete;
	SkillActor_DragonBrath(SkillActor_DragonBrath&& _Other) noexcept = delete;
	SkillActor_DragonBrath& operator=(const SkillActor_DragonBrath& _Other) = delete;
	SkillActor_DragonBrath& operator=(SkillActor_DragonBrath&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};
