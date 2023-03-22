#pragma once
#include "BattleMonsterBase.h"

class BattleMonsterEnemy : public BattleMonsterBase
{
public:
	BattleMonsterEnemy();
	~BattleMonsterEnemy() override;

	BattleMonsterEnemy(const BattleMonsterEnemy& _Other) = delete;
	BattleMonsterEnemy(BattleMonsterEnemy&& _Other) noexcept = delete;
	BattleMonsterEnemy& operator=(const BattleMonsterEnemy& _Other) = delete;
	BattleMonsterEnemy& operator=(const BattleMonsterEnemy&& _Other) noexcept = delete;

	void Init(PokeNumber _MonsterType, bool _IsWildMonster);

protected:
	void Update(float _DeltaTime) override;

private:
	enum class State
	{
		Move,
		Appear,
		Ready,
	};

	bool IsWildMonster = false;
	State CurState = State::Appear;
	GameEngineRender* MonsterRender = nullptr;
	GameEngineRender* AppearRender = nullptr;
	const float4 StartAlpha = float4{ 100.f, 0.f };

	float AppearTime = 0.f;

	void RenderCreate();
	void Update_Move();
	void Update_WildAppear();
	void Update_NPCAppear();
};

