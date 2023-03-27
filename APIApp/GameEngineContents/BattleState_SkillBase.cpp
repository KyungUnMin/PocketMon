#include "BattleState_SkillBase.h"
#include "BattleLevel.h"
#include "BattleFSM.h"
#include "BattleEnemy.h"
#include "BattlePlayerMonsterFSM.h"
#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"
#include "BattleMonsterEnemy.h"

BattleState_SkillBase::BattleState_SkillBase()
{

}

BattleState_SkillBase::~BattleState_SkillBase()
{

}

void BattleState_SkillBase::EnterState()
{
	EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();
	PlayerMonster = BattlePlayer::PlayerPtr->GetMonster();
}

void BattleState_SkillBase::Update(float _DeltaTime)
{
	MsgAssert("해당 함수는 오버라이딩 해주어야 합니다.\n자식의 Update에서 Update_CheckTime를 호출시켜주세요");
}

void BattleState_SkillBase::ExitState()
{
	if (EnemyMonster->IsDeath() || PlayerMonster->IsDeath())
	{
		MsgAssert("Monster들의 FSM에서는 서로를 삭제시키면 안됩니다");
		return;
	}

	LiveTime = 0.f;
	EnemyMonster = nullptr;
	PlayerMonster = nullptr;
}

bool BattleState_SkillBase::CheckValid()
{
	if (nullptr == EnemyMonster || nullptr == PlayerMonster)
	{
		MsgAssert("부모의 EnterState를 호출시켜주어야 합니다");
		return false;
	}

	return true;
}
