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

// ���͸� óġ�ϸ� ����ġ ȹ��
void PokeDataBase::PokeExperienceAcquisition(int _EXP)
{
	// ������ ���� Ȯ��
	// ������ ���� Ȯ��
	// ȹ�� ����ġ ����
	// �ڽ��� ����ġ�� �߰�
	Experience += _EXP;
}

// ���� ����ġ �̻��� ȹ���� ��� ������ ����
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

// �������� �ϸ� ü��, ���ݷ�, ����, Ư�����ݷ�, Ư������, ��ø���� ����
void PokeDataBase::PokeStatusUp()
{
	HealthPoint += 1;                       
	AttackPower += 1;                       
	Defense += 1;                           
	SpecialAttackPower += 1;                
	SpecialDefense += 1;                    
	Agility += 1;                           
}

// ��ȭ ������ ���� �� ���� ��ȭ
void PokeDataBase::PokeEvolution()
{
	// ���̸��� ������ 10�̸� ��ȭ ���
}

// ��ų ���� ������ ���� �� ���ο� ��ų ȹ��
void PokeDataBase::PokeSkillAcquisition()
{
	// ���̸��� ������ �� �϶� ���� ��ų�� ȹ�� ����
}