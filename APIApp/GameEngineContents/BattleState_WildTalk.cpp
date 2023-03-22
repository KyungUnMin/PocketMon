#include "BattleState_WildTalk.h"

const std::vector<std::string_view> BattleState_WildTalk::Texts =
{
	"�� �߻��� __�� ��Ÿ����!",
	"����! ___!",
	"___�� ������ �ұ�?"
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
