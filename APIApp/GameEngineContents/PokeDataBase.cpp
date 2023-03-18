#include "PokeDataBase.h"

#include <GameEngineBase/GameEngineRandom.h>

#include "PokeSkillBase.h"

PokeDataBase::PokeDataBase() 
{
}

PokeDataBase::~PokeDataBase() 
{
}

void PokeDataBase::PokeCreate(int _PokeDexNumber, int _Level)
{
	int ChangePokeNumber = 0;
	
	ChangePokeNumber = _PokeDexNumber - 1;

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

//////////////////////////////////////////////////////////////// ǪŰ�� ����

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
void PokeDataBase::PokeStatusUp(int _Status)
{
	HealthPoint += _Status;
	AttackPower += _Status;
	Defense += _Status;
	SpecialAttackPower += _Status;
	SpecialDefense += _Status;
	Agility += _Status;
}

//////////////////////////////////////////////////////////////// ǪŰ�� ������ ���� ����

// ���� ����
void PokeDataBase::GenderDecision()
{
	int RandValue = GameEngineRandom::MainRandom.RandomInt(1, 2);

	if (1 == RandValue)
	{
		IsMan = true;  // ����
	}
	else
	{
		IsMan = false; // ����
	}
}

// ���� ����
void PokeDataBase::PersonalityDecision()
{
	int RandValue = GameEngineRandom::MainRandom.RandomInt(0, 24);

	Personality = static_cast<PokePersonality>(RandValue);

	// ������ ���� �ӽ� ��ȯ ��
	// return PokePersonality::Adamant;
}

// ���ϸ� �̸� ����
void PokeDataBase::PokeNameEdit(std::string _EditName)
{
	Name = _EditName;
}

//////////////////////////////////////////////////////////////// ǪŰ�� ������

void PokeDataBase::BulbasaurData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Grass;
	Characteristic = PokeCharacteristic::�ɷ�;
	Name = "Bulbasaur";
	
	HealthPoint = 20;
	AttackPower = 15;
	Defense = 15;
	SpecialAttackPower = 15;
	SpecialDefense = 15;
	Agility = 15;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(1);
	}

	MonsterLevel = PlusLevel;

	// ��ų �ο�
	SkillList[0]->CreateSkill("�����ġ��");
	// SkillList[1].~ = "�����Ҹ�";
	// SkillList[2].~ = "�ٳ�����";
}

void PokeDataBase::CharmanderData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Fire;
	Characteristic = PokeCharacteristic::��ȭ;
	Name = "Charmander";

	HealthPoint = 25;
	AttackPower = 12;
	Defense = 12;
	SpecialAttackPower = 12;
	SpecialDefense = 12;
	Agility = 12;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(2);
	}

	MonsterLevel = PlusLevel;

	// ��ų�ο�
	// SkillList[0].~ = "�����ġ��";
	// SkillList[1].~ = "�����Ҹ�";
	// SkillList[2].~ = "�Ҳɼ���";
}

void PokeDataBase::SquirtleData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Water;
	Characteristic = PokeCharacteristic::�޷�;
	Name = "Squirtle";

	HealthPoint = 30;
	AttackPower = 10;
	Defense = 10;
	SpecialAttackPower = 10;
	SpecialDefense = 10;
	Agility = 10;

	int PlusLevel = MonsterLevel + _Level;

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp(3);
	}

	MonsterLevel = PlusLevel;

	// ��ų�ο�
	// SkillList[0].~ = "�����ġ��";
	// SkillList[1].~ = "�����Ҹ�";
	// SkillList[2].~ = "������";
}