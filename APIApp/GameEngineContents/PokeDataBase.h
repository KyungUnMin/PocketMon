#pragma once

#include <string>
#include <vector>

// 도감번호는 +1로 표시
enum class PokeNumber
{
	Bulbasaur,  // 0 이상해씨
	Ivysaur,    // 1 이상해풀
	Venusaur,   // 2 이상해꽃
	Charmander, // 3 파이리
	Charmeleon, // 4 리자드
	Charizard,  // 5 리자몽
	Squirtle,   // 6 꼬부기
	Wartortle,  // 7 어니부기
	Blastoise,  // 8 거북왕
	Max,        // max
};

// 포켓몬 타입
enum class PokeType
{
	Normal,
	Fight,
	Flying,
	Poision,
	Bug,
	Ground,
	Rock,
	Ghost,
	Steel,
	Fire,
	Water,
	Grass,
	Electro,
	Ice,
	Psvchc,
	Dragon,
	Drak,
};

// 포켓몬 성격
enum class PokePersonality
{
	Lonely,
	Adamant,
	Naughty,
	Brave,
	Bold,
	Impish,
	Lax,
	Relaxed,
	Modest,
	Mild,
	Rash,
	Quiet,
	Calm,
	Gentle,
	Careful,
	Sassy,
	Timid,
	Hasty,
	Jolly,
	Naive,
	Bashful,
	Hardy,
	Docile,
	Quirky,
	Serious,
};

// 포켓몬 특성
enum class PokeCharacteristic
{
	심록,
	맹화,
	급류,
};

class GameEngineRender;
class PokeSkillBase;

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

	void PokeCreate(PokeNumber _Number, int _Level);
	void PokeExperienceAcquisition(int _EXP);
	void PokeLevelUp(int _EXP);
	void PokeStatusUp(int _Status);
	void PokeEvolution();
	void PokeSkillAcquisition();

protected:

private:
	// 포켓몬 데이터
	GameEngineRender* MonsterImage = nullptr;						 // 포켓몬 이미지
	// 기술 4개 벡터

	std::string Name = "안농";									     // 포켓몬 이름
											    
	bool IsMan = true;											     // 포켓몬 성별
	bool IsbeCaught = false;									     // 야생포켓몬인지 잡힌 포켓몬인지

	PokeNumber PokeDexNumber = PokeNumber::Max;					     // 포켓몬 도감 번호
	int HealthPoint = 0;										     // 몬스터 체력
	int AttackPower = 0;											 // 몬스터 공격력
	int Defense = 0;												 // 몬스터 방어력
	int SpecialAttackPower = 0;										 // 몬스터 특수공격력
	int SpecialDefense = 0;											 // 몬스터 특수방어력
	int Agility = 0;											     // 몬스터 민첩성
	int MonsterLevel = 0;										     // 몬스터 레벨
	int Experience = 0;												 // 몬스터 경험치
	int RemainingExperience = 0;								     // 몬스터 다음 레벨까지 남은 경험치
											    
	int PokeBall = 0;												 // 포켓몬이 담겨있는 포켓볼 종류
	PokeType Type = PokeType::Normal;								 // 포켓몬 속성 타입
	PokePersonality Personality = PokePersonality::Serious;			 // 포켓몬 성격
	PokeCharacteristic Characteristic = PokeCharacteristic::심록;	 // 포켓몬 특성

	// 성격, 성별 난수
	PokePersonality PersonalityDecision();
	void GenderDecision();


	// 포켓몬 베이스 데이터
	void BulbasaurData(int _Level);
	void CharmanderData(int _Level);
	void SquirtleData(int _Level);

	// 스킬
	std::vector<PokeSkillBase*> SkillList = std::vector<PokeSkillBase*>(4);
};

