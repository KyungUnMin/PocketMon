#pragma once

#include <string>
#include <vector>
#include <list>

#include <GameEngineBase/GameEngineDebug.h>
#include "PokeSkillBase.h"

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
	Pidgey,     // 9 구구
	Rattata,    // 10 꼬렛
	Spearow,    // 11 깨비참
	Geodude,    // 12 꼬마돌
	Onix,       // 13 롱스톤
	Max,        // max
};

// 포켓몬 타입
enum class PokeType
{
	Normal,   // 노말
	Fight,    // 격투
	Flying,   // 비행
	Poision,  // 독
	Bug,      // 벌레
	Ground,   // 땅
	Rock,     // 바위
	Ghost,    // 고스트
	Steel,    // 강철
	Fire,     // 불
	Water,    // 물
	Grass,    // 풀
	Electro,  // 전기
	Ice,      // 얼음
	Psvchc,   // 에스퍼
	Dragon,   // 드래곤
	Drak,     // 악
};

// 포켓몬 성격
enum class PokePersonality
{
	Lonely,   // 외로운
	Adamant,  // 고집스러운
	Naughty,  // 어리광부리는
	Brave,    // 용감한
	Bold,     // 뻔뻔한
	Impish,   // 장난이 심한
	Lax,      // 덜렁한
	Relaxed,  // 느긋한
	Modest,   // 소극적인
	Mild,     // 대범한
	Rash,     // 무심한
	Quiet,    // 냉정한
	Calm,     // 온화한
	Gentle,   // 얌전한
	Careful,  // 신중한
	Sassy,    // 건방진
	Timid,    // 겁많은
	Hasty,    // 성급한
	Jolly,    // 쾌활한
	Naive,    // 순진한
	Bashful,  // 수줍은
	Hardy,    // 노력하는
	Docile,   // 고분고분한
	Quirky,   // 변덕스러운
	Serious,  // 성실한
};

// 포켓몬 특성
enum class PokeCharacteristic
{
	심록,
	맹화,
	급류,
	날카로운눈,
	근성,
	돌머리,
};

class GameEngineRender;
// class PokeSkillBase;

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

	static PokeDataBase* PokeCreate(int _PokeDexNumber, int _Level = 1);
	static void PokeExperienceGain(PokeDataBase* _Ownerpokemon, PokeDataBase* _knockeddownpokemon);

	//void PokeEvolution();
	//void PokeSkillAcquisition();

	// 체력깎기
	void MinusMonsterCurrentHP(int _Value)
	{
		CurrentHealthPoint -= _Value;
	}

	// 포켓몬 이름 가져오기
	std::string_view ForUI_GetMonsterName()
	{
		return Name;
	}

	// 포켓몬 이름 수정
	void PokeNameEdit(std::string _EditName)
	{
		Name = _EditName;
	}

	// 포켓몬 레벨 가져오기
	inline int GetMonsterLevel_int()
	{
		return MonsterLevel;
	}

	// 포켓몬 레벨 가져오기(계산용)
	inline float GetMonsterLevel_float()
	{
		return static_cast<float>(MonsterLevel);
	}

	// UI용 레벨 string 반환
	inline std::string ForUI_GetMonsterLevel()
	{
		return std::to_string(MonsterLevel);
	}

	// 포켓몬 경험치 가져오기
	inline int GetMonsterExperience()
	{
		return Experience;
	}

	inline void PlusMonsterExperience(int _EXP)
	{
		Experience += _EXP;
	}

	// UI용 경험치 string 반환
	inline std::string ForUI_GetMonsterExperience()
	{
		return std::to_string(Experience);
	}

	// 포켓몬 성별 가져오기
	inline int GetMonsterGender()
	{
		return IsMan;
	}

	// 포켓몬 최대 체력 가져오기
	inline int GetMonsterMaxHP_int()
	{
		return MaxHealthPoint;
	}

	// 포켓몬 최대 체력 가져오기 (계산용)
	inline float GetMonsterMaxHP_float()
	{
		return static_cast<float>(MaxHealthPoint);
	}

	// UI용 최대 체력 string 반환
	inline std::string ForUI_GetMonsterMaxHP()
	{
		return std::to_string(MaxHealthPoint);
	}

	// 포켓몬 현재 체력 가져오기
	inline int GetMonsterCurrentHP()
	{
		return CurrentHealthPoint;
	}

	// UI용 현재 체력 string 반환
	inline std::string ForUI_GetMonsterCurrentHP()
	{
		return std::to_string(CurrentHealthPoint);
	}

	// 공격력 가져오기
	inline int GetMonsterAttackPower_int()
	{
		return AttackPower;
	}

	// 공격력 가져오기 (계산용)
	inline float GetMonsterAttackPower_float()
	{
		return static_cast<float>(AttackPower);
	}

	// 방어력 가져오기
	inline int GetMonsterDefense_int()
	{
		return Defense;
	}

	// 방어력 가져오기 (계산용)
	inline float GetMonsterDefense_float()
	{
		return static_cast<float>(Defense);
	}

	// 특수공격력 가져오기
	inline int GetMonsterSpecialAttackPower_int()
	{
		return SpecialAttackPower;
	}

	// 특수공격력 가져오기 (계산용)
	inline float GetMonsterSpecialAttackPower_float()
	{
		return static_cast<float>(SpecialAttackPower);
	}

	// 특수방어력 가져오기
	inline int GetMonsterSpecialDefense_int()
	{
		return SpecialDefense;
	}

	// 특수방어력 가져오기 (계산용)
	inline float GetMonsterSpecialDefense_float()
	{
		return static_cast<float>(SpecialDefense);
	}

	// 스피드 가져오기
	inline int GetMonsterAgility()
	{
		return Agility;
	}

	// 포켓몬 스킬리스트 가져오기
	PokeSkillBase* GetMonsterSkillList(int _SkillNumber)
	{
		if (_SkillNumber <= 0 || _SkillNumber >= 5)
		{
			MsgAssert("스킬목록은 1, 2, 3, 4 입니다.");
			return nullptr; 
		}

		return SkillList[_SkillNumber - 1];
	}

	// 포켓몬 스킬 변경
	void ChangeMonsterSkillList(int _SkillNumber)
	{
		if (_SkillNumber <= 0 || _SkillNumber >= 5)
		{
			MsgAssert("스킬목록은 1, 2, 3, 4 입니다.");
			return;
		}

		//SkillList[_SkillNumber - 1]->ChangeSkill(SkillList[_SkillNumber - 1]);;
	}

	// 포켓몬 타입 가져오기
	PokeType GetMonsterType()
	{
		return Type;
	}

	// 포켓몬 특성 가져오기
	PokePersonality GetMonsterPersonality()
	{
		return Personality;
	}

	// 포켓몬 성격 가져오기
	PokeCharacteristic GetMonsterCharacteristic()
	{
		return Characteristic;
	}

	/// <summary>
	/// 메모리 해제용 포인터 Get 함수입니다. 호출해서 사용하지 마세요. 터집니다.
	/// </summary>
	static PokeDataBase& GetPtr()
	{
		return Ptr;
	}
	static void Release();

