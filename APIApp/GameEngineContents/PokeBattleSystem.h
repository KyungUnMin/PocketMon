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

	void Battle(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender);

protected:

private:
	int Damage = 0;
	bool IsSpecial = false;

	float Damagecalculator(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender);

	float OwnCharacteristiccalculation(PokeDataBase* _Attacker, PokeCharacteristic _characteristic);
	float OtherCharacteristiccalculation(PokeDataBase* _Defender, PokeCharacteristic _characteristic);

	float NormalAttackstatuscalculator(PokeDataBase* _Attacker);
	float SpecialAttackstatuscalculator(PokeDataBase* _Attacker);
	float NormalDeffencestatuscalculator(PokeDataBase* _Defender);
	float SpecialDeffencestatuscalculator(PokeDataBase* _Defender);

	float OwnPersonalitycalculation_NA(PokePersonality _personality);
	float OwnPersonalitycalculation_SA(PokePersonality _personality);
	float OtherPersonalitycalculation_ND(PokePersonality _personality);
	float OtherPersonalitycalculation_SD(PokePersonality _personality);

	float CriticalRand();
	float Randomvalue();

	void Ownpropertiescorrection();
	void Compatibilitycorrection();

};
