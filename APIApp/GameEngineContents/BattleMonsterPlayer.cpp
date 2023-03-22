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
	SetPos({ 300.f, 300.f });
}

void BattleMonsterPlayer::RenderCreate()
{
	std::string Name = GetName();

	std::string ImagePath = "Battle" + Name + "Back.bmp";
	MonsterRender = CreateRender(ImagePath, BattleRenderOrder::Monster0);
	MonsterRender->SetScaleToImage();

	ImagePath = "Battle" + Name + "BackLight.bmp";
	AppearRender = CreateRender(ImagePath, BattleRenderOrder::Monster0);
	AppearRender->SetScale(float4::Zero);
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
	//TODO

	//Duration �ð��� �����ٸ�
	if (Ratio <= 1.f)
		return;

	CurState = State::Ready;
	AppearRender->Death();
	AppearRender = nullptr;
}