protected:

private:
	// 메모리 할당, 해제용 리스트, 포인터 (사용하지 마세요...)
	static std::list<PokeDataBase*> AllPokemons;		          // 모든 포켓몬
	static std::list<PokeSkillBase*> AllSkills;			          // 모든 스킬
	static PokeDataBase Ptr;                                      // 사용하지 마세요...

	// 포켓몬 데이터
	GameEngineRender* MonsterImage = nullptr;					  // 포켓몬 이미지
	std::string Name = "안농";							          // 포켓몬 이름

	std::vector<PokeSkillBase*> SkillList = std::vector<PokeSkillBase*>(4);			// 포켓몬 스킬리스트
								    
	bool IsMan = true;										      // 포켓몬 성별
	bool IsbeCaught = false;									  // 야생포켓몬인지 잡힌 포켓몬인지

	PokeNumber PokeDexNumber = PokeNumber::Blastoise;			  // 포켓몬 도감 번호
	int MaxHealthPoint = 0;								          // 몬스터 최대 체력
	int CurrentHealthPoint = 0;						              // 몬스터 잔여 체력
	int AttackPower = 0;								     	  // 몬스터 공격력
	int Defense = 0;										      // 몬스터 방어력
	int SpecialAttackPower = 0;							          // 몬스터 특수공격력
	int SpecialDefense = 0;								          // 몬스터 특수방어력
	int Agility = 0;									          // 몬스터 민첩성
	int MonsterLevel = 0;								          // 몬스터 레벨
	int Experience = 0;									          // 몬스터 경험치
	int RemainingExperience = 0;						          // 몬스터 다음 레벨까지 남은 경험치
									    
	int PokeBall = 0;									          // 포켓몬이 담겨있는 포켓볼 종류
	PokeType Type = PokeType::Bug;								  // 포켓몬 속성 타입
	PokePersonality Personality = PokePersonality::Adamant;		  // 포켓몬 성격
	PokeCharacteristic Characteristic = PokeCharacteristic::근성; // 포켓몬 특성

	// 데이터 생성 보조
	static void PersonalityDecision(PokeDataBase* _PoKeCreatePtr);                                 // 성격
	static void GenderDecision(PokeDataBase* _PoKeCreatePtr);                                      // 성별
	static void PokeSkillInit(int _Index, PokeSkill _SkillName, PokeDataBase* _PoKeCreatePtr);     // 스킬 할당
	static void PokeStatusUp(PokeDataBase* _PoKeCreatePtr);                                        // 1 이상 레벨 할당 시 호출됨

	// 경험치가 100을 넘길 때 호출
	static void PokeLevelUp(PokeDataBase* _Ownerpokemon);

	// 포켓몬 베이스 데이터
	static void BulbasaurData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void IvysaurData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void VenusaurData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void CharmanderData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void CharmeleonData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void CharizardData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void SquirtleData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void WartortleData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void BlastoiseData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void PidgeyData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void RattataData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void SpearowData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void GeodudeData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void OnixData(int _Level, PokeDataBase* _PoKeCreatePtr);

};

