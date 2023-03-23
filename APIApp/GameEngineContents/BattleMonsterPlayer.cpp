#include "BattleMonsterPlayer.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBase.h"
#include "ContentsEnum.h"


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
	AppearRender->SetAlpha(100);
}


void BattleMonsterPlayer::Update(float _DeltaTime)
{
	switch (CurState)
	{
	case BattleMonsterPlayer::State::Appear:
		Update_Appear();
		break;
	case BattleMonsterPlayer::State::Ready:
		//Ready�϶� �ƹ��͵� ���� �ʴ´�.
		break;
	}
}


void BattleMonsterPlayer::Update_Appear()
{
	//���� ����Ʈ�� ������ �ð�
	static const float Duration = 0.2f;

	//���İ� ����
	float Ratio = (GetLiveTime() / Duration);

	float4 DestScale = MonsterRender->GetScale();
	float4 NowScale = float4::LerpClamp(float4::Zero, DestScale, Ratio);
	AppearRender->SetScale(NowScale);

	//Duration �ð��� �����ٸ�
	if (Ratio <= 1.f)
		return;

	CurState = State::Ready;
	AppearRender->Off();
	MonsterRender->On();
}
