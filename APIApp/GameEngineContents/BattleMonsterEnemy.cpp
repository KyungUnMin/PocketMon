#include "BattleMonsterEnemy.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "BattleEnemy.h"
#include "BattleEnemyMonsterFSM.h"
#include "BattleLevel.h"
#include "BattleFSM.h"
#include "Battle_EnemyHpUIHandler.h"

const float BattleMonsterEnemy::LockTime = 0.3f;

BattleMonsterEnemy::BattleMonsterEnemy()
{
	FsmPtr = new BattleEnemyMonsterFSM(this);
}

BattleMonsterEnemy::~BattleMonsterEnemy()
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

void BattleMonsterEnemy::Init(PokeDataBase* _MonsterDB, bool _IsWildMonster)
{
	IsWildMonster = _IsWildMonster;
	BattleMonsterBase::Init(_MonsterDB);

	RenderCreate();
	FsmPtr->Init(_IsWildMonster);
}



void BattleMonsterEnemy::RenderCreate()
{
	std::string Name = GetName();

	std::string ImagePath = "Battle" + Name + "Front.bmp";
	MonsterRender = CreateRender(ImagePath, BattleRenderOrder::Monster0);
	MonsterRender->SetScaleToImage();

	ImagePath = "Battle" + Name + "FrontLight.bmp";
	EffectRender = CreateRender(ImagePath, BattleRenderOrder::Monster1);
	EffectRender->Off();
}







void BattleMonsterEnemy::Lock()
{
	if (false == IsWildMonster)
	{
		MsgAssert("야생 포켓몬만 몬스터볼로 잡을수 있습니다");
		return;
	}

	FsmPtr->ChangeState(BattleEnemyMonster_StateType::Lock);
}

void BattleMonsterEnemy::KillMonster()
{
	BattleFSM* GameFSM = BattleLevel::BattleLevelPtr->GetBattleFSM();
	BattleStateType NowGameState = GameFSM->GetNowState<BattleStateType>();
	if (BattleStateType::StageWin != NowGameState)
	{
		MsgAssert("플레이어가 현재 대결에서 승리한 상태일때만 적 몬스터를 죽일수 있습니다");
		return;
	}

	FsmPtr->ChangeState(BattleEnemyMonster_StateType::Dead);
}

void BattleMonsterEnemy::Update(float _DeltaTime)
{
	FsmPtr->Update(_DeltaTime);
}



void BattleMonsterEnemy::CreateHpUI()
{
	if (nullptr != UiHandler)
		return;

	UiHandler = GetLevel()->CreateActor<Battle_EnemyHpUIHandler>(UpdateOrder::Battle_Actors);
}


void BattleMonsterEnemy::DamageOnIU(int _Value)
{
	UiHandler->OnDamage(_Value);
}
