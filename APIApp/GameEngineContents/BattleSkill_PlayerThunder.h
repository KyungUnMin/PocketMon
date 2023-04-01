#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_Thunder;
class SkillActor_ThunderBack;
class SkillActor_BlackBox;

class BattleSkill_PlayerThunder : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerThunder();
	~BattleSkill_PlayerThunder();

	// delete Function
	BattleSkill_PlayerThunder(const BattleSkill_PlayerThunder& _Other) = delete;
	BattleSkill_PlayerThunder(BattleSkill_PlayerThunder&& _Other) noexcept = delete;
	BattleSkill_PlayerThunder& operator=(const BattleSkill_PlayerThunder& _Other) = delete;
	BattleSkill_PlayerThunder& operator=(BattleSkill_PlayerThunder&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	SkillActor_Thunder* ThunderRender1 = nullptr;
	SkillActor_Thunder* ThunderRender2 = nullptr;
	SkillActor_Thunder* ThunderRender3 = nullptr;
	SkillActor_Thunder* ThunderRender4 = nullptr;
	SkillActor_Thunder* ThunderRender5 = nullptr;

	SkillActor_BlackBox* BBox = nullptr;

	SkillActor_ThunderBack* BackGround1 = nullptr;
	SkillActor_ThunderBack* BackGround2 = nullptr;

	enum class MoveState
	{
		Forward,
		Backward,
		Flashing,
	};

	MoveState CurState = MoveState::Forward;

	float ForwardTime = 0.f;
	float BackwardTime = 0.f;
	float FlashingTime = 0.f;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);
	void Update_Flashing(float _Deltatime);
};

