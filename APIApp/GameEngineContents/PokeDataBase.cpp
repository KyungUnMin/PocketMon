#include "PokeDataBase.h"

PokeDataBase::PokeDataBase() 
{
}

PokeDataBase::~PokeDataBase() 
{
}

void PokeDataBase::PokeCreate()
{
	
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
void PokeDataBase::PokeStatusUp()
{
	HealthPoint += 1;                       
	AttackPower += 1;                       
	Defense += 1;                           
	SpecialAttackPower += 1;                
	SpecialDefense += 1;                    
	Agility += 1;                           
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