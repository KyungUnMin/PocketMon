#include "BattleState_WildTalk.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "BattlePlayer.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "Battle_Select.h"
#include "ContentsEnum.h"
#include "BattleFSM.h"
#include "BattlePlayerFSM.h"

const std::vector<std::string_view> BattleState_WildTalk::Texts =
{
	"Oops That Wild PocketMon",
	"Lets Go!"
};

BattleState_WildTalk::BattleState_WildTalk()
{

}

BattleState_WildTalk::~BattleState_WildTalk()
{

}

void BattleState_WildTalk::EnterState()
{
	BattleState_TalkBase::EnterState();

	//UI에 들어갈 텍스트 등록
	CreateUIText(Texts);
	
	//텍스트가 나올때마다 실행될 이벤트 등록
	SetTextEvent(1, []
	{
		BattlePlayer::PlayerPtr->ThrowBallToCreate();
	});
}

