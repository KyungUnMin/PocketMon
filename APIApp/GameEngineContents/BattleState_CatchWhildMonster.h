#pragma once
#include "BattleStateBase.h"
#include "PokeDataBase.h"

class BackTextActor;
enum class SpecialPokeEnum;

class BattleState_CatchWhildMonster : public BattleStateBase
{
public:
	BattleState_CatchWhildMonster();
	~BattleState_CatchWhildMonster() override;

	BattleState_CatchWhildMonster(const BattleState_CatchWhildMonster& _Other) = delete;
	BattleState_CatchWhildMonster(BattleState_CatchWhildMonster&& _Other) noexcept = delete;
	BattleState_CatchWhildMonster& operator=(const BattleState_CatchWhildMonster& _Other) = delete;
	BattleState_CatchWhildMonster& operator=(const BattleState_CatchWhildMonster&& _Other) noexcept = delete;

protected:
	void EnterState() override;
	void Update(float _DeltaTime) override;
	void ExitState() override;

private:
	BackTextActor* TextInfoUI = nullptr;
	const float FadeTime = 1.f;
	float LiveTime = 0.f;
	bool IsPushed = false;

	SpecialPokeEnum PokeNumToSpecialConvertor(PokeNumber _Index);
};

