#include "BattleState_RivalTalk.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"
#include "PokeDataBase.h"

const std::vector<std::string_view> BattleState_RivalTalk::Texts =
{
	"Green walks into battle",
	"He is trying to\nget the Pokemon out",
	"Lets Go!"
};

BattleState_RivalTalk::BattleState_RivalTalk()
{

}

BattleState_RivalTalk::~BattleState_RivalTalk()
{

}

void BattleState_RivalTalk::EnterState()
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
