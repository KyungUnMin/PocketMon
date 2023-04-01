#include "PokeSkillBase.h"

PokeSkillBase::PokeSkillBase() 
{
}

PokeSkillBase::~PokeSkillBase() 
{
}

void PokeSkillBase::ChangeSkill(PokeSkill _modifyskill)
{
	InitCreateSkill(_modifyskill);
}

// PokeDataBase() 클래스에서만 이용하는 몬스터 스킬 입력 함수입니다.
void PokeSkillBase::InitCreateSkill(PokeSkill _SkillName)
{
	Skills = _SkillName;

	switch (Skills)
	{
	case PokeSkill::Scratch:
		ScratchData();
		break;
	case PokeSkill::Growl:
		GrowlData();
		break;
	case PokeSkill::Ember:
		EmberData();
		break;
	case PokeSkill::Leer:
		LeerData();
		break;
	case PokeSkill::Slash:
		SlashData();
		break;
	case PokeSkill::Flamethrower:
		FlamethrowerData();
		break;
	case PokeSkill::Tackle:
		TackleData();
		break;
	case PokeSkill::TailWhip:
		TailWhipData();
		break;
	case PokeSkill::Bubble:
		BubbleData();
		break;
	case PokeSkill::WaterGun:
		WaterGunData();
		break;
	case PokeSkill::Withdraw:
		WithdrawData();
		break;
	case PokeSkill::SkullBash:
		SkullBashData();
		break;
	case PokeSkill::HydroPump:
		HydroPumpData();
		break;
	case PokeSkill::LeechSeed:
		LeechSeedData();
		break;
	case PokeSkill::VineWhip:
		VineWhipData();
		break;
	case PokeSkill::RazorLeaf:
		RazorLeafData();
		break;
	case PokeSkill::SleepPowder:
		SleepPowderData();
		break;
	case PokeSkill::SolarBeam:
		SolarBeamData();
		break;
	case PokeSkill::SandAttack:
		SandAttackData();
		break;
	case PokeSkill::Gust:
		GustData();
		break;
	case PokeSkill::QuickAttack:
		QuickAttackData();
		break;
	case PokeSkill::Twister:
		TwisterData();
		break;
	case PokeSkill::FeatherDance:
		FeatherDanceData();
		break;
	case PokeSkill::WingAttack:
		WingAttackData();
		break;
	case PokeSkill::AirSlash:
		AirSlashData();
		break;
	case PokeSkill::Peck:
		PeckData();
		break;
	case PokeSkill::FuryAttack:
		FuryAttackData();
		break;
	case PokeSkill::Pursuit:
		PursuitData();
		break;
	case PokeSkill::FastMove:
		FastMoveData();
		break;
	case PokeSkill::Assurance:
		AssuranceData();
		break;
	case PokeSkill::DrillPeck:
		DrillPeckData();
		break;
	case PokeSkill::DefenseCurl:
		DefenseCurlData();
		break;
	case PokeSkill::RockPolish:
		RockPolishData();
		break;
	case PokeSkill::RockThrow:
		RockThrowData();
		break;
	case PokeSkill::Magnitude:
		MagnitudeData();
		break;
	case PokeSkill::Selfdestruct:
		SelfdestructData();
		break;
	case PokeSkill::Earthquake:
		EarthquakeData();
		break;
	case PokeSkill::StoneEdge:
		StoneEdgeData();
		break;
	case PokeSkill::Bind:
		BindData();
		break;
	case PokeSkill::RockTomb:
		RockTombData();
		break;
	case PokeSkill::DragonBreath:
		DragonBreathData();
		break;
	case PokeSkill::IronTail:
		IronTailData();
		break;
	case PokeSkill::SandTomb:
		SandTombData();
		break;
	case PokeSkill::Bite:
		BiteData();
		break;
	case PokeSkill::HyperFang:
		HyperFangData();
		break;
	case PokeSkill::Crunch:
		CrunchData();
		break;
	case PokeSkill::SuperFang:
		SuperFangData();
		break;
	case PokeSkill::DoubleEdge:
		DoubleEdgeData();
		break;
	case PokeSkill::Thunderbolt:
		ThunderboltData();
		break;
	case PokeSkill::Thunder:
		ThunderData();
		break;
	case PokeSkill::Unknown:
		UnknownData();
		break;
	default:
		break;
	}
}

