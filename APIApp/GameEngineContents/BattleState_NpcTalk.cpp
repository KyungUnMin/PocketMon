#include "BattleState_NpcTalk.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"


BattleState_NpcTalk::BattleState_NpcTalk()
{

}

BattleState_NpcTalk::~BattleState_NpcTalk()
{

}

void BattleState_NpcTalk::EnterState()
{
	BattleState_TalkBase::EnterState();

	std::vector<std::string> Texts = InitNPCTexts("stranger");
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
