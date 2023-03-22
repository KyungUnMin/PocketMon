#include "BattleState_TalkBase.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "BattleLevel.h"
#include "EnemyHPBackground.h"
#include "BackTextActor.h"
#include "Battle_MonsterAppearEffect.h"

BattleState_TalkBase::BattleState_TalkBase()
{

}

BattleState_TalkBase::~BattleState_TalkBase()
{

}

void BattleState_TalkBase::Start()
{
	AppearEffect = BattleLevel::BattleLevelPtr->CreateActor<Battle_MonsterAppearEffect>(UpdateOrder::Battle_Actors);
}

void BattleState_TalkBase::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsDown(BattleLevel::BattleKeyName))
	{
		//모든 텍스트를 출력했다면
		if (false == BackUI->WriteText())
			return;

		if (nullptr == TextEvents[CurTextNum++])
			return;

		TextEvents[CurTextNum - 1]();
		TextEvents[CurTextNum - 1] = nullptr;

		//MsgAssert("이제 여기서 배틀의 FSM을 변경할 예정");
		//GetFSM()->ChangeState(Battle)
	}
}

void BattleState_TalkBase::CreateUIText(const std::vector<std::string_view>& _Texts)
{
	BackUI = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>();
	BackUI->PushTexts(_Texts);

	TextEvents.resize(_Texts.size(), nullptr);
}

void BattleState_TalkBase::SetTextEvent(size_t _Index, std::function<void()> _Event)
{
	if (TextEvents.size() <= _Index)
	{
		MsgAssert("벡터의 인덱스를 넘겼습니다");
		return;
	}

	if (nullptr != TextEvents[_Index])
	{
		MsgAssert("이미 등록된 텍스트 이벤트입니다");
		return;
	}

	TextEvents[_Index] = _Event;
}

