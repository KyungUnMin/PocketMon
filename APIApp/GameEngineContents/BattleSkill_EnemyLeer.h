#pragma once
#include "BattleSkill_EnemyBase.h"

class GameEngineRender;
class SkillActor_Leer;

// Ό³Έν :
class BattleSkill_EnemyLeer : public BattleSkill_EnemyBase
{
public:
	// constrcuter destructer
	BattleSkill_EnemyLeer();
	~BattleSkill_EnemyLeer();

	// delete Function
	BattleSkill_EnemyLeer(const BattleSkill_EnemyLeer& _Other) = delete;
	BattleSkill_EnemyLeer(BattleSkill_EnemyLeer&& _Other) noexcept = delete;
	BattleSkill_EnemyLeer& operator=(const BattleSkill_EnemyLeer& _Other) = delete;
	BattleSkill_EnemyLeer& operator=(BattleSkill_EnemyLeer&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	SkillActor_Leer* LeerRender = nullptr;

	enum class MoveState
	{
		Forward,
		Backward
	};

	MoveState CurState = MoveState::Forward;

	float ForwardTime = 0.f;
	float BackwardTime = 0.f;

	void Update_Forward(float _Deltatime);
	void Update_BackWard(float _Deltatime);

};

