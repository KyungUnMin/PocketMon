#include "BattleState_LeafTalk.h"
#include "BattleEnemy.h"
#include "BattlePlayer.h"


BattleState_LeafTalk::BattleState_LeafTalk()
{

}

BattleState_LeafTalk::~BattleState_LeafTalk()
{

}

void BattleState_LeafTalk::EnterState()
{
	BattleState_TalkBase::EnterState();

	std::vector<std::string> Texts = InitNPCTexts("LEAF");
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
