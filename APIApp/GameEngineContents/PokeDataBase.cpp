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
		MsgAssert("���ϸ� �ѹ��� 14(�ս���)������ �����մϴ�.");
		return;
	}
	else if (ChangePokeNumber < 0)
	{
		MsgAssert("���ϸ� �ѹ��� 1(�̻��ؾ�) �̸��� �� �����ϴ�.");
		return;
	}

	if (_Level <= 0)
	{
		MsgAssert("������ 0�� ���ϸ��� ������ �� �����ϴ�.");
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
void PokeDataBase::PokeStatusUp()
{
	MaxHealthPoint += 1;
	AttackPower += 1;
	Defense += 1;
	SpecialAttackPower += 1;
	SpecialDefense += 1;
	Agility += 1;
}

//////////////////////////////////////////////////////////////// ǪŰ�� ������

// PokeCreate() �Լ��� ȣ���ϸ� �ش� ������ �Լ��� ���������� ȣ���Ͽ� �����͸� �Է����ݴϴ�.
// ������ ���� ���� �Լ��� ǪŰ�� ������ �Լ��� �ֽ��ϴ�.

// ǪŰ�� ��ų �̴�
void PokeDataBase::PokeSkillInit(int _Skillslot, PokeSkill _SkillName)
{
	PokeSkillBase* Skill = new PokeSkillBase();
	Skill->InitCreateSkill(_SkillName);

	SkillList[_Skillslot - 1] = Skill;
}

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

// No.1 �̻��ؾ�
void PokeDataBase::BulbasaurData(int _Level)
{
	GenderDecision();                          // ���� ���� (��, ��)
	PersonalityDecision();                     // ���� ���� (������ ��)
	Type = PokeType::Grass;                    // ���ϸ� Ÿ�� 
	Characteristic = PokeCharacteristic::�ɷ�; // ���ϸ� Ư��
	Name = "Bulbasaur";                        // ���ϸ� ����Ʈ �̸�
	
	MaxHealthPoint = 45;                       // ���ϸ� ���� �ִ� ü��
	CurrentHealthPoint = 45;                   // ���ϸ� ���� �ܿ� ü��
	AttackPower = 49;                          // ���ϸ� ���� ���ݷ�
	Defense = 49;                              // ���ϸ� ���� ����
	SpecialAttackPower = 65;                   // ���ϸ� ���� Ư�����ݷ�
	SpecialDefense = 65;                       // ���ϸ� ���� Ư������ // "Ư��"�� ��������, ��������, �븻�� ��������, �������� �����ϸ� �˴ϴ�.
	Agility = 45;                              // ���ϸ� ���� ���ǵ�

	int PlusLevel = MonsterLevel + _Level;     // �߻� ���ϸ� ���� ���� ��, ������ �Է����ݴϴ�.

	for (int i = 1; i < PlusLevel; i++)
	{
		PokeStatusUp();
	}

	MonsterLevel = PlusLevel;
}

// No.2 �̻���Ǯ
void PokeDataBase::IvysaurData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Grass;
	Characteristic = PokeCharacteristic::�ɷ�;
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
// No.3 �̻��ز�
void PokeDataBase::VenusaurData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Grass;
	Characteristic = PokeCharacteristic::�ɷ�;
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

// No.4 ���̸�
void PokeDataBase::CharmanderData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Fire;
	Characteristic = PokeCharacteristic::��ȭ;
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

// No.5 ���ڵ�
void PokeDataBase::CharmeleonData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Fire;
	Characteristic = PokeCharacteristic::��ȭ;
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

// No.6 ���ڸ�
void PokeDataBase::CharizardData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Fire;
	Characteristic = PokeCharacteristic::��ȭ;
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

// No.7 ���α�
void PokeDataBase::SquirtleData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Water;
	Characteristic = PokeCharacteristic::�޷�;
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

// No.8 ��Ϻα�
void PokeDataBase::WartortleData(int _Level)
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Water;
	Characteristic = PokeCharacteristic::�޷�;
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

// No.9 �źϿ�
void PokeDataBase::BlastoiseData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Water;
	Characteristic = PokeCharacteristic::�޷�;
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

// No.10 ����
void PokeDataBase::PidgeyData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Flying;
	Characteristic = PokeCharacteristic::��ī�ο;
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

// No.11 ����
void PokeDataBase::RattataData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Normal;
	Characteristic = PokeCharacteristic::�ټ�;
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

// No.12 ������
void PokeDataBase::SpearowData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Flying;
	Characteristic = PokeCharacteristic::��ī�ο;
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

// No.13 ������
void PokeDataBase::GeodudeData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Rock;
	Characteristic = PokeCharacteristic::���Ӹ�;
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

// No.14 �ս���
void PokeDataBase::OnixData(int _Level) 
{
	GenderDecision();
	PersonalityDecision();
	Type = PokeType::Rock;
	Characteristic = PokeCharacteristic::���Ӹ�;
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