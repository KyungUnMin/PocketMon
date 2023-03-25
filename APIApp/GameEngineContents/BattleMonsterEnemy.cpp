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

	//�߻����ϸ��� ���
	if (true == IsWildMonster)
	{
		ImagePath = "Battle" + Name + "Shadow.bmp";
		AppearRender = CreateRender(ImagePath, BattleRenderOrder::Monster0);
		AppearRender->SetScaleToImage();
		AppearRender->SetAlpha(StartAlpha.ix());
		return;
	}

	//NPC���ϸ��� ���
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
		//Ready�϶� �ƹ��͵� ���� �ʴ´�.
		break;
	}
}


void BattleMonsterEnemy::Update_Move()
{
	if (nullptr == BattleEnemy::EnemyPtr)
	{
		MsgAssert("���� �������� �ʽ��ϴ�");
		return;
	}

	static const float Duration = 1.6f;
	static const float4 OffsetPos = float4{ 0.f, -50.f };

	//�������� �����ٸ� Appear ���·� ����	 �̰� float �Ҽ��� ������ ���� �� ����� ����
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
	//���� ����Ʈ�� ������ �ð�
	static const float Duration = 0.2f;

	//���Ͱ� �����ϰ� �� �� ���� �ð�
	float During = GetLiveTime() - AppearTime;

	//���İ� ����
	float Ratio = (During / Duration);
	int NowAlpha = float4::LerpClamp(StartAlpha, float4::Zero, Ratio).ix();
	AppearRender->SetAlpha(NowAlpha);

	//Duration �ð��� �����ٸ�
	if (Ratio <= 1.f)
		return;

	CurState = State::Ready;
	AppearRender->Death();
	AppearRender = nullptr;
}

void BattleMonsterEnemy::Update_NPCAppear()
{

}

