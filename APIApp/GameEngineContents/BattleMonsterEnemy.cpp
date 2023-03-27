#include "BattleMonsterEnemy.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "BattleEnemy.h"
#include "BattleEnemyMonsterFSM.h"

const float BattleMonsterEnemy::LockTime = 0.3f;

BattleMonsterEnemy::BattleMonsterEnemy()
{
	FsmPtr = new BattleEnemyMonsterFSM;
}

BattleMonsterEnemy::~BattleMonsterEnemy()
{
	if (nullptr != FsmPtr)
	{
		delete FsmPtr;
		FsmPtr = nullptr;
	}
}

void BattleMonsterEnemy::Init(PokeNumber _MonsterType, bool _IsWildMonster)
{
	IsWildMonster = _IsWildMonster;
	BattleMonsterBase::Init(_MonsterType);

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

void BattleMonsterEnemy::Update(float _DeltaTime)
{
	FsmPtr->Update(_DeltaTime);
}



