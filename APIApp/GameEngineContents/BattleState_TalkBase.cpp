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

	//������ ���� ���ð�
	Timer = -1.6f;
}

void BattleState_TalkBase::CreateUIText(const std::vector<std::string_view>& _Texts)
{
	TextEvents.resize(_Texts.size());
	for (size_t i = 0; i < TextEvents.size(); ++i)
	{
		TextEvents[i].first = _Texts[i];
	}

	BackUI = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);

	//ù��° �ؽ�Ʈ�� �̸� ���(ù��° �ؽ�Ʈ������ �̺�Ʈ �Ұ���)
	BackUI->BattleSetText(TextEvents.front().first);
	++CurTextNum;
}

void BattleState_TalkBase::Update(float _DeltaTime)
{
	static const float ButtonOKTime = 0.5f;

	//Ű�� ������ ��Ÿ�ϴ� ���� ����
	Timer += _DeltaTime;
	if (Timer < ButtonOKTime)
		return;

	//Ű�� ����������
	if (false == GameEngineInput::IsDown(BattleLevel::BattleKeyName))
		return;

	Timer = 0.f;

	//�� ������ �ؽ�Ʈ�� ������ ���� State�� �̵�
	if (TextEvents.size() == CurTextNum)
	{
		NextStateAtLastText();
		return;
	}

	//UI�� �ؽ�Ʈ ����
	BackUI->BattleSetText(TextEvents[CurTextNum].first);

	//��ϵ� �̺�Ʈ�� ���ٸ� return
	std::function<void()>& EventFunc = TextEvents[CurTextNum++].second;
	if (nullptr == EventFunc)
		return;
	
	//�̺�Ʈ ȣ��
	EventFunc();
	EventFunc = nullptr;
}



void BattleState_TalkBase::SetTextEvent(size_t _Index, std::function<void()> _Event)
{
	if (TextEvents.size() <= _Index)
	{
		MsgAssert("������ �ε����� �Ѱ���ϴ�");
		return;
	}

	if (nullptr != TextEvents[_Index].second)
	{
		MsgAssert("�̹� ��ϵ� �ؽ�Ʈ �̺�Ʈ�Դϴ�");
		return;
	}

	TextEvents[_Index].second = _Event;
}

