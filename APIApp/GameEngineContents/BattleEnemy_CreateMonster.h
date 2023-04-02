#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class GameEngineRender;

class BattleEnemy_CreateMonster : public BattleStateBase
{
public:
	BattleEnemy_CreateMonster();
	~BattleEnemy_CreateMonster() override;

	BattleEnemy_CreateMonster(const BattleEnemy_CreateMonster& _Other) = delete;
	BattleEnemy_CreateMonster(BattleEnemy_CreateMonster&& _Other) noexcept = delete;
	BattleEnemy_CreateMonster& operator=(const BattleEnemy_CreateMonster& _Other) = delete;
	BattleEnemy_CreateMonster& operator=(const BattleEnemy_CreateMonster&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* EnemyRender = nullptr;

	float Timer = 0.f;
	const float Duration = 0.5f;

	float4 OriginOffset = float4::Zero;
	const float MoveOffset = 400.f;
};

