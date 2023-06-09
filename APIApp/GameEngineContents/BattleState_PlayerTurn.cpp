#include "BattleState_PlayerTurn.h"
#include <string_view>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineResources.h>
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
#include "BattleMonsterEnemy.h"
#include "BattleDebug.h"
#include "BattleDefine.h"

BattleScript BattleState_PlayerTurn::BattleResultType = BattleScript::Nothing;
PokeSkill BattleState_PlayerTurn::UseSkill = PokeSkill::Unknown;

BattleState_PlayerTurn::BattleState_PlayerTurn()
{

}

BattleState_PlayerTurn::~BattleState_PlayerTurn()
{

}

void BattleState_PlayerTurn::EnterState()
{
	std::string TextValue = "What will\n" + BattlePlayer::PlayerPtr->GetMonster()->GetName() + " do?";

	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText(TextValue);

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

	CreateHpUI();
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
	SelectBoard->SetCallBack(3, std::bind(&BattleState_PlayerTurn::SelectRunAway, this));
}

void BattleState_PlayerTurn::SelectRunAway()
{
	if (true == WasRun)
		return;

	if (false == BattleLevel::BattleLevelPtr->IsWildBattle())
		return;

	if (nullptr != TextInfo)
	{
		TextInfo->Death();
	}

	WasRun = true;
	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
	TextInfo->BattleSetText("Succeed\nin escaping");
	GameEngineResources::GetInst().SoundPlay(BattleDefine::SfxName_Runaway);
	BattleLevel::BattleLevelPtr->ChangeFieldLevel(true, true, 3.f);
}



void BattleState_PlayerTurn::BindBattleCommand(int _SlotIndex)
{
	BattleState_PlayerTurn* ThisPtr = this;

	//슬롯의 스킬 발동
	BattleCommand->SetCallBack(_SlotIndex, [=]
	{
		PokeDataBase* PlayerMonsterDB = BattlePlayer::PlayerPtr->GetMonsterDB();
		PokeSkillBase& SkillDB = PlayerMonsterDB->GetMonsterSkillList(_SlotIndex + 1);
		UseSkill = SkillDB.GetSkill();
		if (PokeSkill::Unknown == UseSkill)
			return;

		TextInfo->Death();
		TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);
		TextInfo->BattleSetText(SkillDB.ForUI_GetSkillName( ) + "!!!");

		SelectBoard->Off();
		BattleCommand->Off();

		BattleMonsterEnemy* EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();
		PokeDataBase* EnemyMonsterDB = EnemyMonster->GetDB();

		//데미지 처리는 이 State가 끝날때 하기 위해 콜백 등록
		ThisPtr->SetCallBack([=]
		{
			BattleResultType = PokeBattleSystem::Battle(*PlayerMonsterDB, _SlotIndex + 1, *EnemyMonsterDB);
			int Damage = PokeBattleSystem::GetDamage();
			EnemyMonster->DamageOnIU(Damage);
		});

		//TODO
		BattlePlayerMonsterFSM* MonsterFSM = BattlePlayer::PlayerPtr->GetMonster()->GetFSM();

		
		//실제 게임용입니다. 
		MonsterFSM->ChangeState(ConvertSkill(UseSkill));
		
		//스킬 확인용입니다
		//MonsterFSM->ChangeState(BattlePlayerMonster_StateType::Skill_Scratch);
	});


}

void BattleState_PlayerTurn::BattleCmdOpen()
{
	TextInfo->Off();
	BattleCommand->On();
	SelectBoard->Off();
}


void BattleState_PlayerTurn::CreateHpUI()
{
	BattleMonsterPlayer* PlayerMonster = BattlePlayer::PlayerPtr->GetMonster();
	if (nullptr == PlayerMonster->GetHpUI())
	{
		PlayerMonster->CreateHpUI();
	}

	BattleMonsterEnemy* EnemyMonster = BattleEnemy::EnemyPtr->GetMonster();
	if (nullptr == EnemyMonster->GetHpUI())
	{
		EnemyMonster->CreateHpUI();
	}

}



void BattleState_PlayerTurn::Update(float _DeltaTime)
{
	if (false == BattleLevel::BattleLevelPtr->IsWildBattle())
		return;

	/*if (false == GameEngineInput::IsDown("FreeCamera"))
		return;

	BattleLevel::BattleLevelPtr->CreateActor<BattleDebug>(UpdateOrder::Battle_Actors);*/
}



void BattleState_PlayerTurn::ExitState()
{
	SelectBoard->Death();
	BattleCommand->Death();
	TextInfo->Death();

	SelectBoard = nullptr;
	BattleCommand = nullptr;
	TextInfo = nullptr;

	if (nullptr != DamageCalcFunc)
	{
		DamageCalcFunc();
		DamageCalcFunc = nullptr;
	}
}





