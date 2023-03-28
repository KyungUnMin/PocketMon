#include "BattleState_MonsterDead.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleFSMBase.h"
#include "BattleMonsterBase.h"

BattleState_MonsterDead::BattleState_MonsterDead()
{

}

BattleState_MonsterDead::~BattleState_MonsterDead()
{

}

void BattleState_MonsterDead::EnterState()
{
	GameEngineActor* OwnerActor = GetFSM()->GetOwner();
	BattleMonsterBase* OwnerMonster = dynamic_cast<BattleMonsterBase*>(OwnerActor);
	MonsterRender = OwnerMonster->GetRender();
}

void BattleState_MonsterDead::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Duration < Timer)
	{

		return;
	}

	float Ratio = (Timer / Duration);

	float NowAlpha = 255.f - (255.f * Ratio);
	if (NowAlpha < 0.f)
	{
		NowAlpha = 0.f;
	}
	MonsterRender->SetAlpha(static_cast<int>(NowAlpha));

	float4 NowOffset = float4::LerpClamp(float4::Zero, MoveOffset, Ratio);
	MonsterRender->SetPosition(NowOffset);
}

void BattleState_MonsterDead::ExitState()
{
	MonsterRender = nullptr;
	Timer = 0.f;
}
