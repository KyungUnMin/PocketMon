#pragma once
#include "BattleStateBase.h"

class BattleState_StageLose : public BattleStateBase
{
public:
	BattleState_StageLose();
	~BattleState_StageLose() override;

	BattleState_StageLose(const BattleState_StageLose& _Other) = delete;
	BattleState_StageLose(BattleState_StageLose&& _Other) noexcept = delete;
	BattleState_StageLose& operator=(const BattleState_StageLose& _Other) = delete;
	BattleState_StageLose& operator=(const BattleState_StageLose&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	class BackTextActor* TextInfo = nullptr;
	const float Duration = 2.f;
	float Timer = 0.f;
	bool IsAliveMonster = false;
};

