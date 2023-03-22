#pragma once

#include <string>
#include <map>

enum class PokeSkill
{
	Scratch,      // 0 할퀴기
	Growl,        // 1 울음소리
	Ember,        // 2 불꽃세례
	Leer,         // 3 째려보기
	Slash,        // 4 베어가르기
	Flamethrower, // 5 화염방사
	Tackle,       // 6 몸통박치기
	TailWhip,     // 7 꼬리흔들기
	Bubble,       // 8 거품
	WaterGun,     // 9 물대포
	Withdraw,     // 10 껍질에숨기
	SkullBash,    // 11 로케트박치기
	HydroPump,    // 12 하이드로펌프
	LeechSeed,    // 13 씨뿌리기
	VineWhip,     // 14 덩굴채찍
	RazorLeaf,    // 15 잎날가르기
	SleepPowder,  // 16 수면가루
	SolarBeam,    // 17 솔라빔
	SandAttack,   // 18 모래뿌리기
	Gust,         // 19 바람일으키기
	QuickAttack,  // 20 전광석화
	Twister,      // 21 회오리
	FeatherDance, // 22 깃털댄스
	WingAttack,   // 23 날개치기
	AirSlash,     // 24 에어슬래시
	Peck,         // 25 쪼기
	FuryAttack,   // 26 마구찌르기
	Pursuit,      // 27 따라가때리기
	FastMove,     // 28 고속이동
	Assurance,    // 29 승부굳히기
	DrillPeck,    // 30 회전부리
	DefenseCurl,  // 31 웅크리기
	RockPolish,   // 32 록커트
	RockThrow,    // 33 돌떨구기
	Magnitude,    // 34 매그니튜드
	Selfdestruct, // 35 자폭
	Earthquake,   // 36 지진
	StoneEdge,    // 37 스톤에지
	Bind,         // 38 조이기
	RockTomb,     // 39 암석봉인
	DragonBreath, // 40 용의숨결
	IronTail,     // 41 아이언테일
	SandTomb,     // 42 모래지옥
	Bite,         // 43 물기
	HyperFang,    // 44 필살앞니
	Crunch,       // 45 깨물어부수기
	SuperFang,    // 46 분노의앞니
	DoubleEdge,   // 47 이판사판태클
	Unknown,      // 48 Max
};

enum class SkillType
{
	Normal,   // 0 노말 (사용)
	Fight,    // 1 격투
	Flying,   // 2 비행 (사용)
	Poision,  // 3 독
	Bug,      // 4 벌레
	Ground,   // 5 땅   (사용)
	Rock,     // 6 바위  (사용)
	Ghost,    // 7 고스트
	Steel,    // 8 강철 (사용)
	Fire,     // 9 불  (사용)
	Water,    // 10 물 (사용)
	Grass,    // 11 풀 (사용)
	Electro,  // 12 전기
	Ice,      // 13 얼음
	Psvchc,   // 14 에스퍼 (사용)
	Dragon,   // 15 드래곤 (사용)
	Drak,     // 16 악 (사용)
};

// 설명 :
class PokeSkillBase
{
	friend class PokeDataBase;

public:
	// constrcuter destructer
	PokeSkillBase();
	~PokeSkillBase();

	// delete Function
	PokeSkillBase(const PokeSkillBase& _Other) = delete;
	PokeSkillBase(PokeSkillBase&& _Other) noexcept = delete;
	PokeSkillBase& operator=(const PokeSkillBase& _Other) = delete;
	PokeSkillBase& operator=(PokeSkillBase&& _Other) noexcept = delete;

	// 이것은 공격스킬입니까?
	inline bool ItisAttackSkill()
	{
		return IsAttackSkill;
	}

	// 이것은 특수공격입니까?
	inline bool ItisSpecialSkill()
	{
		return IsSpecialSkill;
	}

	// 스킬 공격력 가져오기
	inline int GetSkillDamage()
	{
		return SkillDamage;
	}

	// 스킬 최대 PP 가져오기
	inline int GetMaxSkillPowerPoint()
	{
		return MaxSkillPowerPoint;
	}

	// UI용 최대 PP 반환
	inline std::string ForUI_GetMaxSkillPowerPoint()
	{
		return std::to_string(MaxSkillPowerPoint);
	}

	// 스킬 현재 PP 가져오기
	inline int GetCurrentSkillPowerPoint()
	{
		return CurrentSkillPowerPoint;
	}

	// UI용 현재 PP 반환
	inline std::string ForUI_GetCurrentSkillPowerPoint()
	{
		return std::to_string(CurrentSkillPowerPoint);
	}

	// 스킬 적중률 가져오기
	inline float GetSkillHitrate()
	{
		return SkillHitrate;
	}

	// 스킬 타입 가져오기
	SkillType GetSkillType()
	{
		return SkillType;
	}

	// 스킬 종류 가져오기
	PokeSkill GetSkill()
	{
		return Skills;
	}

	// 스킬이름 가져오기
	std::string ForUI_GetSkillName()
	{
		return Name;
	}

protected:

private:
	PokeSkill Skills = PokeSkill::Tackle;          // 스킬 종류
	SkillType SkillType = SkillType::Normal;       // 스킬 타입
	std::string Name = "대폭발";					   // 스킬 이름

	bool IsAttackSkill = true;                     // 공격스킬인지 버프스킬인지
	bool IsSpecialSkill = false;				   // 물공인지 마공인지

	int SkillDamage = 0;                           // 스킬공격력
	int MaxSkillPowerPoint = 0;                    // 최대 스킬 파워포인트
	int CurrentSkillPowerPoint = 0;                // 잔여 스킬 파워포인트
	float SkillHitrate = 0.f;                      // 스킬 명중률

	void InitCreateSkill(PokeSkill _SkillName);    // 최초 몬스터 생성 시 호출되는 스킬 Init 함수
	void ChangeSkill(PokeSkill _modifyskill);       // 스킬 선택 후 Change 하는 함수

	// 스킬 데이터 베이스
	void ScratchData();
	void GrowlData();
	void EmberData();
	void LeerData();
	void SlashData();
	void FlamethrowerData();
	void TackleData();
	void TailWhipData();
	void BubbleData();
	void WaterGunData();
	void WithdrawData();
	void SkullBashData();
	void HydroPumpData();
	void LeechSeedData();
	void VineWhipData();
	void RazorLeafData();
	void SleepPowderData();
	void SolarBeamData();
	void SandAttackData();
	void GustData();
	void QuickAttackData();
	void TwisterData();
	void FeatherDanceData();
	void WingAttackData();
	void AirSlashData();
	void PeckData();
	void FuryAttackData();
	void PursuitData();
	void FastMoveData();
	void AssuranceData();
	void DrillPeckData();
	void DefenseCurlData();
	void RockPolishData();
	void RockThrowData();
	void MagnitudeData();
	void SelfdestructData();
	void EarthquakeData();
	void StoneEdgeData();
	void BindData();
	void RockTombData();
	void DragonBreathData();
	void IronTailData();
	void SandTombData();
	void BiteData();
	void HyperFangData();
	void CrunchData();
	void SuperFangData();
	void DoubleEdgeData();
	void UnknownData();
};