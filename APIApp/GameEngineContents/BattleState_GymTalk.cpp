#include "BattleState_GymTalk.h"
#include "BattleEnemy.h"
#include "BattlePlayer.h"

BattleState_GymTalk::BattleState_GymTalk()
{

}

BattleState_GymTalk::~BattleState_GymTalk()
{

}

void BattleState_GymTalk::EnterState()
{
	BattleState_TalkBase::EnterState();

	
	std::vector<std::string> Texts = InitNPCTexts("WOONG");
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
