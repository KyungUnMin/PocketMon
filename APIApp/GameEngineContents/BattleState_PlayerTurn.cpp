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
#include "BattlePlayer.h"
#include "BattleMonsterPlayer.h"
#include "PokeSkillBase.h"
#include "BattlePlayerMonsterFSM.h"
#include "PokeBattleSystem.h"
#include "BattleEnemy.h"

BattleState_PlayerTurn::BattleState_PlayerTurn()
{

}

BattleState_PlayerTurn::~BattleState_PlayerTurn()
{

}

void BattleState_PlayerTurn::EnterState()
{
	const std::string_view PlayerTurnText = "What should I Do";

	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText(PlayerTurnText);

	BattleCommand = BattleLevel::BattleLevelPtr->CreateActor<BattleCommendActor>(UpdateOrder::Battle_Actors);
	BattleCommand->Off();
	for (int i = 0; i < 4; ++i)
	{
		PokeSkill SkillType = BattlePlayer::PlayerPtr->GetSlotSkillType(static_cast<size_t>(i));
		if (PokeSkill::Unknown == SkillType)
			continue;

		BindBattleCommand(i);
	}

	SelectBoard = BattleLevel::BattleLevelPtr->CreateActor<Battle_Select>(UpdateOrder::Battle_Actors);
	BindSelectBoard();
}


void BattleState_PlayerTurn::BindSelectBoard()
{
	SelectBoard->ResizeCallBacks(4);

	//가방 레벨과 연결
	SelectBoard->SetCallBack(0, std::bind(&BattleState_PlayerTurn::BattleCmdOpen, this));

	//가방 레벨과 연결
	SelectBoard->SetCallBack(1, []
	{
		PocketMonCore::GetInst().ChangeLevel("BagLevel");
		PlayerBag::MainBag->BattleOn();
	});

	//포켓몬 교체 레벨로 전환
	SelectBoard->SetCallBack(2, []
	{
		PocketMonCore::GetInst().ChangeLevel("PokemonLevel");
	});

	//필드 레벨과 연결
	SelectBoard->SetCallBack(3, []
	{
		PocketMonCore::GetInst().ChangeLevel("FieldmapLevel");
	});
}


void BattleState_PlayerTurn::BindBattleCommand(int _SlotIndex)
{
	//슬롯의 스킬 발동
	BattleCommand->SetCallBack(_SlotIndex, [=]
	{
		PokeDataBase* PlayerMonsterDB = BattlePlayer::PlayerPtr->GetMonsterDB();
		PokeSkill SkillType = PlayerMonsterDB->GetMonsterSkillList(_SlotIndex + 1)->GetSkill();
		if (PokeSkill::Unknown == SkillType)
			return;

		TextInfo->Death();
		TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
		TextInfo->BattleSetText("Player Attacking...");

		SelectBoard->Off();
		BattleCommand->Off();

		PokeDataBase* EnemyMonsterDB = BattleEnemy::EnemyPtr->GetMonsterDB();
		PokeBattleSystem::Battle(PlayerMonsterDB, _SlotIndex + 1, EnemyMonsterDB);

		//TODO
		BattlePlayerMonsterFSM* MonsterFSM = BattlePlayer::PlayerPtr->GetMonster()->GetFSM();

		//일단 임시, 나중에 PlayerMonster에서 함수를 만들어서 등록된 슬롯과 연동시킬 예정이다
		//MonsterFSM->ChangeState(ConvertSkill(SkillType));
		MonsterFSM->ChangeState(BattlePlayerMonster_StateType::Skill_Tackle);

	});


}

void BattleState_PlayerTurn::BattleCmdOpen()
{
	TextInfo->Off();
	BattleCommand->On();
	SelectBoard->Off();
}


void BattleState_PlayerTurn::ExitState()
{
	SelectBoard->Death();
	BattleCommand->Death();
	TextInfo->Death();

	SelectBoard = nullptr;
	BattleCommand = nullptr;
	TextInfo = nullptr;
}





