#include "PokeDataBase.h"

#include <GameEngineBase/GameEngineRandom.h>

PokeDataBase::PokeDataBase() 
{
}

PokeDataBase::~PokeDataBase() 
{
}

void PokeDataBase::PokeCreate(PokeNumber _Number, int _Level)
{
	int ChangePokeNumber = 0;
	ChangePokeNumber = static_cast<int>(_Number) - 1;

	PokeDexNumber = static_cast<PokeNumber>(ChangePokeNumber);

	switch (PokeDexNumber)
	{
	case PokeNumber::Bulbasaur:
		BulbasaurData(_Level);
		break;
	case PokeNumber::Ivysaur:
		break;
	case PokeNumber::Venusaur:
		break;
	case PokeNumber::Charmander:
		CharmanderData(_Level);
		break;
	case PokeNumber::Charmeleon:
		break;
	case PokeNumber::Charizard:
		break;
	case PokeNumber::Squirtle:
		SquirtleData(_Level);
		break;
	case PokeNumber::Wartortle:
		break;
	case PokeNumber::Blastoise:
		break;
	case PokeNumber::Max:
		break;
	default:
		break;
	}
}

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
void PokeDataBase::PokeStatusUp(int _Status)
{
	HealthPoint += _Status;
	AttackPower += _Status;
	Defense += _Status;
	SpecialAttackPower += _Status;
	SpecialDefense += _Status;
	Agility += _Status;
}

// 진화 조건을 충족 시 몬스터 진화
void PokeDataBase::PokeEvolution()
{
	// 파이리의 레벨이 10이면 진화 물어봄
}

// 스킬 습득 조건을 충족 시 새로운 스킬 획득
void PokeDataBase::PokeSkillAcquisition()
{
	// 파이리의 레벨이 몇 일때 무슨 스킬을 획득 가능
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
PokePersonality PokeDataBase::PersonalityDecision()
{
	int RandValue = GameEngineRandom::MainRandom.RandomInt(0, 24);

	Personality = static_cast<PokePersonality>(RandValue);
}

//////////////////////////////////////////////////////////////// 푸키먼

void PokeDataBase::BulbasaurData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Grass;
	Characteristic = PokeCharacteristic::심록;
	PokeDexNumber = PokeNumber::Bulbasaur;
	
	HealthPoint = 20;
	AttackPower = 15;
	Defense = 15;
	SpecialAttackPower = 15;
	SpecialDefense = 15;
	Agility = 15;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 0; i < PlusLevel; i++)
	{
		PokeStatusUp(1);
	}

	// 스킬 부여
	// SkillList[0].~ = "몸통박치기";
	// SkillList[1].~ = "울음소리";
	// SkillList[2].~ = "잎날리기";
}

void PokeDataBase::CharmanderData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Fire;
	Characteristic = PokeCharacteristic::맹화;
	PokeDexNumber = PokeNumber::Charmander;

	HealthPoint = 25;
	AttackPower = 12;
	Defense = 12;
	SpecialAttackPower = 12;
	SpecialDefense = 12;
	Agility = 12;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 0; i < PlusLevel; i++)
	{
		PokeStatusUp(2);
	}

	// 스킬부여
	// SkillList[0].~ = "몸통박치기";
	// SkillList[1].~ = "울음소리";
	// SkillList[2].~ = "불꽃세례";
}

void PokeDataBase::SquirtleData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Water;
	Characteristic = PokeCharacteristic::급류;
	PokeDexNumber = PokeNumber::Squirtle;

	HealthPoint = 30;
	AttackPower = 10;
	Defense = 10;
	SpecialAttackPower = 10;
	SpecialDefense = 10;
	Agility = 10;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 0; i < PlusLevel; i++)
	{
		PokeStatusUp(3);
	}

	// 스킬부여
	// SkillList[0].~ = "몸통박치기";
	// SkillList[1].~ = "울음소리";
	// SkillList[2].~ = "물대포";
}