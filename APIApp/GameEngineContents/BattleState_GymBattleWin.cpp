#include "BattleState_GymBattleWin.h"
#include "BattleFSM.h"
#include "BattleEnemy.h"

const std::vector<std::string_view> BattleState_GymBattleWin::Texts =
{
	"Woong :\nCongratulation, This is yours",
	"I got a gray emblem!",
};

BattleState_GymBattleWin::BattleState_GymBattleWin()
{

}

BattleState_GymBattleWin::~BattleState_GymBattleWin()
{

}

void BattleState_GymBattleWin::EnterState()
{
	BattleState_TalkBase::EnterState();
	SetNextState(BattleStateType::BattleWin);

	CreateUIText(Texts);
	SetTextEvent(0, []
	{
		BattleEnemy::EnemyPtr->ComeBack();
	});


}
