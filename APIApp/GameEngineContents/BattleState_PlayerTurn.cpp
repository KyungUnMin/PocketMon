#include "BattleState_PlayerTurn.h"
#include <string_view>
#include "BattleLevel.h"
#include "BackTextActor.h"
#include "Battle_Select.h"
#include "ContentsEnum.h"
#include "BagLevel.h"
#include "PlayerBag.h"
#include "PocketMonCore.h"
#include "BattleCommendActor.h"
#include "BattleFSM.h"

BattleState_PlayerTurn::BattleState_PlayerTurn()
{

}

BattleState_PlayerTurn::~BattleState_PlayerTurn()
{

}

void BattleState_PlayerTurn::EnterState()
{
	const std::string_view PlayerTurnText = "What should I Do";

	BackTextActor* TextInfo = BattleLevel::BattleLevelPtr->GetTextInfoUI();
	TextInfo->BattleSetText(PlayerTurnText);

	BattleCommand = BattleLevel::BattleLevelPtr->CreateActor<BattleCommendActor>(UpdateOrder::Battle_Actors);
	BindBattleCommand();
	BattleCommand->Off();

	SelectBoard = BattleLevel::BattleLevelPtr->CreateActor<Battle_Select>(UpdateOrder::Battle_Actors);
	BindSelectBoard();
}


void BattleState_PlayerTurn::BindSelectBoard()
{
	SelectBoard->ResizeCallBacks(4);

	//���� ������ ����
	SelectBoard->SetCallBack(0, std::bind(&BattleState_PlayerTurn::BattleCmdOpen, this));

	//���� ������ ����
	SelectBoard->SetCallBack(1, []
	{
		PocketMonCore::GetInst().ChangeLevel("BagLevel");
		PlayerBag::MainBag->BattleOn();
	});

	//���ϸ� ��ü ������ ��ȯ
	SelectBoard->SetCallBack(2, []
	{
		PocketMonCore::GetInst().ChangeLevel("PokemonLevel");
	});

	//�ʵ� ������ ����
	SelectBoard->SetCallBack(3, []
	{
		PocketMonCore::GetInst().ChangeLevel("FieldmapLevel");
	});
}


void BattleState_PlayerTurn::BindBattleCommand()
{
	const float EventTime = 3.f;

	std::function<void(GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*)> EventCallBack = nullptr;
	EventCallBack = [](GameEngineTimeEvent::TimeEvent&, GameEngineTimeEvent*)
	{
		BattleFSM* Fsm = BattleLevel::BattleLevelPtr->GetBattleFSM();
		Fsm->ChangeState(BattleStateType::EnemyTurn);
	};

	BattleCommand->SetCallBack(0, [=]
	{
		BackTextActor* TextInfo = BattleLevel::BattleLevelPtr->GetTextInfoUI();
		TextInfo->BattleSetText("Player Attack");
		TextInfo->On();

		SelectBoard->Off();
		BattleCommand->Off();

		BattleLevel::BattleLevelPtr->LevelEvent.AddEvent(EventTime, EventCallBack);
	});
}

void BattleState_PlayerTurn::BattleCmdOpen()
{
	BattleLevel::BattleLevelPtr->GetTextInfoUI()->Off();
	BattleCommand->On();
	SelectBoard->Off();
}


void BattleState_PlayerTurn::ExitState()
{
	SelectBoard->Death();
	BattleCommand->Death();
}





