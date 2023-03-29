#include "BattleMonsterPlayer.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBase.h"
#include "ContentsEnum.h"
#include "Battle_MonsterAppearEffect.h"
#include "BattlePlayerMonsterFSM.h"
#include "BattleFSM.h"
#include "BattleLevel.h"
#include "Battle_PlayerHpUIHandler.h"


BattleMonsterPlayer::BattleMonsterPlayer()
{
	FsmPtr = new BattlePlayerMonsterFSM(this);
}

BattleMonsterPlayer::~BattleMonsterPlayer()
{
	if (nullptr != FsmPtr)
	{
		delete FsmPtr;
		FsmPtr = nullptr;
	}
}

void BattleMonsterPlayer::Init(PokeNumber _MonsterType)
{
	BattleMonsterBase::Init(_MonsterType, 10);

	RenderCreate();
	FsmPtr->Init();
}

void BattleMonsterPlayer::RenderCreate()
{
	std::string Name = GetName();

	std::string ImagePath = "Battle" + Name + "Back.bmp";
	RenderPtr = CreateRender(ImagePath, BattleRenderOrder::Monster0);
	RenderPtr->SetScaleToImage();

	/*ImagePath = "Battle" + Name + "BackLight.bmp";
	AppearRender = CreateRender(ImagePath, BattleRenderOrder::Monster0);
	AppearRender->SetScale(float4::Zero);
	AppearRender->SetAlpha(200);*/
}


void BattleMonsterPlayer::KillMonster()
{
	BattleFSM* GameFSM = BattleLevel::BattleLevelPtr->GetBattleFSM();
	BattleStateType NowGameState = GameFSM->GetNowState<BattleStateType>();
	if (BattleStateType::StageLose != NowGameState)
	{
		MsgAssert("플레이어가 현재 대결에서 패배한 상태일때만 플레이어 몬스터를 죽일수 있습니다");
		return;
	}

	FsmPtr->ChangeState(BattlePlayerMonster_StateType::Dead);
}

void BattleMonsterPlayer::CreateHpUI()
{
	UiHandler = GetLevel()->CreateActor<Battle_PlayerHpUIHandler>(UpdateOrder::Battle_Actors);
}

void BattleMonsterPlayer::DamageOnIU(int _Value)
{
	UiHandler->OnDamage(_Value);
}

void BattleMonsterPlayer::Update(float _DeltaTime)
{
	FsmPtr->Update(_DeltaTime);
}

//
//void BattleMonsterPlayer::Update_Appear()
//{
//	//알파값 조정
//	float Ratio = (GetLiveTime() / Battle_MonsterAppearEffect::FadeDuration);
//
//	float4 DestScale = MonsterRender->GetScale();
//	float4 NowScale = float4::LerpClamp(float4::Zero, DestScale, Ratio);
//	AppearRender->SetScale(NowScale);
//
//	//Duration 시간이 지났다면
//	if (Ratio <= 1.f)
//		return;
//
//	CurState = State::Ready;
//	AppearRender->Off();
//	MonsterRender->On();
//}
