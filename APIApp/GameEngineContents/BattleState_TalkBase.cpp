#include "BattleState_TalkBase.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineString.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "BattleLevel.h"
#include "EnemyHPBackground.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "BattleFSM.h"
#include "BattlePlayer.h"
#include "BattlePlayerFSM.h"

#include "Player.h"
#include "BattleEnemy.h"

BattleState_TalkBase::BattleState_TalkBase()
{

}

BattleState_TalkBase::~BattleState_TalkBase()
{

}

void BattleState_TalkBase::EnterState()
{
	NextState = static_cast<int>(BattleStateType::PlayerTurn);
	TextInfoUI = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
}



void BattleState_TalkBase::CreateUIText(const std::vector<std::string>& _Texts)
{
	TextEvents.resize(_Texts.size());
	for (size_t i = 0; i < TextEvents.size(); ++i)
	{
		TextEvents[i].first = _Texts[i];
	}

	//ù��° �ؽ�Ʈ�� �̸� ���(ù��° �ؽ�Ʈ������ �̺�Ʈ �Ұ���)
	TextInfoUI->BattleSetText(TextEvents.front().first);
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

	//�� ������ �ؽ�Ʈ�� ������ ���� State�� �̵�
	if (TextEvents.size() <= CurTextNum)
	{
		GetFSM()->ChangeState(NextState);
		return;
	}

	BattlePlayer_StateType PlayerState = BattlePlayer::PlayerPtr->GetNowState();
	if (BattlePlayer_StateType::Move == PlayerState)
		return;

	Timer = 0.f;

	//UI�� �ؽ�Ʈ ����
	const std::string& Text = TextEvents[CurTextNum].first;
	TextInfoUI->BattleSetText(Text);

	//��ϵ� �̺�Ʈ�� ���ٸ� return
	std::function<void()>& EventFunc = TextEvents[CurTextNum++].second;
	if (nullptr == EventFunc)
		return;
	
	//�̺�Ʈ ȣ��
	EventFunc();
	EventFunc = nullptr;
}

void BattleState_TalkBase::ExitState()
{
	TextInfoUI->Death();
	TextInfoUI = nullptr;

	CurTextNum = 0;
	Timer = -1.6f;
	TextEvents.clear();
	NextState = -1;
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

std::vector<std::string> BattleState_TalkBase::InitNPCTexts(const std::string_view& _NpcName)
{
	const PokeDataBase& EnemyMonster = BattleEnemy::EnemyPtr->GetFrontMonster();
	TrainerPokemon* PlayerMonsters = Player::MainPlayer->GetPlayerPokemon();
	PokeDataBase* PlayerFirstMon = PlayerMonsters->NextPokemon();

	std::vector<std::string> ReturnText(3, "");
	std::string NpcName = GameEngineString::ToUpper(_NpcName);

	ReturnText[0] = NpcName + "\nwould like to battle!";
	ReturnText[1] = NpcName + " sent\nout " + EnemyMonster.ForUI_GetMonsterName();
	ReturnText[2] = "Go! " + PlayerFirstMon->ForUI_GetMonsterName();

	return ReturnText;
}

