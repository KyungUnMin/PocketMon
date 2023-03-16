#pragma once
#include "BattleTrainerBase.h"

class BattleNPC : public BattleTrainerBase
{
public:
	static BattleNPC* NpcPtr;

	BattleNPC();
	~BattleNPC() override;

	BattleNPC(const BattleNPC& _Other) = delete;
	BattleNPC(BattleNPC&& _Other) noexcept = delete;
	BattleNPC& operator=(const BattleNPC& _Other) = delete;
	BattleNPC& operator=(const BattleNPC&& _Other) noexcept = delete;

protected:
	void Start() override;

private:

};

