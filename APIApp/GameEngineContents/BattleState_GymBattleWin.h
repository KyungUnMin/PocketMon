#pragma once
#include "BattleState_TalkBase.h"

class BattleState_GymBattleWin : public BattleState_TalkBase
{
public:
	BattleState_GymBattleWin();
	~BattleState_GymBattleWin() override;

	BattleState_GymBattleWin(const BattleState_GymBattleWin& _Other) = delete;
	BattleState_GymBattleWin(BattleState_GymBattleWin&& _Other) noexcept = delete;
	BattleState_GymBattleWin& operator=(const BattleState_GymBattleWin& _Other) = delete;
	BattleState_GymBattleWin& operator=(const BattleState_GymBattleWin&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	

private:
	static const std::vector<std::string_view> Texts;

};

