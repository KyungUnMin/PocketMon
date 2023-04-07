#include "PokeBattleSystem.h"

#include <cmath>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>

#include "PokeDataBase.h"
#include "ContentsEnum.h"

int PokeBattleSystem::Damage = 0;
bool PokeBattleSystem::IsSpecial = false;
bool PokeBattleSystem::IsAttack = false;
BattleScript PokeBattleSystem::ScriptValue = BattleScript::Nothing;

PokeBattleSystem::PokeBattleSystem() 
{
}

PokeBattleSystem::~PokeBattleSystem() 
{
}

BattleScript PokeBattleSystem::Battle(PokeDataBase& _Attacker, int _AttackerSkillNumber, PokeDataBase& _Defender)
{
	Damage = 0;
	IsSpecial = false;
	IsAttack = false;
	ScriptValue = BattleScript::Nothing;

    if (_AttackerSkillNumber > 4 || _AttackerSkillNumber <= 0)
	{
		MsgAssert("스킬은 1, 2, 3, 4번만 사용할 수 있습니다.");
		return ScriptValue;
	}

	IsAttack = _Attacker.GetMonsterSkillList(_AttackerSkillNumber).ItisAttackSkill();

	bool Start = _Attacker.GetMonsterSkillList(_AttackerSkillNumber).IsPowerPointZero();

	if (true == Start)
	{
		ScriptValue = BattleScript::PPiszero;
	}
	else
	{
		_Attacker.GetMonsterSkillList(_AttackerSkillNumber).MinusPowerPoint();

		if (true == IsAttack)
		{
			float Cal1 = (_Attacker.GetMonsterLevel_float() * 2 / 5) + 2;
			float Cal2 = Damagecalculator(_Attacker, _AttackerSkillNumber, _Defender);
			float Cal3 = 0;
			float Cal4 = 0;

			IsSpecial = _Attacker.GetMonsterSkillList(_AttackerSkillNumber).ItisSpecialSkill();

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
			float step3 = (step2 / 50) / Cal4;
			float step4 = step3 * Cal5;
			float step5 = step4 * Cal6;
			float step6 = step5 * Cal7;
			float step7 = step6 * Cal8;

			Damage = std::max<int>(1, static_cast<int>(round(step7 / 50)));

			_Defender.MinusMonsterCurrentHP(Damage);

			if (0 >= _Defender.GetMonsterCurrentHP())
			{
				_Defender.SetMonsterCurrentHP(0);
				_Defender.Stern();

				ScriptValue = BattleScript::Stern;
			}

		}
		else
		{
			ScriptValue = BattleScript::Buff;

			Bufflogic(_Attacker, _AttackerSkillNumber, _Defender);
		}
	}

	return ScriptValue;
}

float PokeBattleSystem::Damagecalculator(PokeDataBase& _Attacker, int _AttackerSkillNumber, PokeDataBase& _Defender)
{
	if (PokeSkill::Unknown == _Attacker.GetMonsterSkillList(_AttackerSkillNumber).GetSkill())
	{
		MsgAssert("1, 2, 3, 4번 중 Unknown이 아닌 스킬만 사용할 수 있습니다.");
		return -1;
	}

	float step1 = static_cast<float>(_Attacker.GetMonsterSkillList(_AttackerSkillNumber).GetSkillDamage());
	float step3 = OwnCharacteristiccalculation(_Attacker, _Attacker.GetMonsterCharacteristic(), _AttackerSkillNumber);
	float step4 = OtherCharacteristiccalculation(_Defender, _Defender.GetMonsterCharacteristic());

	// 기술위력 × 도구보정 × 특성보정 × 상대특성보정
	float DamageCal = step1 * step3 * step4;

	return DamageCal;
}

