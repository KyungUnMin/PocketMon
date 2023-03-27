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
	MsgAssert("�ش� �Լ��� �������̵� ���־�� �մϴ�.\n�ڽ��� Update���� Update_CheckTime�� ȣ������ּ���");
}

void BattleState_SkillBase::ExitState()
{
	if (EnemyMonster->IsDeath() || PlayerMonster->IsDeath())
	{
		MsgAssert("Monster���� FSM������ ���θ� ������Ű�� �ȵ˴ϴ�");
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
		MsgAssert("�θ��� EnterState�� ȣ������־�� �մϴ�");
		return false;
	}

	return true;
}
