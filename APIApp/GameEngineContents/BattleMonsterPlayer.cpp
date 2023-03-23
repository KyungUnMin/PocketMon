#include "BattleMonsterPlayer.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBase.h"
#include "ContentsEnum.h"
#include "Battle_MonsterAppearEffect.h"


BattleMonsterPlayer::BattleMonsterPlayer()
{

}

BattleMonsterPlayer::~BattleMonsterPlayer()
{

}

void BattleMonsterPlayer::Init(PokeNumber _MonsterType)
{
	BattleMonsterBase::Init(_MonsterType);

	RenderCreate();
}

void BattleMonsterPlayer::RenderCreate()
{
	std::string Name = GetName();

	std::string ImagePath = "Battle" + Name + "Back.bmp";
	MonsterRender = CreateRender(ImagePath, BattleRenderOrder::Monster0);
	MonsterRender->SetScaleToImage();
	MonsterRender->Off();

	ImagePath = "Battle" + Name + "BackLight.bmp";
	AppearRender = CreateRender(ImagePath, BattleRenderOrder::Monster0);
	AppearRender->SetScale(float4::Zero);
	AppearRender->SetAlpha(200);
}


void BattleMonsterPlayer::Update(float _DeltaTime)
{
	switch (CurState)
	{
	case BattleMonsterPlayer::State::Appear:
		Update_Appear();
		break;
	case BattleMonsterPlayer::State::Ready:
		//Ready일땐 아무것도 하지 않는다.
		break;
	}
}


void BattleMonsterPlayer::Update_Appear()
{
	//알파값 조정
	float Ratio = (GetLiveTime() / Battle_MonsterAppearEffect::FadeDuration);

	float4 DestScale = MonsterRender->GetScale();
	float4 NowScale = float4::LerpClamp(float4::Zero, DestScale, Ratio);
	AppearRender->SetScale(NowScale);

	//Duration 시간이 지났다면
	if (Ratio <= 1.f)
		return;

	CurState = State::Ready;
	AppearRender->Off();
	MonsterRender->On();
}
