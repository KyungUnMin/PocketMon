#include "BattleState_WildTalk.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "BattlePlayer.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "Battle_Select.h"
#include "ContentsEnum.h"

const std::vector<std::string_view> BattleState_WildTalk::Texts =
{
	"Oops That Wild PocketMon",
	"Go @@@",
	"What should I Do"
};

BattleState_WildTalk::BattleState_WildTalk()
{

}

BattleState_WildTalk::~BattleState_WildTalk()
{

}

void BattleState_WildTalk::Start()
{
	BattleState_TalkBase::Start();

	//UI�� �� �ؽ�Ʈ ���
	CreateUIText(Texts);
	
	//�ؽ�Ʈ�� ���ö����� ����� �̺�Ʈ ���
	SetTextEvent(1, std::bind(&BattleState_WildTalk::PlayerMonsterCreate, this));
}


void BattleState_WildTalk::PlayerMonsterCreate()
{
	BattlePlayer::PlayerPtr->CreateMontser();
}

void BattleState_WildTalk::NextStateAtLastText()
{
	int a = 0;
}
