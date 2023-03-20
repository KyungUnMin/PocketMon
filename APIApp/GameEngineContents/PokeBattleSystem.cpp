#include "PokeBattleSystem.h"

#include <cmath>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>

#include "PokeDataBase.h"

PokeBattleSystem::PokeBattleSystem() 
{
}

PokeBattleSystem::~PokeBattleSystem() 
{
}

void PokeBattleSystem::Battle(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender)
{
	if (_AttackerSkillNumber > 4 || _AttackerSkillNumber <= 0)
	{
		MsgAssert("��ų�� 1, 2, 3, 4���� ����� �� �ֽ��ϴ�.");
		return;
	}

	// ������ = (((���� �� 2 / 5) + 2) �� ���� �� Ư������ �� 50) �� Ư�����) �� [[�޼�]] �� �ڼӺ��� �� Ÿ�Ի� �� ������ �� 100

	int step1 = (_Attacker->GetMonsterLevel() * 2 / 5) + 2;
	float step2 = Damagecalculator(_Attacker, _AttackerSkillNumber, _Defender);
	float step3 = 0;
	float step4 = 0;

	IsSpecial = _Attacker->GetMonsterSkillList(_AttackerSkillNumber)->ItisSpecialSkill();

	if (false == IsSpecial)
	{
		step3 = NormalAttackstatuscalculator(_Attacker) / 50;
		step4 = NormalDeffencestatuscalculator(_Defender);
	}
	else
	{
		step3 = SpecialAttackstatuscalculator(_Attacker) / 50;
		step4 = SpecialDeffencestatuscalculator(_Defender);
	}

	float step5 = CriticalRand();
	float step6 = 0.0f; // �ڼӺ���
	float step7 = 0.0f; // Ÿ�Ի�
	float step8 = Randomvalue();
	
	// Damage = ((step1 * static_cast<int>(round(step2)) * static_cast<int>(round(step3)) / static_cast<int>(round(step4)) ;
}

float PokeBattleSystem::Damagecalculator(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender)
{
	if (PokeSkill::Unknown == _Attacker->GetMonsterSkillList(_AttackerSkillNumber)->GetSkill())
	{
		MsgAssert("1, 2, 3, 4�� �� Unknown�� �ƴ� ��ų�� ����� �� �ֽ��ϴ�.");
		return -1;
	}

	float step1 = static_cast<float>(_Attacker->GetMonsterSkillList(_AttackerSkillNumber)->GetSkillDamage());
	//int step2 = _Attacker->GetPossessionItem();
	float step3 = OwnCharacteristiccalculation(_Attacker, _Attacker->GetMonsterCharacteristic());
	float step4 = OtherCharacteristiccalculation(_Defender, _Defender->GetMonsterCharacteristic());

	// ������� �� �������� �� Ư������ �� ���Ư������
	float DamageCal = step1 /** step2*/ * step3 * step4;

	return DamageCal;
}

float PokeBattleSystem::OwnCharacteristiccalculation(PokeDataBase* _Attacker, PokeCharacteristic _characteristic)
{
	float CharDamage = 0.0f;

	switch (_characteristic)
	{
	case PokeCharacteristic::�ɷ�:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (static_cast<int>(Roundthird) <= _Attacker->GetMonsterCurrentHP())
		{
			CharDamage = 1.5f;
		}
	}
	break;
	case PokeCharacteristic::��ȭ:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (static_cast<int>(Roundthird) <= _Attacker->GetMonsterCurrentHP())
		{
			CharDamage = 1.5f;
		}
	}
	break;
	case PokeCharacteristic::�޷�:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (static_cast<int>(Roundthird) <= _Attacker->GetMonsterCurrentHP())
		{
			CharDamage = 1.5f;
		}
	}
	break;
	case PokeCharacteristic::�ټ�:
	{
		//if (true == _Attacker->IsAbnormalStatus())
		//{
		//	Damage = 1.f;
		//}
		//else
		//{
		//	Damage = 1.f;
		//}
		CharDamage = 1.f;
	}
	break;
	default:
	{
		CharDamage = 1.f;
	}
	break;
	}

	return CharDamage;
}

float PokeBattleSystem::OtherCharacteristiccalculation(PokeDataBase* _Defender, PokeCharacteristic _characteristic)
{
	float CharDamage = 0.0f;

	switch (_characteristic)
	{
	case PokeCharacteristic::�ɷ�:
	{
		CharDamage = 1.f;
	}
	break;
	default:
	{
		CharDamage = 1.f;
	}
	break;
	}

	return CharDamage;
}

// �븻 ���� ������ ���
float PokeBattleSystem::NormalAttackstatuscalculator(PokeDataBase* _Attacker)
{
	// ���� �� [[Ư��]] ���� �� [[����]] ����
	float step1 = static_cast<float>(_Attacker->GetMonsterAttackPower());
	float step2 = OwnPersonalitycalculation_NA(_Attacker->GetMonsterPersonality()); // ���ݿ� ���� �� ��ȭ
	float step3 = 1.0f; // ������ ���� �� 0.0f�� ����

	//if (true == _Attacker->GetPossessionItem())
	//{
	//	step2 = 1.1f;
	//}
	//else
	//{
	//	step2 = 1.0f;
	//}
	
	float DamageCal = step1 * step2 /** step3*/;

	return DamageCal;
}

