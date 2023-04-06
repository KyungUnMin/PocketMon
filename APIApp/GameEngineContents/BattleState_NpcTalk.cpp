#include "BattleState_NpcTalk.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"

const std::vector<std::string> BattleState_NpcTalk::Texts =
{
	"A suspicious person\ncame to the battle",
	"He is trying to\nget the Pokemon out",
	"Lets Go!"
};


BattleState_NpcTalk::BattleState_NpcTalk()
{

}

BattleState_NpcTalk::~BattleState_NpcTalk()
{

}

void BattleState_NpcTalk::EnterState()
{
	BattleState_TalkBase::EnterState();

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
