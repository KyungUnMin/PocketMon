#pragma once
#include "BattleStateBase.h"
#include <GameEngineBase/GameEngineMath.h>

class GameEngineRender;

class BattlePlayer_ThrowState : public BattleStateBase
{
public:
	BattlePlayer_ThrowState();
	~BattlePlayer_ThrowState() override;

	BattlePlayer_ThrowState(const BattlePlayer_ThrowState& _Other) = delete;
	BattlePlayer_ThrowState(BattlePlayer_ThrowState&& _Other) noexcept = delete;
	BattlePlayer_ThrowState& operator=(const BattlePlayer_ThrowState& _Other) = delete;
	BattlePlayer_ThrowState& operator=(const BattlePlayer_ThrowState&& _Other) noexcept = delete;

	
protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	GameEngineRender* PlayerRender = nullptr;
	const float ThrowDuration = 0.5f;
	const float MoveSpeed = 800.f;
	float Timer = 0.f;
};

