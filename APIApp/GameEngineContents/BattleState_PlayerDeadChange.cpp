#include "BattleState_PlayerDeadChange.h"

const std::vector<std::string_view> BattleState_PlayerDeadChange::Texts =
{
	"Take out Next PocketMon",
	"Let go",
};

BattleState_PlayerDeadChange::BattleState_PlayerDeadChange()
{

}

BattleState_PlayerDeadChange::~BattleState_PlayerDeadChange()
{

}

void BattleState_PlayerDeadChange::EnterState()
{
	BattleState_TalkBase::EnterState();

	CreateUIText(Texts);

	SetTextEvent(1, []
	{
		//BattleEnemy::EnemyPtr->CreateMonster();
	});

}

void BattleState_PlayerDeadChange::Update(float _DeltaTime)
{
	BattleState_TalkBase::Update(_DeltaTime);


}

void BattleState_PlayerDeadChange::ExitState()
{
	BattleState_TalkBase::ExitState();


}
