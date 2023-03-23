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

BattleState_PlayerTurn::BattleState_PlayerTurn()
{

}

BattleState_PlayerTurn::~BattleState_PlayerTurn()
{

}

void BattleState_PlayerTurn::Start()
{
	BattleCommand = BattleLevel::BattleLevelPtr->CreateActor<BattleCommendActor>(UpdateOrder::Battle_Actors);
	BattleCommand->Off();

	SelectBoard = BattleLevel::BattleLevelPtr->CreateActor<Battle_Select>(UpdateOrder::Battle_Actors);
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

	SelectBoard->Off();
}

void BattleState_PlayerTurn::EnterState()
{
	const std::string_view PlayerTurnText = "What should I Do";

	BackTextActor* TextInfo = BattleLevel::BattleLevelPtr->GetTextInfoUI();
	TextInfo->BattleSetText(PlayerTurnText);

	SelectBoard->On();
}

void BattleState_PlayerTurn::BattleCmdOpen()
{
	BattleCommand->On();
	SelectBoard->Off();
}


