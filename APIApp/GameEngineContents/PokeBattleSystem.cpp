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
		MsgAssert("스킬은 1, 2, 3, 4번만 사용할 수 있습니다.");
		return;
	}

	// (데미지 = ((((((레벨 × 2 / 5) + 2) × 위력 × 특수공격 ÷ 50) ÷ 특수방어) × Mod1) × [[급소]] × Mod2) × 자속보정 × 타입상성1 × 타입상성2 × 랜덤수 ÷ 100)

	int step1 = _Attacker->GetMonsterLevel() * 2 / 5;
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
	
	// Damage = ((step1 * static_cast<int>(round(step2)) * static_cast<int>(round(step3)) / static_cast<int>(round(step4)) ;
}

float PokeBattleSystem::Damagecalculator(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender)
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
	float DamageCal = step1 /** step2*/ * step3 * step4;

	return DamageCal;
}

float PokeBattleSystem::OwnCharacteristiccalculation(PokeDataBase* _Attacker, PokeCharacteristic _characteristic)
{
	float CharDamage = 0.0f;

	switch (_characteristic)
	{
	case PokeCharacteristic::심록:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (static_cast<int>(Roundthird) <= _Attacker->GetMonsterCurrentHP())
		{
			CharDamage = 1.5f;
		}
	}
	break;
	case PokeCharacteristic::맹화:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (static_cast<int>(Roundthird) <= _Attacker->GetMonsterCurrentHP())
		{
			CharDamage = 1.5f;
		}
	}
	break;
	case PokeCharacteristic::급류:
	{
		float third = static_cast<float>(_Attacker->GetMonsterMaxHP() / 3);
		float Roundthird = round(third);
		if (static_cast<int>(Roundthird) <= _Attacker->GetMonsterCurrentHP())
		{
			CharDamage = 1.5f;
		}
	}
	break;
	case PokeCharacteristic::근성:
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
	case PokeCharacteristic::심록:
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

// 노말 공격 데미지 계산
float PokeBattleSystem::NormalAttackstatuscalculator(PokeDataBase* _Attacker)
{
	// 스탯 × [[특성]] 보정 × [[도구]] 보정
	float step1 = static_cast<float>(_Attacker->GetMonsterAttackPower());
	float step2 = OwnPersonalitycalculation_NA(_Attacker->GetMonsterPersonality()); // 성격에 따른 값 변화
	float step3 = 1.0f; // 아이템 생성 시 0.0f로 수정

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

// 특수 공격 데미지 계산
float PokeBattleSystem::SpecialAttackstatuscalculator(PokeDataBase* _Attacker)
{
	// 스탯 × [[특성]] 보정 × [[도구]] 보정
	float step1 = static_cast<float>(_Attacker->GetMonsterSpecialAttackPower());
	float step2 = OwnPersonalitycalculation_SA(_Attacker->GetMonsterPersonality());
	float step3 = 1.0f; // 아이템 생성 시 0.0f로 수정

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

// 노말 방어 데미지 게산(상대)
float PokeBattleSystem::NormalDeffencestatuscalculator(PokeDataBase* _Defender)
{
	// 스탯 × [[특성]] 보정 × [[도구]] 보정
	float step1 = static_cast<float>(_Defender->GetMonsterSpecialAttackPower());
	float step2 = OtherPersonalitycalculation_ND(_Defender->GetMonsterPersonality());
	float step3 = 1.0f; // 아이템 생성 시 0.0f로 수정

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

// 특수 방어 데미지 게산(상대)
float PokeBattleSystem::SpecialDeffencestatuscalculator(PokeDataBase* _Defender)
{
	// 스탯 × [[특성]] 보정 × [[도구]] 보정
	float step1 = static_cast<float>(_Defender->GetMonsterSpecialAttackPower());
	float step2 = OtherPersonalitycalculation_SD(_Defender->GetMonsterPersonality());
	float step3 = 1.0f; // 아이템 생성 시 0.0f로 수정

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

// 자신의 성격에 따른 데미지 조정 (노말)
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

// 자신의 성격에 따른 데미지 조정 (특수)
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

// 상대 성격에 따른 데미지 조정 (노말)
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

// 상대 성격에 따른 데미지 조정 (특수)
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
	int Randomvalue = GameEngineRandom::MainRandom.RandomInt(1, 10);
	
	float Criticalvalue = 0.0f;

	if (1 == Randomvalue)
	{
		Criticalvalue = 1.5f;
	}
	else
	{
		Criticalvalue = 1.0f;
	}

	return Criticalvalue;
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