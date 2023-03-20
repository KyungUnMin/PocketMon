#include "PokeDataBase.h"

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>

#include "PokeSkillBase.h"

PokeDataBase PokeDataBase::Ptr;                                                     // PokeDataBasePtr (사용X)
std::list<PokeDataBase*> PokeDataBase::AllPokemons = std::list<PokeDataBase*>();    // 모든 포켓몬 (왠만하면 사용 X)
std::list<PokeSkillBase*> PokeDataBase::AllSkills = std::list<PokeSkillBase*>();    // 모든 스킬 (왠만하면 사용 X)

std::vector<PokeSkillBase*> PokeDataBase::SkillList = std::vector<PokeSkillBase*>(4);

GameEngineRender* PokeDataBase::MonsterImage = nullptr;						// 포켓몬 이미지
std::string PokeDataBase::Name = "안농";										// 포켓몬 이름

bool PokeDataBase::IsMan = true;											// 포켓몬 성별
bool PokeDataBase::IsbeCaught = false;									    // 야생포켓몬인지 잡힌 포켓몬인지

PokeNumber PokeDataBase::PokeDexNumber = PokeNumber::Max;					// 포켓몬 도감 번호
int PokeDataBase::MaxHealthPoint = 0;									    // 몬스터 최대 체력
int PokeDataBase::CurrentHealthPoint = 0;									// 몬스터 잔여 체력
int PokeDataBase::AttackPower = 0;											// 몬스터 공격력
int PokeDataBase::Defense = 0;												// 몬스터 방어력
int PokeDataBase::SpecialAttackPower = 0;								    // 몬스터 특수공격력
int PokeDataBase::SpecialDefense = 0;									    // 몬스터 특수방어력
int PokeDataBase::Agility = 0;											    // 몬스터 민첩성
int PokeDataBase::MonsterLevel = 0;										    // 몬스터 레벨
int PokeDataBase::Experience = 0;										    // 몬스터 경험치
int PokeDataBase::RemainingExperience = 0;								    // 몬스터 다음 레벨까지 남은 경험치

int PokeDataBase::PokeBall = 0;												// 포켓몬이 담겨있는 포켓볼 종류
PokeType PokeDataBase::Type = PokeType::Normal;								// 포켓몬 속성 타입
PokePersonality PokeDataBase::Personality = PokePersonality::Serious;	    // 포켓몬 성격
PokeCharacteristic PokeDataBase::Characteristic = PokeCharacteristic::심록;	// 포켓몬 특성

PokeDataBase::PokeDataBase() 
{
}

PokeDataBase::~PokeDataBase() 
{
}

void PokeDataBase::Release()
{
	for (PokeSkillBase* Sk : AllSkills)
	{
		if (nullptr == Sk)
		{
			continue;
		}

		delete Sk;
		Sk = nullptr;
	}

	for (PokeDataBase* Pokes : AllPokemons)
	{
		if (nullptr == Pokes)
		{
			continue;
		}

		delete Pokes;
		Pokes = nullptr;
	}
}

