#pragma once
#include <GameEngineCore/GameEngineActor.h>

class BattleTrainerBase : public GameEngineActor
{
public:
	//BattlePlayer와 BattleEnemy의 FSM에서 사용
	static const float MoveDuration;

	BattleTrainerBase();
	~BattleTrainerBase() override;

	BattleTrainerBase(const BattleTrainerBase& _Other) = delete;
	BattleTrainerBase(BattleTrainerBase&& _Other) noexcept = delete;
	BattleTrainerBase& operator=(const BattleTrainerBase& _Other) = delete;
	BattleTrainerBase& operator=(const BattleTrainerBase&& _Other) noexcept = delete;

	virtual class GameEngineRender* GetTrainerRender() = 0;

protected:

private:
};

