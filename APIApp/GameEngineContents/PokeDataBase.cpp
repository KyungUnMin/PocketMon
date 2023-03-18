#include "PokeDataBase.h"

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>

#include "PokeSkillBase.h"

PokeDataBase::PokeDataBase() 
{
}

PokeDataBase::~PokeDataBase() 
{
	for (PokeSkillBase* PokeSkills : SkillList)
	{
		if (nullptr == PokeSkills)
		{
			continue;
		}

		delete PokeSkills;
		PokeSkills = nullptr;
	}
}

void PokeDataBase::Attack()
{

}

void PokeDataBase::PokeCreate(int _PokeDexNumber, int _Level)
{
	int ChangePokeNumber = _PokeDexNumber - 1;
	int MaxNumber = static_cast<int>(PokeNumber::Max);

	if (ChangePokeNumber >= MaxNumber)
	{
		MsgAssert("포켓몬 넘버는 14(롱스톤)까지만 존재합니다.");
		return;
	}
	else if (ChangePokeNumber < 0)
	{
		MsgAssert("포켓몬 넘버는 1(이상해씨) 미만일 수 없습니다.");
		return;
	}

	if (_Level <= 0)
	{
		MsgAssert("레벨이 0인 포켓몬은 생성할 수 없습니다.");
		return;
	}

	PokeDexNumber = static_cast<PokeNumber>(ChangePokeNumber);

	switch (PokeDexNumber)
	{
	case PokeNumber::Bulbasaur:
	{
		BulbasaurData(_Level);

		PokeSkillInit(1, PokeSkill::Tackle);
		PokeSkillInit(2, PokeSkill::TailWhip);
		
		if (MonsterLevel >= 7)
		{
			PokeSkillInit(3, PokeSkill::LeechSeed);
		}
		else
		{
			SkillList[2] = nullptr;
		}
		if (MonsterLevel >= 9)
		{
			PokeSkillInit(4, PokeSkill::VineWhip);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Ivysaur:
	{
		IvysaurData(_Level);

		PokeSkillInit(1, PokeSkill::Tackle);
		PokeSkillInit(2, PokeSkill::TailWhip);

		if (MonsterLevel >= 7)
		{
			PokeSkillInit(3, PokeSkill::LeechSeed);
		}
		else
		{
			SkillList[2] = nullptr;
		}
		if (MonsterLevel >= 9)
		{
			PokeSkillInit(4, PokeSkill::VineWhip);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Venusaur:
	{
		VenusaurData(_Level);

		PokeSkillInit(1, PokeSkill::Tackle);
		PokeSkillInit(2, PokeSkill::TailWhip);

		if (MonsterLevel >= 7)
		{
			PokeSkillInit(3, PokeSkill::LeechSeed);
		}
		else
		{
			SkillList[2] = nullptr;
		}
		if (MonsterLevel >= 9)
		{
			PokeSkillInit(4, PokeSkill::VineWhip);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Charmander:
	{
		CharmanderData(_Level);

		PokeSkillInit(1, PokeSkill::Scratch);
		PokeSkillInit(2, PokeSkill::Growl);
		
		if (MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Ember);
		}
		else
		{
			SkillList[2] = nullptr;
		}
		if (MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::Leer);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Charmeleon:
	{
		CharmeleonData(_Level);

		PokeSkillInit(1, PokeSkill::Scratch);
		PokeSkillInit(2, PokeSkill::Growl);

		if (MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Ember);
		}
		else
		{
			SkillList[2] = nullptr;
		}
		if (MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::Leer);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Charizard:
	{
		CharizardData(_Level);

		PokeSkillInit(1, PokeSkill::Scratch);
		PokeSkillInit(2, PokeSkill::Growl);

		if (MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Ember);
		}
		else
		{
			SkillList[2] = nullptr;
		}
		if (MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::Leer);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Squirtle:
	{
		SquirtleData(_Level);

		PokeSkillInit(1, PokeSkill::Tackle);
		PokeSkillInit(2, PokeSkill::TailWhip);

		if (MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Bubble);
		}
		else
		{
			SkillList[2] = nullptr;
		}
		if (MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::WaterGun);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Wartortle:
	{
		WartortleData(_Level);

		PokeSkillInit(1, PokeSkill::Tackle);
		PokeSkillInit(2, PokeSkill::TailWhip);

		if (MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Bubble);
		}
		else
		{
			SkillList[2] = nullptr;
		}
		if (MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::WaterGun);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Blastoise:
	{
		BlastoiseData(_Level);

		PokeSkillInit(1, PokeSkill::Tackle);
		PokeSkillInit(2, PokeSkill::TailWhip);

		if (MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Bubble);
		}
		else
		{
			SkillList[2] = nullptr;
		}
		if (MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::WaterGun);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Pidgey:
	{
		PidgeyData(_Level);

		PokeSkillInit(1, PokeSkill::Tackle);
		PokeSkillInit(2, PokeSkill::SandAttack);

		if (MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::Gust);
		}
		else
		{
			SkillList[2] = nullptr;
		}
		if (MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::QuickAttack);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Rattata:
	{
		RattataData(_Level);

		PokeSkillInit(1, PokeSkill::Tackle);
		PokeSkillInit(2, PokeSkill::TailWhip);
		PokeSkillInit(3, PokeSkill::QuickAttack);

		if (MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::HyperFang);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Spearow:
	{
		SpearowData(_Level);

		PokeSkillInit(1, PokeSkill::Peck);
		PokeSkillInit(2, PokeSkill::Growl);
		PokeSkillInit(3, PokeSkill::Leer);

		if (MonsterLevel >= 9)
		{
			PokeSkillInit(4, PokeSkill::FuryAttack);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Geodude:
	{
		GeodudeData(_Level);

		PokeSkillInit(1, PokeSkill::Tackle);
		PokeSkillInit(2, PokeSkill::DefenseCurl);

		if (MonsterLevel >= 8)
		{
			PokeSkillInit(3, PokeSkill::RockPolish);
		}
		else
		{
			SkillList[2] = nullptr;
		}
		if (MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::RockThrow);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	case PokeNumber::Onix:
	{
		OnixData(_Level);

		PokeSkillInit(1, PokeSkill::Tackle);
		PokeSkillInit(2, PokeSkill::DefenseCurl);
		PokeSkillInit(3, PokeSkill::Bind);

		if (MonsterLevel >= 12)
		{
			PokeSkillInit(4, PokeSkill::RockThrow);
		}
		else
		{
			SkillList[3] = nullptr;
		}
	}
	break;
	default:
	break;
	}
}

//////////////////////////////////////////////////////////////// 푸키먼 전투

// 몬스터를 처치하면 경험치 획득
void PokeDataBase::PokeExperienceAcquisition(int _EXP)
{
	// 몬스터의 종류 확인
	// 몬스터의 레벨 확인
	// 획득 경험치 산출
	// 자신의 경험치에 추가
	Experience += _EXP;
}

// 일정 경험치 이상을 획득할 경우 레벨이 증가
void PokeDataBase::PokeLevelUp(int _EXP)
{
	int AcquiExperience = _EXP;
	int PlusExperience = Experience + _EXP;
	int ResidueExperience = PlusExperience - 100;

	if (PlusExperience >= 100)
	{
		MonsterLevel += 1;
		Experience = 0;
	}

	Experience += PlusExperience;
}

// 레벨업을 하면 체력, 공격력, 방어력, 특수공격력, 특수방어력, 민첩성이 증가
void PokeDataBase::PokeStatusUp()
{
	MaxHealthPoint += 1;
	AttackPower += 1;
	Defense += 1;
	SpecialAttackPower += 1;
	SpecialDefense += 1;
	Agility += 1;
}

//////////////////////////////////////////////////////////////// 푸키먼 데이터

// PokeCreate() 함수를 호출하면 해당 구역의 함수를 연계적으로 호출하여 데이터를 입력해줍니다.
// 데이터 생성 보조 함수와 푸키먼 데이터 함수가 있습니다.

// 푸키먼 스킬 이닛
void PokeDataBase::PokeSkillInit(int _Skillslot, PokeSkill _SkillName)
{
	PokeSkillBase* Skill = new PokeSkillBase();
	Skill->InitCreateSkill(_SkillName);

	SkillList[_Skillslot - 1] = Skill;
}

// 성별 결정
void PokeDataBase::GenderDecision()
{
	int RandValue = GameEngineRandom::MainRandom.RandomInt(1, 2);

	if (1 == RandValue)
	{
		IsMan = true;  // 수컷
	}
	else
	{
		IsMan = false; // 암컷
	}
}

// 성격 결정
void PokeDataBase::PersonalityDecision()
{
	int RandValue = GameEngineRandom::MainRandom.RandomInt(0, 24);

	Personality = static_cast<PokePersonality>(RandValue);

	// 오류로 인해 임시 반환 값
	// return PokePersonality::Adamant;
}

// 포켓몬 이름 수정
void PokeDataBase::PokeNameEdit(std::string _EditName)
{
	Name = _EditName;
}

// No.1 이상해씨
void PokeDataBase::BulbasaurData(int _Level)
{
	GenderDecision();                          // 성별 결정 (암, 수)
	PersonalityDecision();                     // 성격 결정 (신중한 등)
	Type = PokeType::Grass;                    // 포켓몬 타입 
	Characteristic = PokeCharacteristic::심록; // 포켓몬 특성
	Name = "Bulbasaur";                        // 포켓몬 디폴트 이름
	
	MaxHealthPoint = 45;                       // 포켓몬 기초 최대 체력
	CurrentHealthPoint = 45;                   // 포켓몬 기초 잔여 체력
	AttackPower = 49;                          // 포켓몬 기초 공격력
	Defense = 49;                              // 포켓몬 기초 방어력
	SpecialAttackPower = 65;                   // 포켓몬 기초 특수공격력
	SpecialDefense = 65;                       // 포켓몬 기초 특수방어력 // "특수"는 마법공격, 마법방어로, 노말은 물리공격, 물리방어로 생각하면 됩니다.
	Agility = 45;                              // 포켓몬 기초 스피드

	int PlusLevel = MonsterLevel + _Level;     // 야생 포켓몬 스폰 목적 시, 레벨을 입력해줍니다.

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.2 이상해풀
void PokeDataBase::IvysaurData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Grass;
	Characteristic = PokeCharacteristic::심록;
	Name = "Ivysaur";

	MaxHealthPoint = 60;
	CurrentHealthPoint = 60;
	AttackPower = 62;
	Defense = 63;
	SpecialAttackPower = 80;
	SpecialDefense = 80;
	Agility = 60;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}
// No.3 이상해꽃
void PokeDataBase::VenusaurData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Grass;
	Characteristic = PokeCharacteristic::심록;
	Name = "Venusaur";

	MaxHealthPoint = 80;
	CurrentHealthPoint = 80;
	AttackPower = 82;
	Defense = 83;
	SpecialAttackPower = 100;
	SpecialDefense = 100;
	Agility = 80;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.4 파이리
void PokeDataBase::CharmanderData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Fire;
	Characteristic = PokeCharacteristic::맹화;
	Name = "Charmander";

	MaxHealthPoint = 39;
	CurrentHealthPoint = 39;
	AttackPower = 52;
	Defense = 43;
	SpecialAttackPower = 60;
	SpecialDefense = 50;
	Agility = 65;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.5 리자드
void PokeDataBase::CharmeleonData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Fire;
	Characteristic = PokeCharacteristic::맹화;
	Name = "Charmeleon";

	MaxHealthPoint = 58;
	CurrentHealthPoint = 58;
	AttackPower = 64;
	Defense = 58;
	SpecialAttackPower = 80;
	SpecialDefense = 65;
	Agility = 80;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.6 리자몽
void PokeDataBase::CharizardData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Fire;
	Characteristic = PokeCharacteristic::맹화;
	Name = "Charizard";

	MaxHealthPoint = 78;
	CurrentHealthPoint = 78;
	AttackPower = 84;
	Defense = 78;
	SpecialAttackPower = 109;
	SpecialDefense = 85;
	Agility = 100;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.7 꼬부기
void PokeDataBase::SquirtleData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Water;
	Characteristic = PokeCharacteristic::급류;
	Name = "Squirtle";

	MaxHealthPoint = 44;
	CurrentHealthPoint = 44;
	AttackPower = 48;
	Defense = 65;
	SpecialAttackPower = 50;
	SpecialDefense = 64;
	Agility = 43;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.8 어니부기
void PokeDataBase::WartortleData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Water;
	Characteristic = PokeCharacteristic::급류;
	Name = "Wartortle";

	MaxHealthPoint = 59;
	CurrentHealthPoint = 59;
	AttackPower = 63;
	Defense = 80;
	SpecialAttackPower = 65;
	SpecialDefense = 80;
	Agility = 58;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.9 거북왕
void PokeDataBase::BlastoiseData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Water;
	Characteristic = PokeCharacteristic::급류;
	Name = "Blastoise";

	MaxHealthPoint = 79;
	CurrentHealthPoint = 79;
	AttackPower = 83;
	Defense = 100;
	SpecialAttackPower = 85;
	SpecialDefense = 105;
	Agility = 78;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.10 구구
void PokeDataBase::PidgeyData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Flying;
	Characteristic = PokeCharacteristic::날카로운눈;
	Name = "Pidgey";

	MaxHealthPoint = 40;
	CurrentHealthPoint = 40;
	AttackPower = 45;
	Defense = 40;
	SpecialAttackPower = 35;
	SpecialDefense = 35;
	Agility = 56;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.11 꼬렛
void PokeDataBase::RattataData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Normal;
	Characteristic = PokeCharacteristic::근성;
	Name = "Rattata";

	MaxHealthPoint = 30;
	CurrentHealthPoint = 30;
	AttackPower = 56;
	Defense = 35;
	SpecialAttackPower = 25;
	SpecialDefense = 35;
	Agility = 72;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.12 깨비참
void PokeDataBase::SpearowData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Flying;
	Characteristic = PokeCharacteristic::날카로운눈;
	Name = "Spearow";

	MaxHealthPoint = 40;
	CurrentHealthPoint = 40;
	AttackPower = 60;
	Defense = 30;
	SpecialAttackPower = 31;
	SpecialDefense = 31;
	Agility = 70;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.13 꼬마돌
void PokeDataBase::GeodudeData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Rock;
	Characteristic = PokeCharacteristic::돌머리;
	Name = "Geodude";

	MaxHealthPoint = 40;
	CurrentHealthPoint = 40;
	AttackPower = 80;
	Defense = 100;
	SpecialAttackPower = 30;
	SpecialDefense = 30;
	Agility = 20;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.14 롱스톤
void PokeDataBase::OnixData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Rock;
	Characteristic = PokeCharacteristic::돌머리;
	Name = "Onix";

	MaxHealthPoint = 35;
	CurrentHealthPoint = 35;
	AttackPower = 45;
	Defense = 160;
	SpecialAttackPower = 30;
	SpecialDefense = 45;
	Agility = 70;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}