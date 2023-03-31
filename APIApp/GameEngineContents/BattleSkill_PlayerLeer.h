#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
class SkillActor_Leer;

class BattleSkill_PlayerLeer : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerLeer();
	~BattleSkill_PlayerLeer();

	// delete Function
	BattleSkill_PlayerLeer(const BattleSkill_PlayerLeer& _Other) = delete;
	BattleSkill_PlayerLeer(BattleSkill_PlayerLeer&& _Other) noexcept = delete;
	BattleSkill_PlayerLeer& operator=(const BattleSkill_PlayerLeer& _Other) = delete;
	BattleSkill_PlayerLeer& operator=(BattleSkill_PlayerLeer&& _Other) noexcept = delete;

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