PokeDataBase* PokeDataBase::PokeCreate(int _PokeDexNumber, int _Level)
{
	int ChangePokeNumber = _PokeDexNumber - 1;
	int MaxNumber = static_cast<int>(PokeNumber::Max);

	if (ChangePokeNumber >= MaxNumber)
	{
		MsgAssert("포켓몬 넘버는 14(롱스톤)까지만 존재합니다.");
		return nullptr;
	}
	else if (ChangePokeNumber < 0)
	{
		MsgAssert("포켓몬 넘버는 1(이상해씨) 미만일 수 없습니다.");
		return nullptr;
	}

	if (_Level <= 0)
	{
		MsgAssert("레벨이 0인 포켓몬은 생성할 수 없습니다.");
		return nullptr;
	}

	PokeDataBase* PoKeCreatePtr = new PokeDataBase();

	PoKeCreatePtr->PokeDexNumber = static_cast<PokeNumber>(ChangePokeNumber);

	switch (PoKeCreatePtr->PokeDexNumber)
	{
	case PokeNumber::Bulbasaur:
	{
		BulbasaurData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);
		
		if (PoKeCreatePtr->MonsterLevel >= 7)
		{
			PokeSkillInit(3, PokeSkill::LeechSeed, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		}
		if (PoKeCreatePtr->MonsterLevel >= 9)
		{
			PokeSkillInit(4, PokeSkill::VineWhip, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Ivysaur:
	{
		IvysaurData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 7)
		{
			PokeSkillInit(3, PokeSkill::LeechSeed, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		}
		if (PoKeCreatePtr->MonsterLevel >= 9)
		{
			PokeSkillInit(4, PokeSkill::VineWhip, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Venusaur:
	{
		VenusaurData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 7)
		{
			PokeSkillInit(3, PokeSkill::LeechSeed, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		}
		if (PoKeCreatePtr->MonsterLevel >= 9)
		{
			PokeSkillInit(4, PokeSkill::VineWhip, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Charmander:
	{
		CharmanderData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Scratch, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Growl, PoKeCreatePtr );
		
		if (PoKeCreatePtr->MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Ember, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		}
		if (PoKeCreatePtr->MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::Leer, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Charmeleon:
	{
		CharmeleonData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Scratch, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Growl, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Ember, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		}
		if (PoKeCreatePtr->MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::Leer, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Charizard:
	{
		CharizardData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Scratch, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Growl, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Ember, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		}
		if (PoKeCreatePtr->MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::Leer, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Squirtle:
	{
		SquirtleData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Bubble, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		}
		if (PoKeCreatePtr->MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::WaterGun, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Wartortle:
	{
		WartortleData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Bubble, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		}
		if (PoKeCreatePtr->MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::WaterGun, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Blastoise:
	{
		BlastoiseData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Bubble, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		}
		if (PoKeCreatePtr->MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::WaterGun, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Pidgey:
	{
		PidgeyData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::SandAttack, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Gust, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		}
		if (PoKeCreatePtr->MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::QuickAttack, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Rattata:
	{
		RattataData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::TailWhip, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::QuickAttack, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::HyperFang, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Spearow:
	{
		SpearowData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Peck, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::Growl, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::Leer, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 9)
		{
			PokeSkillInit(4, PokeSkill::FuryAttack, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Geodude:
	{
		GeodudeData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::DefenseCurl, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::RockPolish, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(3, PokeSkill::Unknown, PoKeCreatePtr);
		}
		if (PoKeCreatePtr->MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::RockThrow, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	case PokeNumber::Onix:
	{
		OnixData(_Level, PoKeCreatePtr);

		PokeSkillInit(1, PokeSkill::Tackle, PoKeCreatePtr);
		PokeSkillInit(2, PokeSkill::DefenseCurl, PoKeCreatePtr);
		PokeSkillInit(3, PokeSkill::Bind, PoKeCreatePtr);

		if (PoKeCreatePtr->MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::RockThrow, PoKeCreatePtr);
		}
		else
		{
			PokeSkillInit(4, PokeSkill::Unknown, PoKeCreatePtr);
		}
	}
	break;
	default:
	break;
	}

	AllPokemons.push_back(PoKeCreatePtr);

	return PoKeCreatePtr;
}

//////////////////////////////////////////////////////////////// 푸키먼 전투

void PokeDataBase::Attack()
{

}

// 몬스터를 처치하면 경험치 획득
void PokeDataBase::PokeExperienceAcquisition(int _EXP)
{
	// 몬스터의 종류 확인
	// 몬스터의 레벨 확인
	// 획득 경험치 산출
	// 자신의 경험치에 추가
	//PoKeCreatePtr->Experience += _EXP;
}

// 일정 경험치 이상을 획득할 경우 레벨이 증가
void PokeDataBase::PokeLevelUp(int _EXP)
{
	//int AcquiExperience = _EXP;
	//int PlusExperience = Experience + _EXP;
	//int ResidueExperience = PlusExperience - 100;

	//if (PlusExperience >= 100)
	//{
	//	PoKeCreatePtr->MonsterLevel += 1;
	//	PoKeCreatePtr->Experience = 0;
	//}

	//PoKeCreatePtr->Experience += PlusExperience;
}

// 레벨업을 하면 체력, 공격력, 방어력, 특수공격력, 특수방어력, 민첩성이 증가
void PokeDataBase::PokeStatusUp(PokeDataBase* _PoKeCreatePtr)
{
	_PoKeCreatePtr->MaxHealthPoint += 1;
	_PoKeCreatePtr->AttackPower += 1;
	_PoKeCreatePtr->Defense += 1;
	_PoKeCreatePtr->SpecialAttackPower += 1;
	_PoKeCreatePtr->SpecialDefense += 1;
	_PoKeCreatePtr->Agility += 1;
}

//////////////////////////////////////////////////////////////// 푸키먼 데이터

// PokeCreate() 함수를 호출하면 해당 구역의 함수를 연계적으로 호출하여 데이터를 입력해줍니다.
// 데이터 생성 보조 함수와 푸키먼 데이터 함수가 있습니다.

// 푸키먼 스킬 이닛
void PokeDataBase::PokeSkillInit(int _Skillslot, PokeSkill _SkillName, PokeDataBase* _PoKeCreatePtr)
{
	PokeSkillBase* Skill = new PokeSkillBase();
	Skill->InitCreateSkill(_SkillName);

	_PoKeCreatePtr->SkillList[_Skillslot - 1] = Skill;

	AllSkills.push_back(_PoKeCreatePtr->SkillList[_Skillslot - 1]);
}

// 성별 결정
void PokeDataBase::GenderDecision(PokeDataBase* _PoKeCreatePtr)
{
	int RandValue = GameEngineRandom::MainRandom.RandomInt(1, 2);

	if (1 == RandValue)
	{
		_PoKeCreatePtr->IsMan = true;  // 수컷
	}
	else
	{
		_PoKeCreatePtr->IsMan = false; // 암컷
	}
}

// 성격 결정
void PokeDataBase::PersonalityDecision(PokeDataBase* _PoKeCreatePtr)
{
	int RandValue = GameEngineRandom::MainRandom.RandomInt(0, 24);

	_PoKeCreatePtr->Personality = static_cast<PokePersonality>(RandValue);

	// 오류로 인해 임시 반환 값
	// return PokePersonality::Adamant;
}

// No.1 이상해씨
void PokeDataBase::BulbasaurData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);                            // 성별 결정 (암, 수)
	PersonalityDecision(PoKeCreatePtr);                       // 성격 결정 (신중한 등)
	PoKeCreatePtr->Type = PokeType::Grass;                    // 포켓몬 타입 
	PoKeCreatePtr->Characteristic = PokeCharacteristic::심록; // 포켓몬 특성
	PoKeCreatePtr->Name = "Bulbasaur";                        // 포켓몬 디폴트 이름
	
	PoKeCreatePtr->MaxHealthPoint = 45;                       // 포켓몬 기초 최대 체력
	PoKeCreatePtr->CurrentHealthPoint = 45;                   // 포켓몬 기초 잔여 체력
	PoKeCreatePtr->AttackPower = 49;                          // 포켓몬 기초 공격력
	PoKeCreatePtr->Defense = 49;                              // 포켓몬 기초 방어력
	PoKeCreatePtr->SpecialAttackPower = 65;                   // 포켓몬 기초 특수공격력
	PoKeCreatePtr->SpecialDefense = 65;                       // 포켓몬 기초 특수방어력 // "특수"는 마법공격, 마법방어로, 노말은 물리공격, 물리방어로 생각하면 됩니다.
	PoKeCreatePtr->Agility = 45;                              // 포켓몬 기초 스피드
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;     // 야생 포켓몬 스폰 목적 시, 레벨을 입력해줍니다.

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.2 이상해풀
void PokeDataBase::IvysaurData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Grass;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::심록;
	PoKeCreatePtr->Name = "Ivysaur";

	PoKeCreatePtr->MaxHealthPoint = 60;
	PoKeCreatePtr->CurrentHealthPoint = 60;
	PoKeCreatePtr->AttackPower = 62;
	PoKeCreatePtr->Defense = 63;
	PoKeCreatePtr->SpecialAttackPower = 80;
	PoKeCreatePtr->SpecialDefense = 80;
	PoKeCreatePtr->Agility = 60;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}
// No.3 이상해꽃
void PokeDataBase::VenusaurData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Grass;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::심록;
	PoKeCreatePtr->Name = "Venusaur";

	PoKeCreatePtr->MaxHealthPoint = 80;
	PoKeCreatePtr->CurrentHealthPoint = 80;
	PoKeCreatePtr->AttackPower = 82;
	PoKeCreatePtr->Defense = 83;
	PoKeCreatePtr->SpecialAttackPower = 100;
	PoKeCreatePtr->SpecialDefense = 100;
	PoKeCreatePtr->Agility = 80;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.4 파이리
void PokeDataBase::CharmanderData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Fire;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::맹화;
	PoKeCreatePtr->Name = "Charmander";

	PoKeCreatePtr->MaxHealthPoint = 39;
	PoKeCreatePtr->CurrentHealthPoint = 39;
	PoKeCreatePtr->AttackPower = 52;
	PoKeCreatePtr->Defense = 43;
	PoKeCreatePtr->SpecialAttackPower = 60;
	PoKeCreatePtr->SpecialDefense = 50;
	PoKeCreatePtr->Agility = 65;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.5 리자드
void PokeDataBase::CharmeleonData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Fire;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::맹화;
	PoKeCreatePtr->Name = "Charmeleon";

	PoKeCreatePtr->MaxHealthPoint = 58;
	PoKeCreatePtr->CurrentHealthPoint = 58;
	PoKeCreatePtr->AttackPower = 64;
	PoKeCreatePtr->Defense = 58;
	PoKeCreatePtr->SpecialAttackPower = 80;
	PoKeCreatePtr->SpecialDefense = 65;
	PoKeCreatePtr->Agility = 80;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.6 리자몽
void PokeDataBase::CharizardData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Fire;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::맹화;
	PoKeCreatePtr->Name = "Charizard";

	PoKeCreatePtr->MaxHealthPoint = 78;
	PoKeCreatePtr->CurrentHealthPoint = 78;
	PoKeCreatePtr->AttackPower = 84;
	PoKeCreatePtr->Defense = 78;
	PoKeCreatePtr->SpecialAttackPower = 109;
	PoKeCreatePtr->SpecialDefense = 85;
	PoKeCreatePtr->Agility = 100;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.7 꼬부기
void PokeDataBase::SquirtleData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Water;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::급류;
	PoKeCreatePtr->Name = "Squirtle";

	PoKeCreatePtr->MaxHealthPoint = 44;
	PoKeCreatePtr->CurrentHealthPoint = 44;
	PoKeCreatePtr->AttackPower = 48;
	PoKeCreatePtr->Defense = 65;
	PoKeCreatePtr->SpecialAttackPower = 50;
	PoKeCreatePtr->SpecialDefense = 64;
	PoKeCreatePtr->Agility = 43;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.8 어니부기
void PokeDataBase::WartortleData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Water;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::급류;
	PoKeCreatePtr->Name = "Wartortle";

	PoKeCreatePtr->MaxHealthPoint = 59;
	PoKeCreatePtr->CurrentHealthPoint = 59;
	PoKeCreatePtr->AttackPower = 63;
	PoKeCreatePtr->Defense = 80;
	PoKeCreatePtr->SpecialAttackPower = 65;
	PoKeCreatePtr->SpecialDefense = 80;
	PoKeCreatePtr->Agility = 58;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.9 거북왕
void PokeDataBase::BlastoiseData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Water;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::급류;
	PoKeCreatePtr->Name = "Blastoise";

	PoKeCreatePtr->MaxHealthPoint = 79;
	PoKeCreatePtr->CurrentHealthPoint = 79;
	PoKeCreatePtr->AttackPower = 83;
	PoKeCreatePtr->Defense = 100;
	PoKeCreatePtr->SpecialAttackPower = 85;
	PoKeCreatePtr->SpecialDefense = 105;
	PoKeCreatePtr->Agility = 78;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.10 구구
void PokeDataBase::PidgeyData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Flying;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::날카로운눈;
	PoKeCreatePtr->Name = "Pidgey";

	PoKeCreatePtr->MaxHealthPoint = 40;
	PoKeCreatePtr->CurrentHealthPoint = 40;
	PoKeCreatePtr->AttackPower = 45;
	PoKeCreatePtr->Defense = 40;
	PoKeCreatePtr->SpecialAttackPower = 35;
	PoKeCreatePtr->SpecialDefense = 35;
	PoKeCreatePtr->Agility = 56;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.11 꼬렛
void PokeDataBase::RattataData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Normal;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::근성;
	PoKeCreatePtr->Name = "Rattata";

	PoKeCreatePtr->MaxHealthPoint = 30;
	PoKeCreatePtr->CurrentHealthPoint = 30;
	PoKeCreatePtr->AttackPower = 56;
	PoKeCreatePtr->Defense = 35;
	PoKeCreatePtr->SpecialAttackPower = 25;
	PoKeCreatePtr->SpecialDefense = 35;
	PoKeCreatePtr->Agility = 72;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.12 깨비참
void PokeDataBase::SpearowData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Flying;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::날카로운눈;
	PoKeCreatePtr->Name = "Spearow";

	PoKeCreatePtr->MaxHealthPoint = 40;
	PoKeCreatePtr->CurrentHealthPoint = 40;
	PoKeCreatePtr->AttackPower = 60;
	PoKeCreatePtr->Defense = 30;
	PoKeCreatePtr->SpecialAttackPower = 31;
	PoKeCreatePtr->SpecialDefense = 31;
	PoKeCreatePtr->Agility = 70;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.13 꼬마돌
void PokeDataBase::GeodudeData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Rock;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::돌머리;
	PoKeCreatePtr->Name = "Geodude";

	PoKeCreatePtr->MaxHealthPoint = 40;
	PoKeCreatePtr->CurrentHealthPoint = 40;
	PoKeCreatePtr->AttackPower = 80;
	PoKeCreatePtr->Defense = 100;
	PoKeCreatePtr->SpecialAttackPower = 30;
	PoKeCreatePtr->SpecialDefense = 30;
	PoKeCreatePtr->Agility = 20;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}

// No.14 롱스톤
void PokeDataBase::OnixData(int _Level, PokeDataBase* PoKeCreatePtr)
{
	GenderDecision(PoKeCreatePtr);
	PersonalityDecision(PoKeCreatePtr);
	PoKeCreatePtr->Type = PokeType::Rock;
	PoKeCreatePtr->Characteristic = PokeCharacteristic::돌머리;
	PoKeCreatePtr->Name = "Onix";

	PoKeCreatePtr->MaxHealthPoint = 35;
	PoKeCreatePtr->CurrentHealthPoint = 35;
	PoKeCreatePtr->AttackPower = 45;
	PoKeCreatePtr->Defense = 160;
	PoKeCreatePtr->SpecialAttackPower = 30;
	PoKeCreatePtr->SpecialDefense = 45;
	PoKeCreatePtr->Agility = 70;
	PoKeCreatePtr->MonsterLevel = 0;
	int PlusLevel = PoKeCreatePtr->MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(PoKeCreatePtr);
	}

	PoKeCreatePtr->MonsterLevel = PlusLevel;
}