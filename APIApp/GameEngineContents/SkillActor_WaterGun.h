#pragma once

#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SkillActor_WaterGun : public GameEngineActor
{
public:
	// constrcuter destructer
	SkillActor_WaterGun();
	~SkillActor_WaterGun();

	// delete Function
	SkillActor_WaterGun(const SkillActor_WaterGun& _Other) = delete;
	SkillActor_WaterGun(SkillActor_WaterGun&& _Other) noexcept = delete;
	SkillActor_WaterGun& operator=(const SkillActor_WaterGun& _Other) = delete;
	SkillActor_WaterGun& operator=(SkillActor_WaterGun&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

};
