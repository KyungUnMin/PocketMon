#pragma once
#include "BattleState_TalkBase.h"


class BattleState_NextStage : public BattleState_TalkBase
{
public:
	BattleState_NextStage();
	~BattleState_NextStage() override;

	BattleState_NextStage(const BattleState_NextStage& _Other) = delete;
	BattleState_NextStage(BattleState_NextStage&& _Other) noexcept = delete;
	BattleState_NextStage& operator=(const BattleState_NextStage& _Other) = delete;
	BattleState_NextStage& operator=(const BattleState_NextStage&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	static const std::vector<std::string> Texts;

};

