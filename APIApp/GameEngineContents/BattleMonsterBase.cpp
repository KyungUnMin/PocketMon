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
		MsgAssert("아직 해당 몬스터에 대한 클래스와 연결시켜주지 않았습니다");
		return nullptr;
	}

	//생성한 몬스터 클래스의 이름 구하기
	std::string Name = typeid(*MonsterPtr).name();
	size_t Index = Name.find('_') + 1;
	Name = Name.substr(Index, Name.length() - Index);
	MonsterPtr->SetName(Name);

	//몬스터의 Render생성
	MonsterPtr->OwnerType = _OwnerType;
	MonsterPtr->RenderCreate();

	//야생포켓몬인 경우엔 FSM을 Move부터 시작(나머지는 Appear부터 시작)
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

	//포켓몬의 실제 이미지 생성
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

	//포켓몬이 등장할때 효과 이미지 생성(그림자 or 몬스터볼에서 등장할때 분홍색 빛)
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
		//Ready일땐 Update에서 아무것도 하지 않음
		break;
	}
}



void BattleMonsterBase::Update_Move()
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

void BattleMonsterBase::Update_Appear()
{
	//등장 이펙트가 동작할 시간
	static const float Duration = 0.2f;
	
	//몬스터가 등장하고 난 후 지난 시간
	float During = GetLiveTime() - AppearTime;

	//알파값 조정
	float Ratio = (During / Duration);
	float NowAlpha = float4::LerpClamp(StartAlpha, float4::Zero, Ratio).x;
	AppearRender->SetAlpha(static_cast<int>(NowAlpha));

	//Duration 시간이 지났다면
	if (Ratio <= 1.f)
		return;

	CurState = State::Ready;
	AppearRender->Death();
	AppearRender = nullptr;
}








