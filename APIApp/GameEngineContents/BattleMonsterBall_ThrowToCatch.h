#pragma once
#include "BattleMonsterBall_ThrowBase.h"

class BattleMonsterBall_ThrowToCatch : public BattleMonsterBall_ThrowBase
{
public:
	BattleMonsterBall_ThrowToCatch();
	~BattleMonsterBall_ThrowToCatch() override;

	BattleMonsterBall_ThrowToCatch(const BattleMonsterBall_ThrowToCatch& _Other) = delete;
	BattleMonsterBall_ThrowToCatch(BattleMonsterBall_ThrowToCatch&& _Other) noexcept = delete;
	BattleMonsterBall_ThrowToCatch& operator=(const BattleMonsterBall_ThrowToCatch& _Other) = delete;
	BattleMonsterBall_ThrowToCatch& operator=(const BattleMonsterBall_ThrowToCatch&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitExcute() override;

private:
};

