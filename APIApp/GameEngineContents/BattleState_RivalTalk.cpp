#include "BattleState_RivalTalk.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"

std::vector<std::string> BattleState_RivalTalk::Texts =
{
	"GREEN\nwould like to battle!",
	"GREEN sent\nout ",
	"Go! "
};

BattleState_RivalTalk::BattleState_RivalTalk()
{

}

BattleState_RivalTalk::~BattleState_RivalTalk()
{
	//�� �ؽ�Ʈ�� �θ𿡼� ��ӽ��Ѽ� ó������
}

void BattleState_RivalTalk::EnterState()
{
	BattleState_TalkBase::EnterState();

	Texts[1] += BattleEnemy::EnemyPtr->GetFrontMonster().ForUI_GetMonsterName();

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
