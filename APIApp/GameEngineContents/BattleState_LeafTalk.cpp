#include "BattleState_LeafTalk.h"
#include "BattleEnemy.h"
#include "BattlePlayer.h"

const std::vector<std::string> BattleState_LeafTalk::Texts =
{
	"Leaf\nI want to see your Pokemon",
	"She is trying to\nget the Pokemon out",
	"Lets Go!"
};

BattleState_LeafTalk::BattleState_LeafTalk()
{

}

BattleState_LeafTalk::~BattleState_LeafTalk()
{

}

void BattleState_LeafTalk::EnterState()
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
