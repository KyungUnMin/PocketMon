#pragma once

#include <string>

class GameEngineRender;

// 설명 :
class PokeDataBase
{
public:
	// constrcuter destructer
	PokeDataBase();
	~PokeDataBase();

	// delete Function
	PokeDataBase(const PokeDataBase& _Other) = delete;
	PokeDataBase(PokeDataBase&& _Other) noexcept = delete;
	PokeDataBase& operator=(const PokeDataBase& _Other) = delete;
	PokeDataBase& operator=(PokeDataBase&& _Other) noexcept = delete;

protected:

private:
	// 포켓몬 데이터

	GameEngineRender* MonsterImage = nullptr;  // 포켓몬 이미지

	std::string Name = "안농";                 // 포켓몬 이름

	bool IsMan = true;                         // 포켓몬 성별
	bool IsbeCaught = false;                   // 야생포켓몬인지 잡힌 포켓몬인지

	int PokeDexNumber = 0;                    // 포켓몬 도감 번호
	int HealthPoint = 0;                       // 몬스터 체력
	int AttackPower = 0;                       // 몬스터 공격력
	int Defense = 0;                           // 몬스터 방어력
	int SpecialAttackPower = 0;                // 몬스터 특수공격력
	int SpecialDefense = 0;                    // 몬스터 특수방어력
	int Agility = 0;                           // 몬스터 민첩성
	int MonsterLevel = 0;                      // 몬스터 레벨
	int Experience = 0;						   // 몬스터 경험치
	int RemainingExperience = 0;               // 몬스터 다음 레벨까지 남은 경험치

	int PoketBall = 0;                        // 포켓몬이 담겨있는 포켓볼 종류
	int PokeType = 0;
		// 타입 (물, 불, 땅, 비행 등)
		// 특성 (
		// 성격
		// 


};

