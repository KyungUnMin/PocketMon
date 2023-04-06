#pragma once
#include "BattleState_TalkBase.h"

class BattleState_NpcTalk : public BattleState_TalkBase
{
public:
	BattleState_NpcTalk();
	~BattleState_NpcTalk() override;

	BattleState_NpcTalk(const BattleState_NpcTalk& _Other) = delete;
	BattleState_NpcTalk(BattleState_NpcTalk&& _Other) noexcept = delete;
	BattleState_NpcTalk& operator=(const BattleState_NpcTalk& _Other) = delete;
	BattleState_NpcTalk& operator=(const BattleState_NpcTalk&& _Other) noexcept = delete;

protected:
	void EnterState() override;

private:
	static const std::vector<std::string> Texts;
};

