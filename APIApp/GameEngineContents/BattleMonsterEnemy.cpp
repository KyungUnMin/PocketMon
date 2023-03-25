#include "BattleMonsterEnemy.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "BattleEnemy.h"
#include "BattleEnemyMonsterFSM.h"

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

	////NPC포켓몬인 경우
	//ImagePath = "Battle" + Name + "FrontLight.bmp";
	//AppearRender = CreateRender(ImagePath, BattleRenderOrder::Monster0);
	//AppearRender->SetScale(float4::Zero);
}






void BattleMonsterEnemy::Update(float _DeltaTime)
{
	FsmPtr->Update(_DeltaTime);
}



