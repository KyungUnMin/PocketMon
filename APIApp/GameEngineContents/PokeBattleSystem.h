#pragma once

#include "PokeDataBase.h"

// Ό³Έν :
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

	static void Battle(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender);

protected:

private:
	static int Damage;
	static bool IsSpecial;

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

};
