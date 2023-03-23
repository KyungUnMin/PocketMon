#include "BattlePlayer.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "BattleLevel.h"
#include "PokeDataBase.h"
#include "BattleMonsterPlayer.h"

BattlePlayer* BattlePlayer::PlayerPtr = nullptr;
const std::string_view BattlePlayer::IdleAniName = "Idle";
const std::string_view BattlePlayer::ThrowAniName = "Throw";

BattlePlayer::BattlePlayer()
{
	PlayerPtr = this;
}

BattlePlayer::~BattlePlayer()
{
	if (this == PlayerPtr)
	{
		PlayerPtr = nullptr;
	}
}


void BattlePlayer::Init(BattleFieldType _FieldType)
{
	CreateGround(_FieldType);
	CreatePlayerRender();
}



void BattlePlayer::CreateGround(BattleFieldType _FieldType)
{
	const float4 ScreenSize = GameEngineWindow::GetScreenSize();
	const float Height = (ScreenSize.y - 230.f);
	std::string GroundPath = "";

	switch (_FieldType)
	{
	case BattleFieldType::Indoor:
		GroundPath = "BattleIndoorPlayerGround.bmp";
		break;
	case BattleFieldType::Forest0:
	case BattleFieldType::Forest1:
		GroundPath = "BattleForestPlayerGround.bmp";
		break;
	case BattleFieldType::Gym:
		GroundPath = "BattleGymPlayerGround.bmp";
		break;
	}

	GameEngineRender* GroundRender = CreateRender(GroundPath, BattleRenderOrder::Ground);
	GroundRender->SetScaleToImage();

	//State에 따른 움직임 위치 설정
	const float4& RenderScale = GroundRender->GetScale();
	MoveStartPos = float4{ ScreenSize.x + RenderScale.hx(), Height };
	MoveEndPos = float4{ RenderScale.hx(), Height };
}

void BattlePlayer::CreatePlayerRender()
{
	const float4 Offset = {0.f, -65.f};

	PlayerRenderPtr = CreateRender(BattleRenderOrder::Player0);
	PlayerRenderPtr->CreateAnimation
	({
		.AnimationName = IdleAniName,
		.ImageName = "BattlePlayer.bmp",
		.Start = 0,
		.End = 0,
		.InterTime = FLT_MAX,
		.Loop = true
	});

	PlayerRenderPtr->CreateAnimation
	({
		.AnimationName = ThrowAniName,
		.ImageName = "BattlePlayer.bmp",
		.Start = 1,
		.End = 4,
		.InterTime = 0.1f,
		.Loop = false
	});

	PlayerRenderPtr->ChangeAnimation(IdleAniName);
	PlayerRenderPtr->SetScale(PlayerRenderScale);
	PlayerRenderPtr->SetPosition(Offset);
}








void BattlePlayer::Update(float _DeltaTime)
{
	switch (CurState)
	{
	case BattlePlayer::State::Move:
		Update_Move();
		break;
	case BattlePlayer::State::Idle:
		break;
	case BattlePlayer::State::Throw:
		Update_Throw();
		break;
	}

}


void BattlePlayer::Update_Move()
{
	if (true == Update_LerpMoveActor(MoveStartPos, MoveEndPos, BattleTrainerBase::MoveDuration))
		return;

	CurState = State::Idle;
}

void BattlePlayer::CreateMontser()
{
	BattleTrainerBase::CreateMontser();

	Monster = GetLevel()->CreateActor<BattleMonsterPlayer>(UpdateOrder::Battle_Actors);
	Monster->Init(PokeNumber::Bulbasaur);
	Monster->SetPos(GetPos());

	CurState = State::Throw;
	PlayerRenderPtr->ChangeAnimation(ThrowAniName);
}


void BattlePlayer::Update_Throw()
{
	if (true == Update_LerpMoveComponent(PlayerRenderPtr, float4::Zero, float4::Left * ThrowMoveLen, ThrowDuration))
		return;

	PlayerRenderPtr->Off();
	CurState = State::Idle;
}
