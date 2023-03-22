#include "BattleMonsterEnemy.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnum.h"
#include "BattleEnemy.h"

BattleMonsterEnemy::BattleMonsterEnemy()
{

}

BattleMonsterEnemy::~BattleMonsterEnemy()
{

}

void BattleMonsterEnemy::Init(PokeNumber _MonsterType, bool _IsWildMonster)
{
	BattleMonsterBase::Init(_MonsterType);

	IsWildMonster = _IsWildMonster;
	if (true == IsWildMonster)
	{
		CurState = State::Move;
	}

	RenderCreate();
}



void BattleMonsterEnemy::RenderCreate()
{
	std::string Name = GetName();

	std::string ImagePath = "Battle" + Name + "Front.bmp";
	MonsterRender = CreateRender(ImagePath, BattleRenderOrder::Monster0);
	MonsterRender->SetScaleToImage();

	//야생포켓몬인 경우
	if (true == IsWildMonster)
	{
		ImagePath = "Battle" + Name + "Shadow.bmp";
		AppearRender = CreateRender(ImagePath, BattleRenderOrder::Monster0);
		AppearRender->SetScaleToImage();
		AppearRender->SetAlpha(StartAlpha.ix());
		return;
	}

	//NPC포켓몬인 경우
	ImagePath = "Battle" + Name + "FrontLight.bmp";
	AppearRender = CreateRender(ImagePath, BattleRenderOrder::Monster0);
	AppearRender->SetScale(float4::Zero);
}






void BattleMonsterEnemy::Update(float _DeltaTime)
{
	switch (CurState)
	{
	case BattleMonsterEnemy::State::Move:
		Update_Move();
		break;
	case BattleMonsterEnemy::State::Appear:
		IsWildMonster ? Update_WildAppear() : Update_NPCAppear();
		break;
	case BattleMonsterEnemy::State::Ready:
		//Ready일땐 아무것도 하지 않는다.
		break;
	}
}


void BattleMonsterEnemy::Update_Move()
{
	if (nullptr == BattleEnemy::EnemyPtr)
	{
		MsgAssert("적이 존재하지 않습니다");
		return;
	}

	static const float Duration = 1.6f;
	static const float4 OffsetPos = float4{ 0.f, -50.f };

	//움직임이 끝났다면 Appear 상태로 변경	 이거 float 소수점 문제도 있음 이 방식은 비추
	float LiveTime = GetLiveTime();
	if (Duration < LiveTime)
	{
		CurState = State::Appear;
		AppearTime = LiveTime;
		return;
	}

	float4 TargetPos = BattleEnemy::EnemyPtr->GetPos();
	float4 NextPos = (TargetPos + OffsetPos);
	SetPos(NextPos);
}

void BattleMonsterEnemy::Update_WildAppear()
{
	//등장 이펙트가 동작할 시간
	static const float Duration = 0.2f;

	//몬스터가 등장하고 난 후 지난 시간
	float During = GetLiveTime() - AppearTime;

	//알파값 조정
	float Ratio = (During / Duration);
	int NowAlpha = float4::LerpClamp(StartAlpha, float4::Zero, Ratio).ix();
	AppearRender->SetAlpha(NowAlpha);

	//Duration 시간이 지났다면
	if (Ratio <= 1.f)
		return;

	CurState = State::Ready;
	AppearRender->Death();
	AppearRender = nullptr;
}

void BattleMonsterEnemy::Update_NPCAppear()
{

}

