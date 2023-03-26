#pragma once
#include "BattleState_TalkBase.h"

class BattleState_WildTalk : public BattleState_TalkBase
{
public:
	static const std::vector<std::string_view> Texts;

	BattleState_WildTalk();
	~BattleState_WildTalk() override;

	BattleState_WildTalk(const BattleState_WildTalk& _Other) = delete;
	BattleState_WildTalk(BattleState_WildTalk&& _Other) noexcept = delete;
	BattleState_WildTalk& operator=(const BattleState_WildTalk& _Other) = delete;
	BattleState_WildTalk& operator=(const BattleState_WildTalk&& _Other) noexcept = delete;

protected:
	void EnterState() override;

private:
};

