#pragma once
#include "BattleStateBase.h"

class BackTextActor;

class BattleState_ItemUse : public BattleStateBase
{
public:
	BattleState_ItemUse();
	~BattleState_ItemUse() override;

	BattleState_ItemUse(const BattleState_ItemUse& _Other) = delete;
	BattleState_ItemUse(BattleState_ItemUse&& _Other) noexcept = delete;
	BattleState_ItemUse& operator=(const BattleState_ItemUse& _Other) = delete;
	BattleState_ItemUse& operator=(const BattleState_ItemUse&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	BackTextActor* TextInfo = nullptr;

	bool IsAction = false;
	float Timer = 0.f;
	const float Duration = 2.f;
};

