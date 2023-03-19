#include "PokeBattleSystem.h"

#include <cmath>
#include <GameEngineBase/GameEngineDebug.h>

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

	// (������ = ((((((���� �� 2 / 5) + 2) �� ���� �� Ư������ �� 50) �� Ư�����) �� Mod1) �� [[�޼�]] �� Mod2) �� �ڼӺ��� �� Ÿ�Ի�1 �� Ÿ�Ի�2 �� ������ �� 100)

	int step1 = _Attacker->GetMonsterLevel() * 2 / 5;
	int step2 = Damagecalculator(_Attacker, _AttackerSkillNumber, _Defender);
	int step3 = 0;
	int step4 = 0;

	IsSpecial = _Attacker->GetMonsterSkillList(_AttackerSkillNumber)->ItisSpecialSkill();

	if (false == IsSpecial)
	{
		step3 = NormalAttackstatuscalculator(_Attacker);
		step4 = NormalDeffencestatuscalculator(_Defender);
	}
	else
	{
		step3 = SpecialAttackstatuscalculator(_Attacker);
		step4 = SpecialDeffencestatuscalculator(_Defender);
	}
	

	Damage = step1 * step2;
}

int PokeBattleSystem::Damagecalculator(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender)
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
	float fDamageCal = step1 /** step2*/ * step3 * step4;

	int DamageCal = static_cast<int>(round(fDamageCal));

	return DamageCal;
}

float PokeBattleSystem::OwnCharacteristiccalculation(PokeDataBase* _Attacker, PokeCharacteristic _characteristic)
{
	switch (_characteristic)
	{
	case PokeCharacteristic::�ɷ�:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (Roundthird <= _Attacker->GetMonsterCurrentHP())
		{
			return 1.5f;
		}
	}
	break;
	case PokeCharacteristic::��ȭ:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (Roundthird <= _Attacker->GetMonsterCurrentHP())
		{
			return 1.5f;
		}
	}
	break;
	case PokeCharacteristic::�޷�:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (Roundthird <= _Attacker->GetMonsterCurrentHP())
		{
			return 1.5f;
		}
	}
	break;
	case PokeCharacteristic::�ټ�:
	{
		//if (true == _Attacker->IsAbnormalStatus())
		//{
		//	return 1.5f;
		//}
		//else
		//{
		//	return 1.f;
		//}
		return 1.f;
	}
	break;
	default:
	{
		return 1.f;
	}
	break;
	}
}

float PokeBattleSystem::OtherCharacteristiccalculation(PokeDataBase* _Defender, PokeCharacteristic _characteristic)
{
	switch (_characteristic)
	{
	case PokeCharacteristic::�ɷ�:
	{
		return 1.f;
	}
	break;
	default:
	{
		return 1.f;
	}
	break;
	}
}

int PokeBattleSystem::NormalAttackstatuscalculator(PokeDataBase* _Attacker)
{
	// ���� �� [[Ư��]] ���� �� [[����]] ����
	float step1 = static_cast<float>(_Attacker->GetMonsterAttackPower());
	float step2 = OwnPersonalitycalculation(_Attacker->GetMonsterPersonality());
	float step3 = 1.0f; // ������ ���� �� 0.0f�� ����

	//if (true == _Attacker->GetPossessionItem())
	//{
	//	step2 = 1.1f;
	//}
	//else
	//{
	//	step2 = 1.0f;
	//}
	
	float fDamageCal = step1 * step2 /** step3*/;

	int DamageCal = static_cast<int>(round(fDamageCal));

	return DamageCal;
}

int PokeBattleSystem::SpecialAttackstatuscalculator(PokeDataBase* _Attacker)
{
	// ���� �� [[Ư��]] ���� �� [[����]] ����
	float step1 = static_cast<float>(_Attacker->GetMonsterSpecialAttackPower());
	float step2 = OwnPersonalitycalculation(_Attacker->GetMonsterPersonality());
	float step3 = 1.0f; // ������ ���� �� 0.0f�� ����

	//if (true == _Attacker->GetPossessionItem())
	//{
	//	step2 = 1.1f;
	//}
	//else
	//{
	//	step2 = 1.0f;
	//}

	float fDamageCal = step1 * step2 /** step3*/;

	int DamageCal = static_cast<int>(round(fDamageCal));

	return DamageCal;
}

