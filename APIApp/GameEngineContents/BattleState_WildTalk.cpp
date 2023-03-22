#include "BattleState_WildTalk.h"
#include "Battle_MonsterAppearEffect.h"
#include "BattlePlayer.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "Battle_Select.h"

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

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineInput.h>

void BattleState_WildTalk::Start()
{
	BattleState_TalkBase::Start();

	//CreateUIText(Texts);

	BackUI = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>();
	//BackUI->PushTexts(_Texts);


	//SetTextEvent(1, std::bind(&BattleState_WildTalk::PlayerMonsterCreate, this));
}

void BattleState_WildTalk::Update(float _DeltaTime)
{
	static bool IsCreated = false;
	if (true == IsCreated)
		return;

	if (true == GameEngineInput::IsDown(BattleLevel::BattleKeyName))
	{
		//모든 텍스트를 출력했다면
		/*if (false == BackUI->WriteText())
			return;*/

		BackUI->BattleSetText(Texts[StrIndex++]);
		if (StrIndex == Texts.size() && false == IsCreated)
		{
			BattleLevel::BattleLevelPtr->CreateActor<Battle_Select>();
			IsCreated = true;
		}

		/*if (nullptr == TextEvents[CurTextNum++])
			return;*/

		/*TextEvents[CurTextNum - 1]();
		TextEvents[CurTextNum - 1] = nullptr;*/

		//MsgAssert("이제 여기서 배틀의 FSM을 변경할 예정");
		//GetFSM()->ChangeState(Battle)
	}
}

void BattleState_WildTalk::PlayerMonsterCreate()
{
	GetAppearEffect()->Action();
	BattlePlayer::PlayerPtr->CreatePlayerMonster();
}
