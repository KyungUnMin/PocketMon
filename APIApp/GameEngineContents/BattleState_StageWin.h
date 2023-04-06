#pragma once
#include "BattleStateBase.h"
#include <string>

class BackTextActor;

class BattleState_StageWin : public BattleStateBase
{
public:
	BattleState_StageWin();
	~BattleState_StageWin() override;

	BattleState_StageWin(const BattleState_StageWin& _Other) = delete;
	BattleState_StageWin(BattleState_StageWin&& _Other) noexcept = delete;
	BattleState_StageWin& operator=(const BattleState_StageWin& _Other) = delete;
	BattleState_StageWin& operator=(const BattleState_StageWin&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	BackTextActor* TextInfo = nullptr;

	float Timer = 0.f;
	const float Duration = 2.f;

	std::string MakeText();
};

