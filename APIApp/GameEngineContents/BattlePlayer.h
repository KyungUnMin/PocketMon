#pragma once
#include "BattleTrainerBase.h"

class BattlePlayer : public BattleTrainerBase
{
public:
	static BattlePlayer* PlayerPtr;

	BattlePlayer();
	~BattlePlayer() override;

	BattlePlayer(const BattlePlayer& _Other) = delete;
	BattlePlayer(BattlePlayer&& _Other) noexcept = delete;
	BattlePlayer& operator=(const BattlePlayer& _Other) = delete;
	BattlePlayer& operator=(const BattlePlayer&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType) override;

protected:

private:
	

	void CreateGround(BattleFieldType _FieldType);
	void CreatePlayer();
};

