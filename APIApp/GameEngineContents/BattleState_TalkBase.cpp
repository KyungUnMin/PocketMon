#include "BattleState_TalkBase.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "BattleLevel.h"
#include "EnemyHPBackground.h"
#include "BackTextActor.h"
#include "BattleLevel.h"

BattleState_TalkBase::BattleState_TalkBase()
{

}

BattleState_TalkBase::~BattleState_TalkBase()
{

}

void BattleState_TalkBase::CreateUIText(const std::vector<std::string_view>& _Texts)
{
	TextEvents.resize(_Texts.size());
	for (size_t i = 0; i < TextEvents.size(); ++i)
	{
		TextEvents[i].first = _Texts[i];
	}

	TextInfoUI = BattleLevel::BattleLevelPtr->GetTextInfoUI();

	//첫번째 텍스트는 미리 출력(첫번째 텍스트에서는 이벤트 불가능)
	TextInfoUI->BattleSetText(TextEvents.front().first);
	++CurTextNum;
}

void BattleState_TalkBase::Update(float _DeltaTime)
{
	static const float ButtonOKTime = 0.5f;

	//키를 빠르게 연타하는 것을 방지
	Timer += _DeltaTime;
	if (Timer < ButtonOKTime)
		return;

	//키를 눌렀을때만
	if (false == GameEngineInput::IsDown(BattleLevel::BattleKeyName))
		return;

	Timer = 0.f;

	//더 전달할 텍스트가 없을땐 다음 State로 이동
	if (TextEvents.size() == CurTextNum)
	{
		NextStateAtLastText();
		return;
	}

	//UI에 텍스트 전달
	const std::string& Text = TextEvents[CurTextNum].first;
	TextInfoUI->BattleSetText(Text);

	//등록된 이벤트가 없다면 return
	std::function<void()>& EventFunc = TextEvents[CurTextNum++].second;
	if (nullptr == EventFunc)
		return;
	
	//이벤트 호출
	EventFunc();
	EventFunc = nullptr;
}



void BattleState_TalkBase::SetTextEvent(size_t _Index, std::function<void()> _Event)
{
	if (TextEvents.size() <= _Index)
	{
		MsgAssert("벡터의 인덱스를 넘겼습니다");
		return;
	}

	if (nullptr != TextEvents[_Index].second)
	{
		MsgAssert("이미 등록된 텍스트 이벤트입니다");
		return;
	}

	TextEvents[_Index].second = _Event;
}

