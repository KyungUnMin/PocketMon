#pragma once

#include "PokeDataBase.h"

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

	void Battle(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender);

protected:

private:
	int Damage = 0;
	bool IsSpecial = false;

	int Damagecalculator(PokeDataBase* _Attacker, int _AttackerSkillNumber, PokeDataBase* _Defender);

	float OwnCharacteristiccalculation(PokeDataBase* _Attacker, PokeCharacteristic _characteristic);
	float OtherCharacteristiccalculation(PokeDataBase* _Defender, PokeCharacteristic _characteristic);

	int NormalAttackstatuscalculator(PokeDataBase* _Attacker);
	int SpecialAttackstatuscalculator(PokeDataBase* _Attacker);
	int NormalDeffencestatuscalculator(PokeDataBase* _Defender);
	int SpecialDeffencestatuscalculator(PokeDataBase* _Defender);

	float OwnPersonalitycalculation(PokePersonality _personality);
	float OtherPersonalitycalculation(PokePersonality _personality);

	void Ownpropertiescorrection();
	void Compatibilitycorrection();
	void Randomvalue();

	// 0319 특수공격, 특수방어 공식 세우다가 멈춤 -> Personality에 따른 스탯 10% 상승, 감소 함수 필요

};