//////////////////////////////////////////////////////////////// 푸키먼 스킬 데이터

// CreateSkill(), InitCreateSkill() 함수를 호출하면 해당 구역의 함수를 연계적으로 호출하여 데이터를 입력해줍니다.

// 할퀴기
void PokeSkillBase::ScratchData() 
{
	IsAttackSkill = true;            // 공격 스킬인지, 버프(디버프) 스킬인지 확인
	SkillType = SkillType::Normal;   // 스킬공격 타입 설정
	Name = "Scratch";                // 스킬 이름 설정

	SkillDamage = 40;                // 스킬공격력 설정
	MaxSkillPowerPoint = 35;         // 스킬 최대 파워포인트 설정
	CurrentSkillPowerPoint = 35;     // 스킬 잔여 파워포인트 설정
	SkillHitrate = 1.0f;             // 스킬 명중률 설정
}

// 울음소리
void PokeSkillBase::GrowlData() 
{
	IsAttackSkill = false;           
	SkillType = SkillType::Normal;   
	Name = "Growl";

	SkillDamage = 0;                
	MaxSkillPowerPoint = 40;         
	CurrentSkillPowerPoint = 40;     
	SkillHitrate = 1.0f;             
}

// 불꽃세례
void PokeSkillBase::EmberData()
{
	IsAttackSkill = true;
	SkillType = SkillType::Fire;
	Name = "Ember";

	SkillDamage = 40;
	MaxSkillPowerPoint = 25;
	CurrentSkillPowerPoint = 25;
	SkillHitrate = 1.0f;
}

// 째려보기
void PokeSkillBase::LeerData()
{
	IsAttackSkill = false;
	SkillType = SkillType::Normal;
	Name = "Leer";

	SkillDamage = 0;
	MaxSkillPowerPoint = 30;
	CurrentSkillPowerPoint = 30;
	SkillHitrate = 1.0f;
}

// 베어가르기
void PokeSkillBase::SlashData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Normal;
	Name = "Slash";

	SkillDamage = 70;
	MaxSkillPowerPoint = 20;
	CurrentSkillPowerPoint = 20;
	SkillHitrate = 1.0f;
}

// 화염방사
void PokeSkillBase::FlamethrowerData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Fire;
	Name = "Flamethrower";

	SkillDamage = 95;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 1.0f;
}

// 몸통박치기
void PokeSkillBase::TackleData()
{
	IsAttackSkill = true;
	SkillType = SkillType::Normal;
	Name = "Tackle";

	SkillDamage = 40;
	MaxSkillPowerPoint = 35;
	CurrentSkillPowerPoint = 35;
	SkillHitrate = 0.95f;
}

// 꼬리흔들기
void PokeSkillBase::TailWhipData() 
{
	IsAttackSkill = false;
	SkillType = SkillType::Normal;
	Name = "TailWhip";

	SkillDamage = 0;
	MaxSkillPowerPoint = 40;
	CurrentSkillPowerPoint = 40;
	SkillHitrate = 1.f;
}

// 거품
void PokeSkillBase::BubbleData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Water;
	Name = "Bubble";

	SkillDamage = 20;
	MaxSkillPowerPoint = 30;
	CurrentSkillPowerPoint = 30;
	SkillHitrate = 1.f;
}

// 물대포
void PokeSkillBase::WaterGunData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Water;
	Name = "WaterGun";

	SkillDamage = 40;
	MaxSkillPowerPoint = 25;
	CurrentSkillPowerPoint = 25;
	SkillHitrate = 1.f;
}

