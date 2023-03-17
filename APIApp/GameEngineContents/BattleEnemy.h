#pragma once
#include "BattleTrainerBase.h"

class BattleEnemy : public BattleTrainerBase
{
public:
	static BattleEnemy* NpcPtr;

	BattleEnemy();
	~BattleEnemy() override;

	BattleEnemy(const BattleEnemy& _Other) = delete;
	BattleEnemy(BattleEnemy&& _Other) noexcept = delete;
	BattleEnemy& operator=(const BattleEnemy& _Other) = delete;
	BattleEnemy& operator=(const BattleEnemy&& _Other) noexcept = delete;

	void Init(BattleFieldType _FieldType) override;

protected:

private:

	void CreateGround(BattleFieldType _FieldType);
	void CreatePlayer();
};

