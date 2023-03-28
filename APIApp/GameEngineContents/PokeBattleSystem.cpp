#include "PokeBattleSystem.h"

#include <cmath>

#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineRandom.h>

#include "PokeDataBase.h"

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
		MsgAssert("��ų�� 1, 2, 3, 4���� ����� �� �ֽ��ϴ�.");
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

			// ������ = (((���� �� 2 / 5) + 2) �� ���� �� Ư������ �� 50) �� Ư�����) �� [[�޼�]] �� �ڼӺ��� �� Ÿ�Ի� �� ������ �� 100
			// ��� ������ ���ʿ��� ������ ������� ����ϸ�, �� ����� �����ϱ� ���� �Ҽ��� ���ϸ� ������. ������� ������� ������ �߸��� ����� �����Ƿ� ����.
			// Damage = (((Cal1 * Cal2 * Cal3 / 50) / Cal4) * Cal5 * Cal6 * Cal7 * Cal8) / 100;

			float step1 = Cal1 * Cal2;
			float step2 = step1 * Cal3;
			float step3 = (step2 / 50) / Cal4;
			float step4 = step3 * Cal5;
			float step5 = step4 * Cal6;
			float step6 = step5 * Cal7;
			float step7 = step6 * Cal8;

			Damage = static_cast<int>(round(step7 / 70));

			_Defender.MinusMonsterCurrentHP(Damage);
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
		MsgAssert("1, 2, 3, 4�� �� Unknown�� �ƴ� ��ų�� ����� �� �ֽ��ϴ�.");
		return -1;
	}

	float step1 = static_cast<float>(_Attacker.GetMonsterSkillList(_AttackerSkillNumber).GetSkillDamage());
	float step3 = OwnCharacteristiccalculation(_Attacker, _Attacker.GetMonsterCharacteristic());
	float step4 = OtherCharacteristiccalculation(_Defender, _Defender.GetMonsterCharacteristic());

	// ������� �� �������� �� Ư������ �� ���Ư������
	float DamageCal = step1 * step3 * step4;

	return DamageCal;
}

float PokeBattleSystem::OwnCharacteristiccalculation(PokeDataBase& _Attacker, PokeCharacteristic _characteristic)
{
	float CharDamage = 0.0f;

	switch (_characteristic)
	{
	case PokeCharacteristic::�ɷ�:
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
	case PokeCharacteristic::��ȭ:
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
	case PokeCharacteristic::�޷�:
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

float PokeBattleSystem::OtherCharacteristiccalculation(PokeDataBase& _Defender, PokeCharacteristic _characteristic)
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
float PokeBattleSystem::NormalAttackstatuscalculator(PokeDataBase& _Attacker)
{
	// ���� �� [[Ư��]] ���� �� [[����]] ����
	float step1 = Attackbuff(_Attacker);
	float step2 = OwnPersonalitycalculation_NA(_Attacker.GetMonsterPersonality()); // ���ݿ� ���� �� ��ȭ
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
float PokeBattleSystem::SpecialAttackstatuscalculator(PokeDataBase& _Attacker)
{
	// ���� �� [[Ư��]] ���� �� [[����]] ����
	float step1 = Specialattackbuff(_Attacker);
	float step2 = OwnPersonalitycalculation_SA(_Attacker.GetMonsterPersonality());
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
float PokeBattleSystem::NormalDeffencestatuscalculator(PokeDataBase& _Defender)
{
	// ���� �� [[Ư��]] ���� �� [[����]] ����
	float step1 = static_cast<float>(_Defender.GetMonsterSpecialDefense_float());
	float step2 = OtherPersonalitycalculation_ND(_Defender.GetMonsterPersonality());
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
float PokeBattleSystem::SpecialDeffencestatuscalculator(PokeDataBase& _Defender)
{
	// ���� �� [[Ư��]] ���� �� [[����]] ����
	float step1 = static_cast<float>(_Defender.GetMonsterSpecialDefense_float());
	float step2 = OtherPersonalitycalculation_SD(_Defender.GetMonsterPersonality());
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

// �ڼ� ����
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

// Ÿ�� ��
float PokeBattleSystem::Compatibilitycorrection(PokeDataBase& _Attacker, int _AttackerSkillNumber, PokeDataBase& _Defender)
{
	int skillvalue = static_cast<int>(_Attacker.GetMonsterSkillList(_AttackerSkillNumber).GetSkillType());
	int othervalue = static_cast<int>(_Defender.GetMonsterType());
	float correctionvalue = 0.0f;

	switch (skillvalue)
	{
	case 0: // �븻
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
	case 2: // ����
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
	case 5: // ��
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
	case 6: // ����
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
	case 8: // ��ö
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
	case 9: // ��
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
	case 10: // ��
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
	case 11: // Ǯ
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
	case PokeSkill::Growl:      // �����Ҹ� : ���
		_Defender.MinusDefensebuffstack();
		_Defender.MinusSpcialDefensebuffstack();
		break;
	case PokeSkill::Leer:       // °������ : ����
		_Defender.MinusAttackbuffstack();
		_Defender.MinusSpcialAttackbuffstack();
		break;
	case PokeSkill::TailWhip:   // �������� : ���
		_Defender.MinusDefensebuffstack();
		_Defender.MinusSpcialDefensebuffstack();
		break;
	case PokeSkill::Withdraw:   // ������ ���� : ����
		_Attacker.PlusDefensebuffstack();
		_Attacker.PlusSpcialDefensebuffstack();
		break;
	case PokeSkill::FastMove:   // ����̵� : ����, ����
		_Attacker.PlusAttackbuffstack();
		_Attacker.PlusSpcialAttackbuffstack();
		_Attacker.PlusDefensebuffstack();
		_Attacker.PlusSpcialDefensebuffstack();
		break;
	case PokeSkill::DefenseCurl:// ��ũ���� : ����
		_Attacker.PlusDefensebuffstack();
		_Attacker.PlusSpcialDefensebuffstack();
		break;
	case PokeSkill::RockPolish: // ��ĿƮ : ���
		_Defender.MinusDefensebuffstack();
		_Defender.MinusSpcialDefensebuffstack();
		break;
	case PokeSkill::Magnitude:  // �ű״�Ʃ�� : ����, ����
		_Attacker.PlusAttackbuffstack();
		_Attacker.PlusSpcialAttackbuffstack();
		_Attacker.PlusDefensebuffstack();
		_Attacker.PlusSpcialDefensebuffstack();
		break;
	case PokeSkill::SuperFang:  // �г��Ǿմ� : ����
		_Attacker.PlusAttackbuffstack();
		_Attacker.PlusSpcialAttackbuffstack();
		break;
	default:
		MsgAssert("����ε� ��(����)�� �ƴմϴ�. PokeDatabase.cpp�� ���캸����");
		break;
	}
}

// ���� ���
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

// ������ ���
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

// ���� ���
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

// ������ ���
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