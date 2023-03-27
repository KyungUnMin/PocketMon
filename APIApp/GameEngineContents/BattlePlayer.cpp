#include "BattlePlayer.h"
#include <GameEngineBase/GameEngineTimeEvent.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "BattleLevel.h"
#include "PokeDataBase.h"
#include "BattleMonsterPlayer.h"
#include "Battle_PlayerBallParticle.h"
#include "BattlePlayerFSM.h"
#include "BattleMonsterBall.h"

BattlePlayer* BattlePlayer::PlayerPtr = nullptr;


BattlePlayer::BattlePlayer()
{
	PlayerPtr = this;
	FsmPtr = new BattlePlayerFSM;
}

BattlePlayer::~BattlePlayer()
{
	if (this == PlayerPtr)
	{
		PlayerPtr = nullptr;
	}

	if (nullptr != FsmPtr)
	{
		delete FsmPtr;
		FsmPtr = nullptr;
	}
}


void BattlePlayer::Init(BattleFieldType _FieldType, BattleNpcType _NpcType)
{
	const float4 RenderScale = float4{ 256.f, 196.f };
	const float4 RenderOffset = float4{ 0.f, -65.f };
	PlayerRenderPtr = CreateRender(BattleRenderOrder::Player0);
	PlayerRenderPtr->SetScale(RenderScale);
	PlayerRenderPtr->SetPosition(RenderOffset);

	FsmPtr->Init(_FieldType, _NpcType);
	CreateGround(_FieldType);
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
	case BattleFieldType::Forest:
		GroundPath = "BattleForestPlayerGround.bmp";
		break;
	case BattleFieldType::Gym:
		GroundPath = "BattleGymPlayerGround.bmp";
		break;
	}

	GameEngineRender* GroundRender = CreateRender(GroundPath, BattleRenderOrder::Ground);
	GroundRender->SetScaleToImage();

}




void BattlePlayer::Update(float _DeltaTime)
{
	FsmPtr->Update(_DeltaTime);
}






BattlePlayer_StateType BattlePlayer::GetNowState()
{
	return FsmPtr->GetNowState<BattlePlayer_StateType>();
}



PokeDataBase* BattlePlayer::GetMonsterDB()
{
	return Monster->GetDB();
}

PokeSkill BattlePlayer::GetSlotSkillType(size_t _Index)
{
	if (3 < _Index)
	{
		MsgAssert("스킬 슬롯의 최대 크기는 4 입니다.");
	}

	PokeDataBase* MonsterDB = Monster->GetDB();
	PokeSkillBase* SkillBase = MonsterDB->GetMonsterSkillList(static_cast<int>(_Index + 1));
	return SkillBase->GetSkill();
}





void BattlePlayer::ThrowBallToCreate()
{
	const float OffsetY = 200.f;

	FsmPtr->ChangeState(BattlePlayer_StateType::Throw);
	BattleMonsterBall* Ball = BattleLevel::BattleLevelPtr->CreateActor<BattleMonsterBall>(UpdateOrder::Battle_Actors);
	Ball->Init(BattleBallType::Create_MonsterBall);
	Ball->SetPos(GetPos() + float4::Up * OffsetY);
}

void BattlePlayer::ThrowBallToCatch(bool _IsMasterBall)
{
	const float OffsetY = 200.f;

	BattleMonsterBall* Ball = BattleLevel::BattleLevelPtr->CreateActor<BattleMonsterBall>(UpdateOrder::Battle_Actors);
	_IsMasterBall ? Ball->Init(BattleBallType::Catch_MasterBall) : Ball->Init(BattleBallType::Catch_MonsterBall);
	Ball->SetPos(float4::Down * OffsetY);
}


void BattlePlayer::CreateMontser()
{
	Monster = GetLevel()->CreateActor<BattleMonsterPlayer>(UpdateOrder::Battle_Actors);
	Monster->Init(PokeNumber::Bulbasaur);
	Battle_PlayerBallParticle* Particle = GetLevel()->CreateActor<Battle_PlayerBallParticle>(UpdateOrder::Battle_Actors);
	Particle->SetPos(GetPos());
}