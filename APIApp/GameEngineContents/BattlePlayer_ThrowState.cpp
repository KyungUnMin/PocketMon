#include "BattlePlayer_ThrowState.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleLevel.h"
#include "BattlePlayer.h"
#include "BattleMonsterBall.h"
#include "BattlePlayerFSM.h"

BattlePlayer_ThrowState::BattlePlayer_ThrowState()
{

}

BattlePlayer_ThrowState::~BattlePlayer_ThrowState()
{

}

void BattlePlayer_ThrowState::EnterState()
{
	BattlePlayer* Player = BattlePlayer::PlayerPtr;
	PlayerRender = Player->GetTrainerRender();

	if (true == IsCreated)
		return;

	PlayerRender->CreateAnimation
	({
		.AnimationName = "Throw",
		.ImageName = "BattlePlayer.bmp",
		.Start = 1,
		.End = 4,
		.InterTime = 0.1f,
		.Loop = false
	});
	IsCreated = true;

	PlayerRender->ChangeAnimation("Throw");
}

void BattlePlayer_ThrowState::Update(float _DeltaTime)
{
	Timer += _DeltaTime;

	if (ThrowDuration < Timer)
	{
		PlayerRender->Off();
		GetFSM()->ChangeState(BattlePlayer_StateType::Idle);
		return;
	}

	PlayerRender->SetMove(float4::Left * MoveSpeed * _DeltaTime);
}

void BattlePlayer_ThrowState::ExitState()
{
	PlayerRender = nullptr;
}
