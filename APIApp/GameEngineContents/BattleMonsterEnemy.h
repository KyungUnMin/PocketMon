#pragma once
#include "BattleMonsterBase.h"

class BattleEnemyMonsterFSM;

class BattleMonsterEnemy : public BattleMonsterBase
{
public:
	BattleMonsterEnemy();
	~BattleMonsterEnemy() override;

	BattleMonsterEnemy(const BattleMonsterEnemy& _Other) = delete;
	BattleMonsterEnemy(BattleMonsterEnemy&& _Other) noexcept = delete;
	BattleMonsterEnemy& operator=(const BattleMonsterEnemy& _Other) = delete;
	BattleMonsterEnemy& operator=(const BattleMonsterEnemy&& _Other) noexcept = delete;

	void Init(PokeNumber _MonsterType, bool _IsWildMonster = false);

	inline BattleEnemyMonsterFSM* GetFSM()
	{
		return FsmPtr;
	}

protected:
	void Update(float _DeltaTime) override;

private:
	BattleEnemyMonsterFSM* FsmPtr = nullptr;

	GameEngineRender* MonsterRender = nullptr;

	void RenderCreate();
};

