#include "BattleMonsterPlayer.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBase.h"
#include "ContentsEnum.h"
#include "Battle_MonsterAppearEffect.h"
#include "BattlePlayerMonsterFSM.h"
#include "BattleFSM.h"
#include "BattleLevel.h"


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


void BattleMonsterPlayer::KillMonster()
{
	BattleFSM* GameFSM = BattleLevel::BattleLevelPtr->GetBattleFSM();
	BattleStateType NowGameState = GameFSM->GetNowState<BattleStateType>();
	if (BattleStateType::StageLose != NowGameState)
	{
		MsgAssert("�÷��̾ ���� ��ῡ�� �й��� �����϶��� �÷��̾� ���͸� ���ϼ� �ֽ��ϴ�");
		return;
	}

	FsmPtr->ChangeState(BattlePlayerMonster_StateType::Dead);
}

void BattleMonsterPlayer::Update(float _DeltaTime)
{
	FsmPtr->Update(_DeltaTime);
}

//
//void BattleMonsterPlayer::Update_Appear()
//{
//	//���İ� ����
//	float Ratio = (GetLiveTime() / Battle_MonsterAppearEffect::FadeDuration);
//
//	float4 DestScale = MonsterRender->GetScale();
//	float4 NowScale = float4::LerpClamp(float4::Zero, DestScale, Ratio);
//	AppearRender->SetScale(NowScale);
//
//	//Duration �ð��� �����ٸ�
//	if (Ratio <= 1.f)
//		return;
//
//	CurState = State::Ready;
//	AppearRender->Off();
//	MonsterRender->On();
//}
