#include "BattleMonsterBase.h"
#include <typeinfo>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "PokeDataBase.h"
#include "BattleMonster_Bulbasaur.h"
#include "BattlePlayer.h"
#include "BattleEnemy.h"
#include "ContentsEnum.h"
#include "EnemyHPBackground.h"

BattleMonsterBase* BattleMonsterBase::CreateMonster(GameEngineLevel* _Level, PokeNumber _MonType, BattleMonsterType _OwnerType)
{
	BattleMonsterBase* MonsterPtr = nullptr;

	switch (_MonType)
	{
	case PokeNumber::Bulbasaur:
		MonsterPtr = _Level->CreateActor<BattleMonster_Bulbasaur>();
		break;
	case PokeNumber::Ivysaur:
		break;
	case PokeNumber::Venusaur:
		break;
	case PokeNumber::Charmander:
		break;
	case PokeNumber::Charmeleon:
		break;
	case PokeNumber::Charizard:
		break;
	case PokeNumber::Squirtle:
		break;
	case PokeNumber::Wartortle:
		break;
	case PokeNumber::Blastoise:
		break;
	case PokeNumber::Pidgey:
		break;
	case PokeNumber::Rattata:
		break;
	case PokeNumber::Spearow:
		break;
	case PokeNumber::Geodude:
		break;
	case PokeNumber::Onix:
		break;
	}

	if (nullptr == MonsterPtr)
	{
		MsgAssert("���� �ش� ���Ϳ� ���� Ŭ������ ����������� �ʾҽ��ϴ�");
		return nullptr;
	}

	//������ ���� Ŭ������ �̸� ���ϱ�
	std::string Name = typeid(*MonsterPtr).name();
	size_t Index = Name.find('_') + 1;
	Name = Name.substr(Index, Name.length() - Index);
	MonsterPtr->SetName(Name);

	//������ Render����
	MonsterPtr->OwnerType = _OwnerType;
	MonsterPtr->RenderCreate();

	//�߻����ϸ��� ��쿣 FSM�� Move���� ����(�������� Appear���� ����)
	if (BattleMonsterType::WildMon == _OwnerType)
	{
		MonsterPtr->CurState = BattleMonsterBase::State::Move;
	}

	MonsterPtr->DbPtr = PokeDataBase::PokeCreate(static_cast<int>(_MonType) + 1);
	return MonsterPtr;
}

void BattleMonsterBase::RenderCreate()
{
	std::string ImagePath = "Battle" + GetName();
	GameEngineRender* RenderPtr = nullptr;

	//���ϸ��� ���� �̹��� ����
	if (BattleMonsterType::PlayerMon == OwnerType)
	{
		RenderPtr = CreateRender(ImagePath + "Back.bmp", RenderOrder::Monster);
	}
	else
	{
		RenderPtr = CreateRender(ImagePath + "Front.bmp", RenderOrder::Monster);
	}
	RenderPtr->SetScaleToImage();

	GameEngineActor* UiPtr = nullptr;

	//���ϸ��� �����Ҷ� ȿ�� �̹��� ����(�׸��� or ���ͺ����� �����Ҷ� ��ȫ�� ��)
	switch (OwnerType)
	{
	case BattleMonsterType::PlayerMon:
		AppearRender = CreateRender(ImagePath + "BackLight.bmp", RenderOrder::Monster);
		break;
	case BattleMonsterType::WildMon:
		AppearRender = CreateRender(ImagePath + "Shadow.bmp", RenderOrder::Monster);
		UiPtr = GetLevel()->CreateActor<EnemyHPBackground>();
		break;
	case BattleMonsterType::NPCMon:
		AppearRender = CreateRender(ImagePath + "FrontLight.bmp", RenderOrder::Monster);
		break;
	}

	SetInfoUI(UiPtr);
	AppearRender->SetScaleToImage(); 
	AppearRender->SetAlpha(static_cast<int>(StartAlpha.x));
}




BattleMonsterBase::BattleMonsterBase()
{

}

BattleMonsterBase::~BattleMonsterBase()
{

}











void BattleMonsterBase::Update(float _DeltaTime)
{
	switch (CurState)
	{
	case BattleMonsterBase::State::Move:
		Update_Move();
		break;
	case BattleMonsterBase::State::Appear:
		Update_Appear();
		break;
	case BattleMonsterBase::State::Ready:
		//Ready�϶� Update���� �ƹ��͵� ���� ����
		break;
	}
}



void BattleMonsterBase::Update_Move()
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

void BattleMonsterBase::Update_Appear()
{
	//���� ����Ʈ�� ������ �ð�
	static const float Duration = 0.2f;
	
	//���Ͱ� �����ϰ� �� �� ���� �ð�
	float During = GetLiveTime() - AppearTime;

	//���İ� ����
	float Ratio = (During / Duration);
	float NowAlpha = float4::LerpClamp(StartAlpha, float4::Zero, Ratio).x;
	AppearRender->SetAlpha(static_cast<int>(NowAlpha));

	//Duration �ð��� �����ٸ�
	if (Ratio <= 1.f)
		return;

	CurState = State::Ready;
	AppearRender->Death();
	AppearRender = nullptr;
}