// Ư�� ���� ������ ���
float PokeBattleSystem::SpecialAttackstatuscalculator(PokeDataBase* _Attacker)
{
	// ���� �� [[Ư��]] ���� �� [[����]] ����
	float step1 = static_cast<float>(_Attacker->GetMonsterSpecialAttackPower());
	float step2 = OwnPersonalitycalculation_SA(_Attacker->GetMonsterPersonality());
	float step3 = 1.0f; // ������ ���� �� 0.0f�� ����

	//if (true == _Attacker->GetPossessionItem())
	//{
	//	step2 = 1.1f;
	//}
	//else
	//{
	//	step2 = 1.0f;
	//}

	float DamageCal = step1 * step2 /** step3*/;

	return DamageCal;
}

// �븻 ��� ������ �Ի�(���)
float PokeBattleSystem::NormalDeffencestatuscalculator(PokeDataBase* _Defender)
{
	// ���� �� [[Ư��]] ���� �� [[����]] ����
	float step1 = static_cast<float>(_Defender->GetMonsterSpecialAttackPower());
	float step2 = OtherPersonalitycalculation_ND(_Defender->GetMonsterPersonality());
	float step3 = 1.0f; // ������ ���� �� 0.0f�� ����

	//if (true == _Attacker->GetPossessionItem())
	//{
	//	step2 = 1.1f;
	//}
	//else
	//{
	//	step2 = 1.0f;
	//}

	float DamageCal = step1 * step2 /** step3*/;

	return DamageCal;
}

// Ư�� ��� ������ �Ի�(���)
float PokeBattleSystem::SpecialDeffencestatuscalculator(PokeDataBase* _Defender)
{
	// ���� �� [[Ư��]] ���� �� [[����]] ����
	float step1 = static_cast<float>(_Defender->GetMonsterSpecialAttackPower());
	float step2 = OtherPersonalitycalculation_SD(_Defender->GetMonsterPersonality());
	float step3 = 1.0f; // ������ ���� �� 0.0f�� ����

	//if (true == _Attacker->GetPossessionItem())
	//{
	//	step2 = 1.1f;
	//}
	//else
	//{
	//	step2 = 1.0f;
	//}

	float DamageCal = step1 * step2 /** step3*/;

	return DamageCal;
}

// �ڽ��� ���ݿ� ���� ������ ���� (�븻)
float PokeBattleSystem::OwnPersonalitycalculation_NA(PokePersonality _personality)
{
	float CharDamage = 0.0f;

	switch (_personality)
	{
	case PokePersonality::Lonely:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Adamant:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Naughty:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Brave:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Bold:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Modest:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Calm:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Timid:
		CharDamage = 0.9f;
		break;
	default:
		CharDamage = 1.0f;
		break;
	}

	return CharDamage;
}

// �ڽ��� ���ݿ� ���� ������ ���� (Ư��)
float PokeBattleSystem::OwnPersonalitycalculation_SA(PokePersonality _personality)
{
	float CharDamage = 0.0f;

	switch (_personality)
	{
	case PokePersonality::Adamant:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Impish:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Modest:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Mild:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Rash:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Quiet:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Careful:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Jolly:
		CharDamage = 0.9f;
		break;
	default:
		CharDamage = 1.f;
		break;
	}

	return CharDamage;
}

// ��� ���ݿ� ���� ������ ���� (�븻)
float PokeBattleSystem::OtherPersonalitycalculation_ND(PokePersonality _personality)
{
	float CharDamage = 0.0f;

	switch (_personality)
	{
	case PokePersonality::Lonely:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Bold:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Impish:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Lax:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Relaxed:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Mild:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Gentle:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Hasty:
		CharDamage = 0.9f;
		break;
	default:
		CharDamage = 1.f;
		break;
	}

	return CharDamage;
}

// ��� ���ݿ� ���� ������ ���� (Ư��)
float PokeBattleSystem::OtherPersonalitycalculation_SD(PokePersonality _personality)
{
	float CharDamage = 0.0f;

	switch (_personality)
	{
	case PokePersonality::Naughty:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Lax:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Rash:
		CharDamage = 0.9f;
		break;
	case PokePersonality::Calm:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Gentle:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Careful:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Sassy:
		CharDamage = 1.1f;
		break;
	case PokePersonality::Naive:
		CharDamage = 0.9f;
		break;
	default:
		CharDamage = 1.f;
		break;
	}

	return CharDamage;
}

float PokeBattleSystem::CriticalRand()
{
	int Rand = GameEngineRandom::MainRandom.RandomInt(1, 10);
	
	float Criticalvalue = 0.0f;

	if (1 == Rand)
	{
		Criticalvalue = 1.5f;
	}
	else
	{
		Criticalvalue = 1.0f;
	}

	return Criticalvalue;
}

float PokeBattleSystem::Randomvalue()
{
	// ������ = ((217~255 ������ ������ �� x 100) / 255), �Ҽ��� ���� ����, �� 85~100 ������ ���� ���´�.

	int Rand = GameEngineRandom::MainRandom.RandomInt(217, 255);

	float Randv = ((Rand * 100) / 255);

	return Randv;
}

void PokeBattleSystem::Ownpropertiescorrection()
{

}
void PokeBattleSystem::Compatibilitycorrection()
{

}
