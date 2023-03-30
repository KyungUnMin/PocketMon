#pragma once
#include "BattleState_TalkBase.h"

class BattleState_PlayerDeadChange : public BattleState_TalkBase
{
public:
	static const std::vector<std::string_view> Texts;

	BattleState_PlayerDeadChange();
	~BattleState_PlayerDeadChange() override;

	BattleState_PlayerDeadChange(const BattleState_PlayerDeadChange& _Other) = delete;
	BattleState_PlayerDeadChange(BattleState_PlayerDeadChange&& _Other) noexcept = delete;
	BattleState_PlayerDeadChange& operator=(const BattleState_PlayerDeadChange& _Other) = delete;
	BattleState_PlayerDeadChange& operator=(const BattleState_PlayerDeadChange&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;


private:

};

