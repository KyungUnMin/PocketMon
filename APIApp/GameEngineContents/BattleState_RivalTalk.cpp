#include "BattleState_RivalTalk.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"

BattleState_RivalTalk::BattleState_RivalTalk()
{

}

BattleState_RivalTalk::~BattleState_RivalTalk()
{
	
}

void BattleState_RivalTalk::EnterState()
{
	BattleState_TalkBase::EnterState();

	std::vector<std::string> Texts = InitNPCTexts("GREEN");
	CreateUIText(Texts);

	SetTextEvent(1, []
	{
		BattleEnemy::EnemyPtr->CreateMonster();
	});

	SetTextEvent(2, []
	{
		BattlePlayer::PlayerPtr->ThrowBallToCreate();
	});
}
