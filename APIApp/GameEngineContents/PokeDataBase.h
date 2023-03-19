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
	static void PokeStatusUp(PokeDataBase* _PoKeCreatePtr);
	void PokeExperienceAcquisition(int _EXP);
	void PokeLevelUp(int _EXP);
	//void PokeEvolution();
	//void PokeSkillAcquisition();

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
	inline int GetMonsterLevel()
	{
		return MonsterLevel;
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
	inline int GetMonsterMaxHP()
	{
		return MaxHealthPoint;
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
	inline int GetMonsterAttackPower()
	{
		return AttackPower;
	}

	// 방어력 가져오기
	inline int GetMonsterDefense()
	{
		return Defense;
	}

	// 특수공격력 가져오기
	inline int GetMonsterSpecialAttackPower()
	{
		return SpecialAttackPower;
	}

	// 특수방어력 가져오기
	inline int GetMonsterSpecialDefense()
	{
		return SpecialDefense;
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
	static std::list<PokeDataBase*> AllPokemons;		    // 모든 포켓몬
	static std::list<PokeSkillBase*> AllSkills;			    // 모든 스킬
	static PokeDataBase Ptr;                                // 사용하지 마세요...

	// 포켓몬 데이터
	static GameEngineRender* MonsterImage;					// 포켓몬 이미지
	static std::string Name;							    // 포켓몬 이름

	static std::vector<PokeSkillBase*> SkillList;			// 포켓몬 스킬리스트
										    
	static bool IsMan;										// 포켓몬 성별
	static bool IsbeCaught;									// 야생포켓몬인지 잡힌 포켓몬인지

	static PokeNumber PokeDexNumber;					    // 포켓몬 도감 번호
	static int MaxHealthPoint;								// 몬스터 최대 체력
	static int CurrentHealthPoint;						    // 몬스터 잔여 체력
	static int AttackPower;									// 몬스터 공격력
	static int Defense;										// 몬스터 방어력
	static int SpecialAttackPower;							// 몬스터 특수공격력
	static int SpecialDefense;								// 몬스터 특수방어력
	static int Agility;									    // 몬스터 민첩성
	static int MonsterLevel;								// 몬스터 레벨
	static int Experience;									// 몬스터 경험치
	static int RemainingExperience;						    // 몬스터 다음 레벨까지 남은 경험치
											    
	static int PokeBall;									// 포켓몬이 담겨있는 포켓볼 종류
	static PokeType Type;								    // 포켓몬 속성 타입
	static PokePersonality Personality;			            // 포켓몬 성격
	static PokeCharacteristic Characteristic;	            // 포켓몬 특성

	// 데이터 생성 보조
	static void PersonalityDecision(PokeDataBase* _PoKeCreatePtr);                                 // 성격
	static void GenderDecision(PokeDataBase* _PoKeCreatePtr);                                      // 성별
	static void PokeSkillInit(int _Index, PokeSkill _SkillName, PokeDataBase* _PoKeCreatePtr);     // 스킬 할당

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

	// 전투
	void Attack();
};

