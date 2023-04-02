#pragma once

#include <GameEngineCore/GameEngineActor.h>

enum class LeafSet
{
	Leafs_Stop,
	Leafs_Move,
	Leafs_Shoot,
	RazorLeaf,
	Leafs_Stop_L,
	Leafs_Move_L,
	Leafs_Shoot_L,
};

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

	void LeafSetting(LeafSet _Set);

	float GetMoveSpeed()
	{
		return MoveSpeed;
	}

	bool IsRazorShoot()
	{
		return IsRazor;
	}

protected:
	void Start() override;
	void Update(float _Deltatime) override;

private:
	GameEngineRender* RenderPtr = nullptr;

	bool IsLeafs = false;
	bool IsRazor = false;
	bool IsMove = false;
	bool IsMove_L = false;

	int SetCount = 1;

	float MoveSpeed = 300.0f;
	float Alphatime = 0.0f;

	void AlphaControl(float _Deltatime);
};