float PokeBattleSystem::OwnCharacteristiccalculation(PokeDataBase& _Attacker, PokeCharacteristic _characteristic, int _AttackerSkillNumber)
{
	float CharDamage = 0.0f;

	switch (_characteristic)
	{
	case PokeCharacteristic::심록:
	{
		float third = static_cast<float>(_Attacker.GetMonsterMaxHP_float() / 3);
		int Roundthird = static_cast<int>(round(third));
		if (Roundthird >= _Attacker.GetMonsterCurrentHP())
		{
			CharDamage = 1.5f;
		}
		else
		{
			CharDamage = 1.f;
		}
	}
	break;
	case PokeCharacteristic::맹화:
	{
		float third = static_cast<float>(_Attacker.GetMonsterMaxHP_float() / 3);
		int Roundthird = static_cast<int>(round(third));
		if (Roundthird >= _Attacker.GetMonsterCurrentHP())
		{
			CharDamage = 1.5f;
		}
		else
		{
			CharDamage = 1.f;
		}
	}
	break;
	case PokeCharacteristic::급류:
	{
		float third = static_cast<float>(_Attacker.GetMonsterMaxHP_float() / 3);
		int Roundthird = static_cast<int>(round(third));
		if (Roundthird >= _Attacker.GetMonsterCurrentHP())
		{
			CharDamage = 1.5f;
		}
		else
		{
			CharDamage = 1.f;
		}
	}
	break;
	case PokeCharacteristic::근성:
	{
		CharDamage = 1.f;
	}
	break;
	case PokeCharacteristic::정전기:
	{
		if (static_cast<int>(_Attacker.GetMonsterSkillList(_AttackerSkillNumber).GetSkillType()) == static_cast<int>(_Attacker.GetMonsterType()))
		{
			CharDamage = 1.5f;
		}
		else
		{
			CharDamage = 1.f;
		}
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

float PokeBattleSystem::OtherCharacteristiccalculation(PokeDataBase& _Defender, PokeCharacteristic _characteristic)
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
float PokeBattleSystem::NormalAttackstatuscalculator(PokeDataBase& _Attacker)
{
	// 스탯 × [[특성]] 보정 × [[도구]] 보정
	float step1 = Attackbuff(_Attacker);
	float step2 = OwnPersonalitycalculation_NA(_Attacker.GetMonsterPersonality()); // 성격에 따른 값 변화
	float step3 = 1.0f;

	if (ItemCode::MuscleBand == _Attacker.GetPossession())
	{
		step3 = 1.1f;
	}
	
	float DamageCal = step1 * step2 * step3;

	return DamageCal;
}

// 특수 공격 데미지 계산
float PokeBattleSystem::SpecialAttackstatuscalculator(PokeDataBase& _Attacker)
{
	// 스탯 × [[특성]] 보정 × [[도구]] 보정
	float step1 = Specialattackbuff(_Attacker);
	float step2 = OwnPersonalitycalculation_SA(_Attacker.GetMonsterPersonality());
	float step3 = 1.0f;

	if (ItemCode::MuscleBand == _Attacker.GetPossession())
	{
		step3 = 1.1f;
	}

	float DamageCal = step1 * step2 * step3;

	return DamageCal;
}

// 노말 방어 데미지 게산(상대)
float PokeBattleSystem::NormalDeffencestatuscalculator(PokeDataBase& _Defender)
{
	// 스탯 × [[특성]] 보정 × [[도구]] 보정
	float step1 = static_cast<float>(_Defender.GetMonsterDefense_float());
	float step2 = OtherPersonalitycalculation_ND(_Defender.GetMonsterPersonality());
	float step3 = 1.0f;

	if (ItemCode::ChoiceBand == _Defender.GetPossession())
	{
		step3 = 1.1f;
	}

	float DamageCal = step1 * step2 * step3;

	return DamageCal;
}

// 특수 방어 데미지 게산(상대)
float PokeBattleSystem::SpecialDeffencestatuscalculator(PokeDataBase& _Defender)
{
	// 스탯 × [[특성]] 보정 × [[도구]] 보정
	float step1 = static_cast<float>(_Defender.GetMonsterSpecialDefense_float());
	float step2 = OtherPersonalitycalculation_SD(_Defender.GetMonsterPersonality());
	float step3 = 1.0f;

	if (ItemCode::ChoiceScarf == _Defender.GetPossession())
	{
		step3 = 1.1f;
	}

	float DamageCal = step1 * step2 * step3;

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
		ScriptValue = BattleScript::Critical;
	}
	else
	{
		Criticalvalue = 1.0f;
	}

	return Criticalvalue;
}

float PokeBattleSystem::Randomvalue()
{
	int Rand = GameEngineRandom::MainRandom.RandomInt(217, 255);

	int Randv = ((Rand * 100) / 255);

	return static_cast<float>(Randv);
}

// 자속 보정
float PokeBattleSystem::Ownpropertiescorrection(PokeDataBase& _Attacker, int _AttackerSkillNumber)
{
	int Monstervalue = static_cast<int>(_Attacker.GetMonsterSkillList(_AttackerSkillNumber).GetSkillType());
	int Monsterskillvalue = static_cast<int>(_Attacker.GetMonsterType());

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
float PokeBattleSystem::Compatibilitycorrection(PokeDataBase& _Attacker, int _AttackerSkillNumber, PokeDataBase& _Defender)
{
	int skillvalue = static_cast<int>(_Attacker.GetMonsterSkillList(_AttackerSkillNumber).GetSkillType());
	int othervalue = static_cast<int>(_Defender.GetMonsterType());
	float correctionvalue = 0.0f;

	switch (skillvalue)
	{
	case 0: // 노말
	{
		switch (othervalue)
		{
		case 6:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
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
			ScriptValue = BattleScript::Insignificant;
			break;
		case 11:
			correctionvalue = 2.f;
			ScriptValue = BattleScript::Amazing;
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
			ScriptValue = BattleScript::Insignificant;
			break;
		case 6:
			correctionvalue = 2.f;
			ScriptValue = BattleScript::Amazing;
			break;
		case 9:
			correctionvalue = 2.f;
			ScriptValue = BattleScript::Amazing;
			break;
		case 11:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
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
			ScriptValue = BattleScript::Amazing;
			break;
		case 9:
			correctionvalue = 2.f;
			ScriptValue = BattleScript::Amazing;
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
			ScriptValue = BattleScript::Amazing;
			break;
		case 9:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
			break;
		case 10:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
			break;
		case 11:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
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
			ScriptValue = BattleScript::Insignificant;
			break;
		case 9:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
			break;
		case 10:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
			break;
		case 11:
			correctionvalue = 2.f;
			ScriptValue = BattleScript::Amazing;
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
			ScriptValue = BattleScript::Amazing;
			break;
		case 9:
			correctionvalue = 2.f;
			ScriptValue = BattleScript::Amazing;
			break;
		case 10:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
			break;
		case 11:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
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
			ScriptValue = BattleScript::Insignificant;
			break;
		case 6:
			correctionvalue = 2.f;
			ScriptValue = BattleScript::Amazing;
			break;
		case 9:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
			break;
		case 10:
			correctionvalue = 2.f;
			ScriptValue = BattleScript::Amazing;
			break;
		case 11:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
			break;
		default:
			correctionvalue = 1.f;
			break;
		}
	}
	break;
	case 12: // 전기
	{
		switch (othervalue)
		{
		case 2:
			correctionvalue = 2.f;
			ScriptValue = BattleScript::Amazing;
			break;
		case 10:
			correctionvalue = 2.f;
			ScriptValue = BattleScript::Amazing;
			break;
		case 11:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
			break;
		case 12:
			correctionvalue = 0.5f;
			ScriptValue = BattleScript::Insignificant;
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


void PokeBattleSystem::Bufflogic(PokeDataBase& _Attacker, int _AttackerSkillNumber, PokeDataBase& _Defender)
{
	PokeSkill buffskill = _Attacker.GetMonsterSkillList(_AttackerSkillNumber).GetSkill();

	switch (buffskill)
	{
	case PokeSkill::Growl:      // 울음소리 : 방깎
		_Defender.MinusDefensebuffstack();
		_Defender.MinusSpcialDefensebuffstack();
		break;
	case PokeSkill::Leer:       // 째려보기 : 공깎
		_Defender.MinusAttackbuffstack();
		_Defender.MinusSpcialAttackbuffstack();
		break;
	case PokeSkill::TailWhip:   // 꼬리흔들기 : 방깎
		_Defender.MinusDefensebuffstack();
		_Defender.MinusSpcialDefensebuffstack();
		break;
	case PokeSkill::Withdraw:   // 껍질에 숨기 : 방증
		_Attacker.PlusDefensebuffstack();
		_Attacker.PlusSpcialDefensebuffstack();
		break;
	case PokeSkill::FastMove:   // 고속이동 : 방증, 공증
		_Attacker.PlusAttackbuffstack();
		_Attacker.PlusSpcialAttackbuffstack();
		_Attacker.PlusDefensebuffstack();
		_Attacker.PlusSpcialDefensebuffstack();
		break;
	case PokeSkill::DefenseCurl:// 웅크리기 : 방증
		_Attacker.PlusDefensebuffstack();
		_Attacker.PlusSpcialDefensebuffstack();
		break;
	case PokeSkill::RockPolish: // 록커트 : 방깎
		_Defender.MinusDefensebuffstack();
		_Defender.MinusSpcialDefensebuffstack();
		break;
	case PokeSkill::Magnitude:  // 매그니튜드 : 방증, 공증
		_Attacker.PlusAttackbuffstack();
		_Attacker.PlusSpcialAttackbuffstack();
		_Attacker.PlusDefensebuffstack();
		_Attacker.PlusSpcialDefensebuffstack();
		break;
	case PokeSkill::SuperFang:  // 분노의앞니 : 공증
		_Attacker.PlusAttackbuffstack();
		_Attacker.PlusSpcialAttackbuffstack();
		break;
	case PokeSkill::FeatherDance: // 깃털댄스 : 공증
		_Attacker.PlusAttackbuffstack();
		_Attacker.PlusSpcialAttackbuffstack();
		break;
	default:
		MsgAssert("제대로된 값(버프)이 아닙니다. PokeDatabase.cpp를 살펴보세요");
		break;
	}
}

// 공증 결과
float PokeBattleSystem::Attackbuff(PokeDataBase& _Attacker)
{
	int stack = _Attacker.GetAttackbuffstack();
	float focusvalue = static_cast<float>(_Attacker.GetMonsterAttackPower_float());
	float stackvalue = 1.f;

	if (stack < 0)
	{
		while (0 > stack)
		{
			stackvalue -= 0.1f;
			++stack;
		}
	}
	else if (stack > 0)
	{
		while (0 < stack)
		{
			stackvalue += 0.1f;
			--stack;
		}
	}

	return focusvalue * stackvalue;
}

// 스공증 결과
float PokeBattleSystem::Specialattackbuff(PokeDataBase& _Attacker)
{
	int stack = _Attacker.GetSpcialAttackbuffstack();
	float focusvalue = static_cast<float>(_Attacker.GetMonsterSpecialAttackPower_float());
	float stackvalue = 1.f;

	if (stack < 0)
	{
		while (0 > stack)
		{
			stackvalue -= 0.1f;
			++stack;
		}
	}
	else if (stack > 0)
	{
		while (0 < stack)
		{
			stackvalue += 0.1f;
			--stack;
		}
	}

	return focusvalue * stackvalue;
}

// 방증 결과
float PokeBattleSystem::Defensekbuff(PokeDataBase& _Defender)
{
	int stack = _Defender.GetDefensebuffstack();
	float focusvalue = static_cast<float>(_Defender.GetMonsterDefense_float());
	float stackvalue = 1.f;

	if (stack < 0)
	{
		while (0 > stack)
		{
			stackvalue -= 0.1f;
			++stack;
		}
	}
	else if (stack > 0)
	{
		while (0 < stack)
		{
			stackvalue += 0.1f;
			--stack;
		}
	}

	return focusvalue * stackvalue;
}

// 스방증 결과
float PokeBattleSystem::Specialdefensekbuff(PokeDataBase& _Defender)
{
	int stack = _Defender.GetSpcialDefensekbuffstack();
	float focusvalue = static_cast<float>(_Defender.GetMonsterSpecialDefense_float());
	float stackvalue = 1.f;

	if (stack < 0)
	{
		while (0 > stack)
		{
			stackvalue -= 0.1f;
			++stack;
		}
	}
	else if (stack > 0)
	{
		while (0 < stack)
		{
			stackvalue += 0.1f;
			--stack;
		}
	}

	return focusvalue * stackvalue;
}