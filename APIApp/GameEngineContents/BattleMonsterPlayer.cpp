#include "BattleMonsterPlayer.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBase.h"
#include "ContentsEnum.h"
#include "Battle_MonsterAppearEffect.h"
#include "BattlePlayerMonsterFSM.h"


BattleMonsterPlayer::BattleMonsterPlayer()
{
	FsmPtr = new BattlePlayerMonsterFSM;
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
	BattleMonsterBase::Init(_MonsterType);

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
