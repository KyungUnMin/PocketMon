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
		MsgAssert("스킬은 1, 2, 3, 4번만 사용할 수 있습니다.");
		return;
	}

	// (데미지 = ((((((레벨 × 2 / 5) + 2) × 위력 × 특수공격 ÷ 50) ÷ 특수방어) × Mod1) × [[급소]] × Mod2) × 자속보정 × 타입상성1 × 타입상성2 × 랜덤수 ÷ 100)

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
		MsgAssert("1, 2, 3, 4번 중 Unknown이 아닌 스킬만 사용할 수 있습니다.");
		return -1;
	}

	float step1 = static_cast<float>(_Attacker->GetMonsterSkillList(_AttackerSkillNumber)->GetSkillDamage());
	//int step2 = _Attacker->GetPossessionItem();
	float step3 = OwnCharacteristiccalculation(_Attacker, _Attacker->GetMonsterCharacteristic());
	float step4 = OtherCharacteristiccalculation(_Defender, _Defender->GetMonsterCharacteristic());

	// 기술위력 × 도구보정 × 특성보정 × 상대특성보정
	float fDamageCal = step1 /** step2*/ * step3 * step4;

	int DamageCal = static_cast<int>(round(fDamageCal));

	return DamageCal;
}

float PokeBattleSystem::OwnCharacteristiccalculation(PokeDataBase* _Attacker, PokeCharacteristic _characteristic)
{
	switch (_characteristic)
	{
	case PokeCharacteristic::심록:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (Roundthird <= _Attacker->GetMonsterCurrentHP())
		{
			return 1.5f;
		}
	}
	break;
	case PokeCharacteristic::맹화:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (Roundthird <= _Attacker->GetMonsterCurrentHP())
		{
			return 1.5f;
		}
	}
	break;
	case PokeCharacteristic::급류:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (Roundthird <= _Attacker->GetMonsterCurrentHP())
		{
			return 1.5f;
		}
	}
	break;
	case PokeCharacteristic::근성:
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
	case PokeCharacteristic::심록:
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
	// 스탯 × [[특성]] 보정 × [[도구]] 보정
	float step1 = static_cast<float>(_Attacker->GetMonsterAttackPower());
	float step2 = OwnPersonalitycalculation(_Attacker->GetMonsterPersonality());
	float step3 = 1.0f; // 아이템 생성 시 0.0f로 수정

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
	// 스탯 × [[특성]] 보정 × [[도구]] 보정
	float step1 = static_cast<float>(_Attacker->GetMonsterSpecialAttackPower());
	float step2 = OwnPersonalitycalculation(_Attacker->GetMonsterPersonality());
	float step3 = 1.0f; // 아이템 생성 시 0.0f로 수정

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
	// 스탯 × [[특성]] 보정 × [[도구]] 보정
	float step1 = static_cast<float>(_Defender->GetMonsterSpecialAttackPower());
	float step2 = OtherPersonalitycalculation(_Defender->GetMonsterPersonality());
	float step3 = 1.0f; // 아이템 생성 시 0.0f로 수정

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