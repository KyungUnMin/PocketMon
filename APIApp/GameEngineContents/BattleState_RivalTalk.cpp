#include "BattleState_RivalTalk.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"
#include "PokeDataBase.h"

const std::vector<std::string_view> BattleState_RivalTalk::Texts =
{
	"Rival vs Player",
	"Rival will take out his monster",
	"Go @@@"
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
		BattleEnemy::EnemyPtr->CreateMonster(PokeNumber::Bulbasaur);
	});

	SetTextEvent(2, []
	{
		BattlePlayer::PlayerPtr->ThrowBallToCreate();
	});
}
