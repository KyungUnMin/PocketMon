#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;
class SkillActor_Thunderbolt;
class SkillActor_BlackBox;

class BattleSkill_EnemyThunderbolt : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyThunderbolt();
	~BattleSkill_EnemyThunderbolt();

	// delete Function
	BattleSkill_EnemyThunderbolt(const BattleSkill_EnemyThunderbolt& _Other) = delete;
	BattleSkill_EnemyThunderbolt(BattleSkill_EnemyThunderbolt&& _Other) noexcept = delete;
	BattleSkill_EnemyThunderbolt& operator=(const BattleSkill_EnemyThunderbolt& _Other) = delete;
	BattleSkill_EnemyThunderbolt& operator=(BattleSkill_EnemyThunderbolt&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	SkillActor_BlackBox* BBox = nullptr;

	SkillActor_Thunderbolt* ThunderboltRender1 = nullptr;
	SkillActor_Thunderbolt* ThunderboltRender2 = nullptr;
	SkillActor_Thunderbolt* ThunderboltRender3 = nullptr;
	SkillActor_Thunderbolt* ThunderboltRender4 = nullptr;
	SkillActor_Thunderbolt* ThunderboltRender5 = nullptr;

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