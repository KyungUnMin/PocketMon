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
	"Wild appeared!",
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

	//UI�� �� �ؽ�Ʈ ���
	CreateUIText(Texts);
	
	//�ؽ�Ʈ�� ���ö����� ����� �̺�Ʈ ���
	SetTextEvent(1, []
	{
		BattlePlayer::PlayerPtr->ThrowBallToCreate();
	});
}

