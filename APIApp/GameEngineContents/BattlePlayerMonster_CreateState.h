#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include "BattleStateBase.h"

class BattleMonsterPlayer;
class GameEngineRender;

class BattlePlayerMonster_CreateState : public BattleStateBase
{
public:
	BattlePlayerMonster_CreateState();
	~BattlePlayerMonster_CreateState() override;

	BattlePlayerMonster_CreateState(const BattlePlayerMonster_CreateState& _Other) = delete;
	BattlePlayerMonster_CreateState(BattlePlayerMonster_CreateState&& _Other) noexcept = delete;
	BattlePlayerMonster_CreateState& operator=(const BattlePlayerMonster_CreateState& _Other) = delete;
	BattlePlayerMonster_CreateState& operator=(const BattlePlayerMonster_CreateState&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	BattleMonsterPlayer* Monster = nullptr;
	GameEngineRender* EffectRender = nullptr;


	float Timer = 0.f;
	float Duration = 0.f;
	float4 DestScale = float4::Zero;
};