// 껍질에숨기
void PokeSkillBase::WithdrawData()
{
	IsAttackSkill = false;
	SkillType = SkillType::Water;
	Name = "Withdraw";

	SkillDamage = 0;
	MaxSkillPowerPoint = 40;
	CurrentSkillPowerPoint = 40;
	SkillHitrate = 1.f;
}

// 로케트박치기
void PokeSkillBase::SkullBashData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Normal;
	Name = "SkullBash";

	SkillDamage = 100;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 1.f;
}

// 하이드로펌프
void PokeSkillBase::HydroPumpData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Water;
	Name = "HydroPump";

	SkillDamage = 120;
	MaxSkillPowerPoint = 5;
	CurrentSkillPowerPoint = 5;
	SkillHitrate = 0.8f;
}

// 씨뿌리기
void PokeSkillBase::LeechSeedData() 
{
	IsAttackSkill = false;
	SkillType = SkillType::Grass;
	Name = "LeechSeed";

	SkillDamage = 0;
	MaxSkillPowerPoint = 10;
	CurrentSkillPowerPoint = 10;
	SkillHitrate = 0.9f;
}

// 덩굴채찍
void PokeSkillBase::VineWhipData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Grass;
	Name = "VineWhip";

	SkillDamage = 35;
	MaxSkillPowerPoint = 10;
	CurrentSkillPowerPoint = 10;
	SkillHitrate = 1.f;
}

// 잎날가르기
void PokeSkillBase::RazorLeafData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Grass;
	Name = "RazorLeaf";

	SkillDamage = 55;
	MaxSkillPowerPoint = 25;
	CurrentSkillPowerPoint = 25;
	SkillHitrate = 0.95f;
}

// 수면가루
void PokeSkillBase::SleepPowderData() 
{
	IsAttackSkill = false;
	SkillType = SkillType::Grass;
	Name = "SleepPowder";

	SkillDamage = 55;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 0.75f;
}

// 솔라빔 (기모으기 한 턴)
void PokeSkillBase::SolarBeamData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Grass;
	Name = "SolarBeam";

	SkillDamage = 120;
	MaxSkillPowerPoint = 10;
	CurrentSkillPowerPoint = 10;
	SkillHitrate = 1.f;
}

// 모래뿌리기
void PokeSkillBase::SandAttackData() 
{
	IsAttackSkill = false;
	SkillType = SkillType::Ground;
	Name = "SandAttack";

	SkillDamage = 0;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 1.f;
}

// 바람일으키기
void PokeSkillBase::GustData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Flying;
	Name = "Gust";

	SkillDamage = 40;
	MaxSkillPowerPoint = 35;
	CurrentSkillPowerPoint = 35;
	SkillHitrate = 1.f;
}

// 전광석화
void PokeSkillBase::QuickAttackData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Normal;
	Name = "QuickAttack";

	SkillDamage = 40;
	MaxSkillPowerPoint = 30;
	CurrentSkillPowerPoint = 30;
	SkillHitrate = 1.f;
}

// 회오리
void PokeSkillBase::TwisterData() 
{
	IsAttackSkill = true;
	IsSpecialSkill = true;
	SkillType = SkillType::Dragon;
	Name = "Twister";

	SkillDamage = 40;
	MaxSkillPowerPoint = 20;
	CurrentSkillPowerPoint = 20;
	SkillHitrate = 1.f;
}

// 깃털댄스
void PokeSkillBase::FeatherDanceData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Flying;
	Name = "FeatherDance";

	SkillDamage = 0;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 1.f;
}

// 날개치기
void PokeSkillBase::WingAttackData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Flying;
	Name = "WingAttack";

	SkillDamage = 60;
	MaxSkillPowerPoint = 35;
	CurrentSkillPowerPoint = 35;
	SkillHitrate = 1.f;
}

// 에어슬래시
void PokeSkillBase::AirSlashData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Flying;
	Name = "AirSlash";

	SkillDamage = 75;
	MaxSkillPowerPoint = 20;
	CurrentSkillPowerPoint = 20;
	SkillHitrate = 0.95f;
}

