#include "BattleState_WildTalk.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "Battle_MonsterAppearEffect.h"
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

	//UI에 들어갈 텍스트 등록
	CreateUIText(Texts);
	
	//텍스트가 나올때마다 실행될 이벤트 등록
	SetTextEvent(1, std::bind(&BattleState_WildTalk::PlayerMonsterCreate, this));
}


void BattleState_WildTalk::PlayerMonsterCreate()
{
	GetAppearEffect()->Action();//이걸 TalkFSM에서 하는게 맞을까? 플레이어가 몬스터를 생성할때 하는게 맞지 않아?
	BattlePlayer::PlayerPtr->CreatePlayerMonster();
}

void BattleState_WildTalk::NextStateAtLastText()
{
	int a = 0;
}
