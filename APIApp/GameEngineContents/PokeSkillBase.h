#pragma once

#include <string>
#include <map>

enum class PokeSkill
{
	Scratch,      // 할퀴기
	Growl,        // 울음소리
	Ember,        // 불꽃세례
	Leer,         // 째려보기
	Slash,        // 베어가르기
	Flamethrower, // 화염방사
	Tackle,       // 몸통박치기
	TailWhip,     // 꼬리흔들기
	Bubble,       // 거품
	WaterGun,     // 물대포
	Withdraw,     // 껍질에숨기
	SkullBash,    // 로케트박치기
	HydroPump,    // 하이드로펌프
	LeechSeed,    // 씨뿌리기
	VineWhip,     // 덩굴채찍
	RazorLeaf,    // 잎날가르기
	SleepPowder,  // 수면가루
	SolarBeam,    // 솔라빔
	SandAttack,   // 모래뿌리기
	Gust,         // 바람일으키기
	QuickAttack,  // 전광석화
	Twister,      // 회오리
	FeatherDance, // 깃털댄스
	WingAttack,   // 날개치기
	AirSlash,     // 에어슬래시
	Peck,         // 쪼기
	FuryAttack,   // 마구찌르기
	Pursuit,      // 따라가때리기
	FastMove,     // 고속이동
	Assurance,    // 승부굳히기
	DrillPeck,    // 회전부리
	DefenseCurl,  // 웅크리기
	RockPolish,   // 록커트
	RockThrow,    // 돌떨구기
	Magnitude,    // 매그니튜드
	Selfdestruct, // 자폭
	Earthquake,   // 지진
	StoneEdge,    // 스톤에지
	Bind,         // 조이기
	RockTomb,     // 암석봉인
	DragonBreath, // 용의숨결
	IronTail,     // 아이언테일
	SandTomb,     // 모래지옥
	Bite,         // 물기
	HyperFang,    // 필살앞니
	Crunch,       // 깨물어부수기
	SuperFang,    // 분노의앞니
	DoubleEdge,   // 이판사판태클
};

enum class SkillType
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

protected:

private:
	PokeSkill Skills = PokeSkill::Tackle;         // 스킬 이름
	SkillType SkillType = SkillType::Normal;      // 스킬 타입

	bool IsAttackSkill = true;                    // 공격스킬인지 버프스킬인지

	int SkillDamage = 0;                          // 스킬공격력
	int MaxSkillPowerPoint = 0;                   // 최대 스킬 파워포인트
	int CurrentSkillPowerPoint = 0;               // 잔여 스킬 파워포인트
	float SkillHitrate = 0.f;                     // 스킬 명중률

	void CreateSkill(PokeSkill _SkillName);
	void InitCreateSkill(PokeSkill _SkillName);

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
};