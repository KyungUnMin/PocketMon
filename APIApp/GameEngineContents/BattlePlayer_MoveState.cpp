#include "BattlePlayer_MoveState.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "BattlePlayer.h"
#include "ContentsEnum.h"
#include "BattlePlayerFSM.h"

BattlePlayer_MoveState::BattlePlayer_MoveState()
{

}

BattlePlayer_MoveState::~BattlePlayer_MoveState()
{

}

void BattlePlayer_MoveState::EnterState()
{
	float4 ScreenSize = GameEngineWindow::GetScreenSize();
	Duration = BattlePlayer::MoveDuration;

	const float Height = ScreenSize.y - 220.f;
	const float DestX = 240.f;

	StartPos = float4{ ScreenSize.x, Height };
	DestPos = float4{ DestX,  Height };

	CreatePlayerRender();
}

void BattlePlayer_MoveState::CreatePlayerRender()
{
	Player = BattlePlayer::PlayerPtr;
	GameEngineRender* RenderPtr = Player->GetPlayerRender();
	RenderPtr->CreateAnimation
	({
		.AnimationName = "Idle",
		.ImageName = "BattlePlayer.bmp",
		.Start = 0,
		.End = 0,
		.InterTime = FLT_MAX,
		.Loop = true
	});

	RenderPtr->ChangeAnimation("Idle");
}


void BattlePlayer_MoveState::Update(float _DeltaTime)
{
	Timer += _DeltaTime;
	if (Duration < Timer)
	{
		GetFSM()->ChangeState(BattlePlayer_StateType::Idle);
		return;
	}

	float Ratio = Timer / Duration;
	float4 NextPos = float4::LerpClamp(StartPos, DestPos, Ratio);
	Player->SetPos(NextPos);
}

