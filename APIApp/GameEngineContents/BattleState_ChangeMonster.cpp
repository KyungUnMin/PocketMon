#include "BattleState_ChangeMonster.h"
#include "BattlePlayer.h"
#include "BattleFSM.h"
#include "BackTextActor.h"
#include "BattleLevel.h"
#include "Player.h"

BattleState_ChangeMonster::BattleState_ChangeMonster()
{

}

BattleState_ChangeMonster::~BattleState_ChangeMonster()
{

}

void BattleState_ChangeMonster::EnterState()
{
	BattlePlayer::PlayerPtr->ThrowBallToCreate();
	TextInfo = BattleLevel::BattleLevelPtr->CreateActor<BackTextActor>(UpdateOrder::Battle_Actors);

	PokeDataBase* NextMon = Player::MainPlayer->GetPlayerPokemon()->NextPokemon();
	TextInfo->BattleSetText("Go! " + NextMon->ForUI_GetMonsterName());
}

void BattleState_ChangeMonster::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Timer < Duration)
		return;

	GetFSM()->ChangeState(BattleStateType::PlayerTurn);
}

void BattleState_ChangeMonster::ExitState()
{
	Timer = 0.f;
	TextInfo->Death();
}
