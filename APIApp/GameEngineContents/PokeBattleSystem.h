#pragma once

#include "PokeDataBase.h"

enum class BattleScript
{
	Nothing,          // 0 아무것도 아님 (노말)
	Insignificant,    // 1 효과는 미미했다!
	Critical,         // 2 급소에 맞았다!
	Amazing,          // 3 효과는 굉장했다!
	Buff,             // 4 이 스킬은 버프스킬입니다.
};

// 설명 :
class PokeBattleSystem
{
public:
	// constrcuter destructer
	PokeBattleSystem();
	~PokeBattleSystem();

	// delete Function
	PokeBattleSystem(const PokeBattleSystem& _Other) = delete;
	PokeBattleSystem(PokeBattleSystem&& _Other) noexcept = delete;
	PokeBattleSystem& operator=(const PokeBattleSystem& _Other) = delete;
	PokeBattleSystem& operator=(PokeBattleSystem&& _Other) noexcept = delete;

	static BattleScript Battle(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender);

protected:

private:
	static int Damage;
	static bool IsSpecial;
	static bool IsAttack;
	static BattleScript ScriptValue;

	static float Damagecalculator(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender);

	static float OwnCharacteristiccalculation(PokeDataBase* _Attacker, PokeCharacteristic _characteristic);
	static float OtherCharacteristiccalculation(PokeDataBase* _Defender, PokeCharacteristic _characteristic);

	static float NormalAttackstatuscalculator(PokeDataBase* _Attacker);
	static float SpecialAttackstatuscalculator(PokeDataBase* _Attacker);
	static float NormalDeffencestatuscalculator(PokeDataBase* _Defender);
	static float SpecialDeffencestatuscalculator(PokeDataBase* _Defender);

	static float OwnPersonalitycalculation_NA(PokePersonality _personality);
	static float OwnPersonalitycalculation_SA(PokePersonality _personality);
	static float OtherPersonalitycalculation_ND(PokePersonality _personality);
	static float OtherPersonalitycalculation_SD(PokePersonality _personality);

	static float CriticalRand();
	static float Randomvalue();

	static float Ownpropertiescorrection(PokeDataBase* _Attacker, int _AttackerSkillNumber);
	static float Compatibilitycorrection(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender);

	static void Bufflogic(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender);

	static float Attackbuff(PokeDataBase* _Attacker);
	static float Specialattackbuff(PokeDataBase* _Attacker);
	static float Defensekbuff(PokeDataBase* _Defender);
	static float Specialdefensekbuff(PokeDataBase* _Defender);

};