// 쪼기
void PokeSkillBase::PeckData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Flying;
	Name = "Peck";

	SkillDamage = 35;
	MaxSkillPowerPoint = 35;
	CurrentSkillPowerPoint = 35;
	SkillHitrate = 1.f;
}

// 마구찌르기 (최대 3번 공격)
void PokeSkillBase::FuryAttackData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Normal;
	Name = "FuryAttack";

	SkillDamage = 15;
	MaxSkillPowerPoint = 20;
	CurrentSkillPowerPoint = 20;
	SkillHitrate = 0.85f;
}

// 따라가때리기 (도망가도 때림)
void PokeSkillBase::PursuitData() 
{
	IsAttackSkill = true;
	IsSpecialSkill = true;
	SkillType = SkillType::Drak;
	Name = "Pursuit";

	SkillDamage = 40;
	MaxSkillPowerPoint = 20;
	CurrentSkillPowerPoint = 20;
	SkillHitrate = 1.f;
}

// 고속이동
void PokeSkillBase::FastMoveData() 
{
	IsAttackSkill = false;
	IsSpecialSkill = true;
	SkillType = SkillType::Psvchc;
	Name = "FastMove";

	SkillDamage = 0;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 1.f;
}

// 승부굳히기
void PokeSkillBase::AssuranceData() 
{
	IsAttackSkill = true;
	IsSpecialSkill = true;
	SkillType = SkillType::Drak;
	Name = "Assurance";

	SkillDamage = 50;
	MaxSkillPowerPoint = 10;
	CurrentSkillPowerPoint = 10;
	SkillHitrate = 1.f;
}

// 회전부리
void PokeSkillBase::DrillPeckData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Flying;
	Name = "DrillPeck";

	SkillDamage = 80;
	MaxSkillPowerPoint = 20;
	CurrentSkillPowerPoint = 20;
	SkillHitrate = 1.f;
}

// 웅크리기
void PokeSkillBase::DefenseCurlData() 
{
	IsAttackSkill = false;
	SkillType = SkillType::Normal;
	Name = "DefenseCurl";

	SkillDamage = 0;
	MaxSkillPowerPoint = 40;
	CurrentSkillPowerPoint = 40;
	SkillHitrate = 1.f;
}

// 록커트
void PokeSkillBase::RockPolishData() 
{
	IsAttackSkill = false;
	SkillType = SkillType::Rock;
	Name = "RockPolish";

	SkillDamage = 0;
	MaxSkillPowerPoint = 20;
	CurrentSkillPowerPoint = 20;
	SkillHitrate = 1.f;
}

// 돌떨구기
void PokeSkillBase::RockThrowData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Rock;
	Name = "RockThrow";

	SkillDamage = 50;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 1.f;
}

// 매그니튜드
void PokeSkillBase::MagnitudeData() 
{
	IsAttackSkill = false;
	SkillType = SkillType::Ground;
	Name = "Magnitude";

	SkillDamage = 0;
	MaxSkillPowerPoint = 30;
	CurrentSkillPowerPoint = 30;
	SkillHitrate = 1.f;
}

// 자폭
void PokeSkillBase::SelfdestructData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Normal;
	Name = "Selfdestruct";

	SkillDamage = 200;
	MaxSkillPowerPoint = 5;
	CurrentSkillPowerPoint = 5;
	SkillHitrate = 1.f;
}

// 지진
void PokeSkillBase::EarthquakeData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Ground;
	Name = "Earthquake";

	SkillDamage = 100;
	MaxSkillPowerPoint = 10;
	CurrentSkillPowerPoint = 10;
	SkillHitrate = 1.f;
}

// 스톤에지
void PokeSkillBase::StoneEdgeData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Rock;
	Name = "StoneEdge";

	SkillDamage = 100;
	MaxSkillPowerPoint = 5;
	CurrentSkillPowerPoint = 5;
	SkillHitrate = 0.8f;
}

