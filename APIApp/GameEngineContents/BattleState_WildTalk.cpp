#include "BattleState_WildTalk.h"

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
	CreateUIText(Texts);
	SetTextEvent(1, std::bind(&BattleState_WildTalk::Test, this));
}

void BattleState_WildTalk::Test()
{
	//MsgAssert("Hello");
}
