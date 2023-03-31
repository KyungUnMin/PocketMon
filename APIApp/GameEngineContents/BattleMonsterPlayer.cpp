#include "BattleMonsterPlayer.h"
#include <GameEngineCore/GameEngineRender.h>
#include "BattleMonsterBase.h"
#include "ContentsEnum.h"
#include "Battle_MonsterAppearEffect.h"
#include "BattlePlayerMonsterFSM.h"
#include "BattleFSM.h"
#include "BattleLevel.h"
#include "Battle_PlayerHpUIHandler.h"
#include "Player.h"


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

	if (nullptr != UiHandler)
	{
		UiHandler->Death();
		UiHandler = nullptr;
	}
}

void BattleMonsterPlayer::Init()
{
	TrainerPokemon* Monsters = Player::MainPlayer->GetPlayerPokemon();
	if (false == Monsters->HasNextPokemon())
	{
		MsgAssert("������ ������ �÷��̾� ���Ͱ� �������� �ʽ��ϴ�");
		return;
	}

	//asdjkbd
	PokeDataBase* DB = Monsters->NextPokemon();
	BattleMonsterBase::Init(DB);

	RenderCreate();
	FsmPtr->Init();
}

void BattleMonsterPlayer::RenderCreate()
{
	std::string Name = GetName();

	std::string ImagePath = "Battle" + Name + "Back.bmp";
	RenderPtr = CreateRender(ImagePath, BattleRenderOrder::Monster0);
	RenderPtr->SetScaleToImage();
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
