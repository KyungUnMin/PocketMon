#include "PokeBattleSystem.h"

#include <cmath>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>

#include "PokeDataBase.h"

int PokeBattleSystem::Damage = 0;
bool PokeBattleSystem::IsSpecial = false;

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

	float Cal1 = static_cast<int>((_Attacker->GetMonsterLevel() * 2 / 5) + 2);
	float Cal2 = Damagecalculator(_Attacker, _AttackerSkillNumber, _Defender);
	float Cal3 = 0;
	float Cal4 = 0;

	IsSpecial = _Attacker->GetMonsterSkillList(_AttackerSkillNumber)->ItisSpecialSkill();

	if (false == IsSpecial)
	{
		Cal3 = NormalAttackstatuscalculator(_Attacker);
		Cal4 = NormalDeffencestatuscalculator(_Defender);
	}
	else
	{
		Cal3 = SpecialAttackstatuscalculator(_Attacker);
		Cal4 = SpecialDeffencestatuscalculator(_Defender);
	}

	float Cal5 = CriticalRand();
	float Cal6 = Ownpropertiescorrection(_Attacker, _AttackerSkillNumber);
	float Cal7 = Compatibilitycorrection(_Attacker, _AttackerSkillNumber, _Defender);
	float Cal8 = Randomvalue();
	
	// 데미지 = (((레벨 × 2 / 5) + 2) × 위력 × 특수공격 ÷ 50) ÷ 특수방어) × [[급소]] × 자속보정 × 타입상성 × 랜덤수 ÷ 100
	// 모든 공식은 왼쪽에서 오른쪽 순서대로 계산하며, 각 계산을 실행하기 전에 소수점 이하를 버린다. 순서대로 계산하지 않으면 잘못된 결과가 나오므로 주의.
	// Damage = (((Cal1 * Cal2 * Cal3 / 50) / Cal4) * Cal5 * Cal6 * Cal7 * Cal8) / 100;

	float step1 = Cal1 * Cal2;
	float step2 = step1 * Cal3;
	float step3 = (step2 / 50) * Cal4;
	float step4 = step3 * Cal5;
	float step5 = step4 * Cal6;
	float step6 = step5 * Cal7;
	float step7 = step6 * Cal8;

	Damage = step7 / 100;

	_Defender->MinusMonsterCurrentHP(Damage);
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
	// 랜덤수 = ((217~255 사이의 랜덤한 수 x 100) / 255), 소수점 이하 버림, 즉 85~100 사이의 수가 나온다.

	int Rand = GameEngineRandom::MainRandom.RandomInt(217, 255);

	float Randv = ((Rand * 100) / 255);

	return Randv;
}

// 자속 보정
float PokeBattleSystem::Ownpropertiescorrection(PokeDataBase* _Attacker, int _AttackerSkillNumber)
{
	int Monstervalue = static_cast<int>(_Attacker->GetMonsterSkillList(_AttackerSkillNumber)->GetSkillType());
	int Monsterskillvalue = static_cast<int>(_Attacker->GetMonsterType());

	float correctionvalue = 0.0f;

	if (Monsterskillvalue == Monstervalue)
	{
		correctionvalue = 1.5f;
	}
	else
	{
		correctionvalue = 1.f;
	}

	return correctionvalue;
}

// 타입 상성
float PokeBattleSystem::Compatibilitycorrection(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender)
{
	int skillvalue = static_cast<int>(_Attacker->GetMonsterSkillList(_AttackerSkillNumber)->GetSkillType());
	int othervalue = static_cast<int>(_Defender->GetMonsterType());
	float correctionvalue = 0.0f;

	switch (skillvalue)
	{
	case 0: // 노말
	{
		switch (othervalue)
		{
		case 6:
			correctionvalue = 0.5f;
			break;
		default:
			correctionvalue = 1.f;
			break;
		}
	}
	break;
	case 2: // 비행
	{
		switch (othervalue)
		{
		case 6:
			correctionvalue = 0.5f;
			break;
		case 11:
			correctionvalue = 2.f;
			break;
		default:
			correctionvalue = 1.f;
			break;
		}
	}
	break;
	case 5: // 땅
	{
		switch (othervalue)
		{
		case 2:
			correctionvalue = 0.5f;
			break;
		case 6:
			correctionvalue = 2.f;
			break;
		case 9:
			correctionvalue = 2.f;
			break;
		case 11:
			correctionvalue = 0.5f;
			break;
		default:
			correctionvalue = 1.f;
			break;
		}
	}
	break;
	case 6: // 바위
	{
		switch (othervalue)
		{
		case 2:
			correctionvalue = 2.f;
			break;
		case 9:
			correctionvalue = 2.f;
			break;
		default:
			correctionvalue = 1.f;
			break;
		}
	}
	break;
	case 8: // 강철
	{
		switch (othervalue)
		{
		case 6:
			correctionvalue = 2.f;
			break;
		case 9:
			correctionvalue = 0.5f;
			break;
		case 10:
			correctionvalue = 0.5f;
			break;
		case 11:
			correctionvalue = 0.5f;
			break;
		default:
			correctionvalue = 1.f;
			break;
		}
	}
	break;
	case 9: // 불
	{
		switch (othervalue)
		{
		case 6:
			correctionvalue = 0.5f;
			break;
		case 9:
			correctionvalue = 0.5f;
			break;
		case 10:
			correctionvalue = 0.5f;
			break;
		case 11:
			correctionvalue = 2.f;
			break;
		default:
			correctionvalue = 1.f;
			break;
		}
	}
	break;
	case 10: // 물
	{
		switch (othervalue)
		{
		case 6:
			correctionvalue = 2.f;
			break;
		case 9:
			correctionvalue = 2.f;
			break;
		case 10:
			correctionvalue = 0.5f;
			break;
		case 11:
			correctionvalue = 0.5f;
			break;
		default:
			correctionvalue = 1.f;
			break;
		}
	}
	break;
	case 11: // 풀
	{
		switch (othervalue)
		{
		case 2:
			correctionvalue = 0.5f;
			break;
		case 6:
			correctionvalue = 2.f;
			break;
		case 9:
			correctionvalue = 0.5f;
			break;
		case 10:
			correctionvalue = 2.f;
			break;
		case 11:
			correctionvalue = 0.5f;
			break;
		default:
			correctionvalue = 1.f;
			break;
		}
	}
	break;
	default:
		correctionvalue = 1.f;
	break;
	}

	return correctionvalue;
}
