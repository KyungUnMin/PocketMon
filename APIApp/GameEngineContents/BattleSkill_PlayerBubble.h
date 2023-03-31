#pragma once
#include "BattleSkill_PlayerBase.h"

class GameEngineRender;
// ��ų ���� class SkillActor_Leer;

class BattleSkill_PlayerBubble : public BattleSkill_PlayerBase
{
public:
	// constrcuter destructer
	BattleSkill_PlayerBubble();
	~BattleSkill_PlayerBubble();

	// delete Function
	BattleSkill_PlayerBubble(const BattleSkill_PlayerBubble& _Other) = delete;
	BattleSkill_PlayerBubble(BattleSkill_PlayerBubble&& _Other) noexcept = delete;
	BattleSkill_PlayerBubble& operator=(const BattleSkill_PlayerBubble& _Other) = delete;
	BattleSkill_PlayerBubble& operator=(BattleSkill_PlayerBubble&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerMonster = nullptr;
	GameEngineRender* EnemyMonster = nullptr;

	// ��ų ����
	// SkillActor_Growl* GrowlRender1 = nullptr;

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