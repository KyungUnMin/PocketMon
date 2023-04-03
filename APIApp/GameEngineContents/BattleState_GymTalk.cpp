#include "BattleState_GymTalk.h"
#include "BattleEnemy.h"
#include "BattlePlayer.h"

const std::vector<std::string_view> BattleState_GymTalk::Texts =
{
	"He come up with a fight",
	"He is trying to\nget the Pokemon out",
	"Go @@@"
};

BattleState_GymTalk::BattleState_GymTalk()
{

}

BattleState_GymTalk::~BattleState_GymTalk()
{

}

void BattleState_GymTalk::EnterState()
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
