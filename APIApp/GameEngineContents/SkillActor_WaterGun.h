#pragma once

#include <GameEngineCore/GameEngineActor.h>

enum class WaterGunSet
{
	WaterGun_Shoot_R,
	WaterGun_Shoot_L,
	WaterGun_Stop,
};

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

	void WaterGunSetting(WaterGunSet _Set);

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	bool IsShoot = false;
	float Alphatime = 0.0f;

	void AlphaControl(float _Deltatime);
};
