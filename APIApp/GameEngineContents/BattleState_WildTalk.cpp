#include "BattleState_WildTalk.h"
#include "Battle_MonsterAppearEffect.h"
#include "BattlePlayer.h"

const std::vector<std::string_view> BattleState_WildTalk::Texts =
{
	"앗 야생의 __이 나타났다!",
	"가랏! ___!",
	"___은 무엇을 할까?"
};

BattleState_WildTalk::BattleState_WildTalk()
{

}

BattleState_WildTalk::~BattleState_WildTalk()
{

}

#include <GameEngineBase/GameEngineDebug.h>

void BattleState_WildTalk::Start()
{
	BattleState_TalkBase::Start();

	CreateUIText(Texts);
	SetTextEvent(1, std::bind(&BattleState_WildTalk::PlayerMonsterCreate, this));
}

void BattleState_WildTalk::PlayerMonsterCreate()
{
	GetAppearEffect()->Action();
	BattlePlayer::PlayerPtr->CreatePlayerMonster();
}
