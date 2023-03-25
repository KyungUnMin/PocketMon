#include "BattlePlayer_ThrowState.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleLevel.h"
#include "BattlePlayer.h"
#include "Battle_PlayerThrowBall.h"
#include "BattlePlayerFSM.h"

BattlePlayer_ThrowState::BattlePlayer_ThrowState()
{

}

BattlePlayer_ThrowState::~BattlePlayer_ThrowState()
{

}

void BattlePlayer_ThrowState::EnterState()
{
	PlayerRender = BattlePlayer::PlayerPtr->GetPlayerRender();
	PlayerRender->CreateAnimation
	({
		.AnimationName = "Throw",
		.ImageName = "BattlePlayer.bmp",
		.Start = 1,
		.End = 4,
		.InterTime = 0.1f,
		.Loop = false
	});

	PlayerRender->ChangeAnimation("Throw");

	Battle_PlayerThrowBall* Ball = BattleLevel::BattleLevelPtr->CreateActor<Battle_PlayerThrowBall>(UpdateOrder::Battle_Actors);
	Ball->Init(BattlePlayer::PlayerPtr->GetPos(), ThrowDuration);
}

void BattlePlayer_ThrowState::Update(float _DeltaTime)
{
	Timer += _DeltaTime;

	if (ThrowDuration < Timer)
	{
		GetFSM()->ChangeState(BattlePlayer_StateType::Idle);
		return;
	}

	PlayerRender->SetMove(float4::Left * MoveSpeed * _DeltaTime);
}

void BattlePlayer_ThrowState::ExitState()
{
	BattlePlayer::PlayerPtr->CreateMontser();
}
