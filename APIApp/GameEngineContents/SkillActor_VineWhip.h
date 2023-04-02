#pragma once

#include <GameEngineCore/GameEngineActor.h>

enum class VineSet
{
	Vine_R,
	Vine_R_Stop,
	Vine_L,
	Vine_L_Stop,
	VineWhip,
};

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

	void VineSetting(VineSet _Set);
	void AlphaControl(int _Value);

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	bool IsVine_R = false;
	bool IsVine_L = false;
	bool IsVineWhip = false;

};