int PokeBattleSystem::NormalDeffencestatuscalculator(PokeDataBase* _Defender)
{
	// ���� �� [[Ư��]] ���� �� [[����]] ����
	float step1 = static_cast<float>(_Defender->GetMonsterSpecialAttackPower());
	float step2 = OtherPersonalitycalculation(_Defender->GetMonsterPersonality());
	float step3 = 1.0f; // ������ ���� �� 0.0f�� ����

	//if (true == _Attacker->GetPossessionItem())
	//{
	//	step2 = 1.1f;
	//}
	//else
	//{
	//	step2 = 1.0f;
	//}

	float fDamageCal = step1 /** step2*/;

	int DamageCal = static_cast<int>(round(fDamageCal));

	return DamageCal;
}

int SpecialDeffencestatuscalculator(PokeDataBase* _Defender)
{
	return -1;
}

float PokeBattleSystem::OwnPersonalitycalculation(PokePersonality _personality)
{
	switch (_personality)
	{
	case PokePersonality::Lonely:
		return 1.1f;
		break;
	case PokePersonality::Adamant:
		return 1.1f;
		break;
	case PokePersonality::Naughty:
		return 1.1f;
		break;
	case PokePersonality::Brave:
		return 1.1f;
		break;
	case PokePersonality::Bold:
		break;
	case PokePersonality::Impish:
		break;
	case PokePersonality::Lax:
		break;
	case PokePersonality::Relaxed:
		break;
	case PokePersonality::Modest:
		break;
	case PokePersonality::Mild:
		break;
	case PokePersonality::Rash:
		break;
	case PokePersonality::Quiet:
		break;
	case PokePersonality::Calm:
		break;
	case PokePersonality::Gentle:
		break;
	case PokePersonality::Careful:
		break;
	case PokePersonality::Sassy:
		break;
	case PokePersonality::Timid:
		break;
	case PokePersonality::Hasty:
		break;
	case PokePersonality::Jolly:
		break;
	case PokePersonality::Naive:
		break;
	case PokePersonality::Bashful:
		break;
	case PokePersonality::Hardy:
		break;
	case PokePersonality::Docile:
		break;
	case PokePersonality::Quirky:
		break;
	case PokePersonality::Serious:
		break;
	default:
		break;
	}
}

float PokeBattleSystem::OtherPersonalitycalculation(PokePersonality _personality)
{
	switch (_personality)
	{
	case PokePersonality::Lonely:
		return 1.1f;
		break;
	case PokePersonality::Adamant:
		break;
	case PokePersonality::Naughty:
		break;
	case PokePersonality::Brave:
		break;
	case PokePersonality::Bold:
		break;
	case PokePersonality::Impish:
		break;
	case PokePersonality::Lax:
		break;
	case PokePersonality::Relaxed:
		break;
	case PokePersonality::Modest:
		break;
	case PokePersonality::Mild:
		break;
	case PokePersonality::Rash:
		break;
	case PokePersonality::Quiet:
		break;
	case PokePersonality::Calm:
		break;
	case PokePersonality::Gentle:
		break;
	case PokePersonality::Careful:
		break;
	case PokePersonality::Sassy:
		break;
	case PokePersonality::Timid:
		break;
	case PokePersonality::Hasty:
		break;
	case PokePersonality::Jolly:
		break;
	case PokePersonality::Naive:
		break;
	case PokePersonality::Bashful:
		break;
	case PokePersonality::Hardy:
		break;
	case PokePersonality::Docile:
		break;
	case PokePersonality::Quirky:
		break;
	case PokePersonality::Serious:
		break;
	default:
		break;
	}
}

void PokeBattleSystem::Ownpropertiescorrection()
{

}
void PokeBattleSystem::Compatibilitycorrection()
{

}
void PokeBattleSystem::Randomvalue()
{

}