#pragma once
#include "BattleState_TalkBase.h"

class BattleState_LeafTalk : public BattleState_TalkBase
{
public:
	BattleState_LeafTalk();
	~BattleState_LeafTalk() override;

	BattleState_LeafTalk(const BattleState_LeafTalk& _Other) = delete;
	BattleState_LeafTalk(BattleState_LeafTalk&& _Other) noexcept = delete;
	BattleState_LeafTalk& operator=(const BattleState_LeafTalk& _Other) = delete;
	BattleState_LeafTalk& operator=(const BattleState_LeafTalk&& _Other) noexcept = delete;

protected:
	void EnterState() override;

private:
	static const std::vector<std::string_view> Texts;
};