// 조이기 (지속 뎀)
void PokeSkillBase::BindData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Normal;
	Name = "Bind";

	SkillDamage = 15;
	MaxSkillPowerPoint = 30;
	CurrentSkillPowerPoint = 30;
	SkillHitrate = 0.75f;
}

// 암석봉인
void PokeSkillBase::RockTombData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Rock;
	Name = "RockTomb";

	SkillDamage = 50;
	MaxSkillPowerPoint = 10;
	CurrentSkillPowerPoint = 10;
	SkillHitrate = 0.8f;
}

// 용의숨결
void PokeSkillBase::DragonBreathData() 
{
	IsAttackSkill = true;
	IsSpecialSkill = true;
	SkillType = SkillType::Dragon;
	Name = "DragonBreath";

	SkillDamage = 60;
	MaxSkillPowerPoint = 20;
	CurrentSkillPowerPoint = 20;
	SkillHitrate = 1.f;
}

// 아이언테일
void PokeSkillBase::IronTailData() 
{
	IsAttackSkill = true;
	SkillType = SkillType::Steel;
	Name = "IronTail";

	SkillDamage = 100;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 0.75f;
}

// 모래지옥 (지속뎀)
void PokeSkillBase::SandTombData() 
{
	IsAttackSkill = false;
	SkillType = SkillType::Ground;
	Name = "SandTomb";

	SkillDamage = 15;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 0.7f;
}

// 물기
void PokeSkillBase::BiteData()
{
	IsAttackSkill = true;
	IsSpecialSkill = true;
	SkillType = SkillType::Drak;
	Name = "Bite";

	SkillDamage = 60;
	MaxSkillPowerPoint = 25;
	CurrentSkillPowerPoint = 25;
	SkillHitrate = 1.f;
}

// 필살앞니
void PokeSkillBase::HyperFangData()
{
	IsAttackSkill = true;
	SkillType = SkillType::Normal;
	Name = "HyperFang";

	SkillDamage = 80;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 1.f;
}

// 깨물어부수기
void PokeSkillBase::CrunchData()
{
	IsAttackSkill = true;
	IsSpecialSkill = true;
	SkillType = SkillType::Drak;
	Name = "Crunch";

	SkillDamage = 80;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 1.f;
}

// 분노의앞니
void PokeSkillBase::SuperFangData()
{
	IsAttackSkill = false;
	SkillType = SkillType::Normal;
	Name = "SuperFang";

	SkillDamage = 0;
	MaxSkillPowerPoint = 10;
	CurrentSkillPowerPoint = 10;
	SkillHitrate = 1.f;
}

// 이판사판태클
void PokeSkillBase::DoubleEdgeData()
{
	IsAttackSkill = true;
	SkillType = SkillType::Normal;
	Name = "DoubleEdge";

	SkillDamage = 120;
	MaxSkillPowerPoint = 5;
	CurrentSkillPowerPoint = 5;
	SkillHitrate = 1.f;
}

void PokeSkillBase::ThunderboltData()
{
	IsAttackSkill = true;
	SkillType = SkillType::Electro;
	Name = "Thunderbolt";

	SkillDamage = 95;
	MaxSkillPowerPoint = 15;
	CurrentSkillPowerPoint = 15;
	SkillHitrate = 1.f;
}

void PokeSkillBase::ThunderData()
{
	IsAttackSkill = true;
	SkillType = SkillType::Electro;
	Name = "Thunder";

	SkillDamage = 120;
	MaxSkillPowerPoint = 10;
	CurrentSkillPowerPoint = 10;
	SkillHitrate = 0.7f;
}

void PokeSkillBase::UnknownData()
{
	IsAttackSkill = false;
	SkillType = SkillType::Bug;
	Name = "Unknown";

	SkillDamage = 0;
	MaxSkillPowerPoint = 0;
	CurrentSkillPowerPoint = 0;
	SkillHitrate = 0.f;
}
