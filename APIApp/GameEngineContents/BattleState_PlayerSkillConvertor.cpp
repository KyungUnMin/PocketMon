#include "BattleState_PlayerTurn.h"
#include "PokeSkillBase.h"
#include "BattlePlayerMonsterFSM.h"

BattlePlayerMonster_StateType BattleState_PlayerTurn::ConvertSkill(PokeSkill _SkillType)
{
	std::string SkillName = "";

	switch (_SkillType)
	{
	case PokeSkill::Tackle:
		return BattlePlayerMonster_StateType::Skill_Tackle;

	case PokeSkill::Growl:
		return BattlePlayerMonster_StateType::Skill_Growl;

	case PokeSkill::Leer:
		return BattlePlayerMonster_StateType::Skill_Leer;

	case PokeSkill::TailWhip:
		return BattlePlayerMonster_StateType::Skill_TailWhip;

	case PokeSkill::Earthquake:
		return BattlePlayerMonster_StateType::Skill_Earthquake;




	case PokeSkill::WaterGun:
		return BattlePlayerMonster_StateType::Skill_WaterGun;

	case PokeSkill::Bubble:
		return BattlePlayerMonster_StateType::Skill_Bubble;

	case PokeSkill::VineWhip:
		return BattlePlayerMonster_StateType::Skill_VineWhip;

	case PokeSkill::RazorLeaf:
		return BattlePlayerMonster_StateType::Skill_RazorLeaf;

	case PokeSkill::Thunder:
		return BattlePlayerMonster_StateType::Skill_Thunder;

	case PokeSkill::Thunderbolt:
		return BattlePlayerMonster_StateType::Skill_Thunderbolt;

	case PokeSkill::DragonBreath:
		return BattlePlayerMonster_StateType::Skill_DragonBreath;

	case PokeSkill::DoubleEdge:
		return BattlePlayerMonster_StateType::Skill_DoubleEdge;

	case PokeSkill::Bite:
		return BattlePlayerMonster_StateType::Skill_Bite;

	case PokeSkill::HyperFang:
		return BattlePlayerMonster_StateType::Skill_HyperFang;

	case PokeSkill::AirSlash:
		return BattlePlayerMonster_StateType::Skill_AirSlash;

	case PokeSkill::Gust:
		return BattlePlayerMonster_StateType::Skill_Gust;

	case PokeSkill::QuickAttack:
		return BattlePlayerMonster_StateType::Skill_QuickAttack;





	case PokeSkill::Scratch:
		return BattlePlayerMonster_StateType::Skill_Scratch;

	case PokeSkill::FeatherDance:
		return BattlePlayerMonster_StateType::Skill_FeatherDance;

	case PokeSkill::Ember:
		return BattlePlayerMonster_StateType::Skill_Ember;

	case PokeSkill::Flamethrower:
		return BattlePlayerMonster_StateType::Skill_Flamethrower;

	case PokeSkill::DefenseCurl:
		return BattlePlayerMonster_StateType::Skill_DefenseCurl;

	case PokeSkill::Magnitude:
		return BattlePlayerMonster_StateType::Skill_IronDefense;

	case PokeSkill::RockThrow:
		return BattlePlayerMonster_StateType::Skill_RockThrow;

	case PokeSkill::SuperFang:
		return BattlePlayerMonster_StateType::Skill_SuperFang;

	case PokeSkill::FastMove:
		return BattlePlayerMonster_StateType::Skill_Agility;

	case PokeSkill::Peck:
		return BattlePlayerMonster_StateType::Skill_Tackle;


	


	case PokeSkill::Slash:
		SkillName = "Slash";
	case PokeSkill::RockPolish:
		SkillName = "RockPolish";
	case PokeSkill::Withdraw:
		SkillName = "Withdraw";
	case PokeSkill::HydroPump:
		SkillName = "HydroPump";
	case PokeSkill::SolarBeam:
		SkillName = "SolarBeam";
	case PokeSkill::Bind:
		SkillName = "Bind";
	case PokeSkill::Twister:
		SkillName = "Twister";
	case PokeSkill::DrillPeck:
		SkillName = "DrillPeck";
	case PokeSkill::StoneEdge:
		SkillName = "StoneEdge";
	case PokeSkill::RockTomb:
		SkillName = "RockTomb";
	case PokeSkill::LeechSeed:
		SkillName = "LeechSeed";
	case PokeSkill::SleepPowder:
		SkillName = "SleepPowder";
	case PokeSkill::SandAttack:
		SkillName = "SandAttack";
	case PokeSkill::Selfdestruct:
		SkillName = "Selfdestruct";
	case PokeSkill::SkullBash:
		SkillName = "SkullBash";
	case PokeSkill::FuryAttack:
		SkillName = "FuryAttack";
	case PokeSkill::Pursuit:
		SkillName = "Pursuit";
	case PokeSkill::Assurance:
		SkillName = "Assurance";
	case PokeSkill::IronTail:
		SkillName = "IronTail";
	case PokeSkill::WingAttack:
		SkillName = "WingAttack";
	case PokeSkill::SandTomb:
		SkillName = "SandTomb";
	case PokeSkill::Crunch:
		SkillName = "Crunch";
	
	default:
		SkillName = "???";
	}
	
	SkillName += " 스킬은 아직 만들지 않았거나 연결해주지 않은 스킬입니다.\n 몸통박치기로 대체합니다\n";
	DebugMsgBox(SkillName);
	return BattlePlayerMonster_StateType::Skill_Tackle;
}

const std::string_view BattleState_PlayerTurn::ConvertSkillNames[static_cast<size_t>(PokeSkill::Unknown)] =
{
	"Scratch",      // 0 할퀴기
	"Growl",        // 1 울음소리
	"Ember",        // 2 불꽃세례
	"Leer",         // 3 째려보기
	"Slash",        // 4 베어가르기
	"Flamethrower", // 5 화염방사
	"Tackle",       // 6 몸통박치기
	"TailWhip",     // 7 꼬리흔들기
	"Bubble",       // 8 거품
	"WaterGun",     // 9 물대포
	"Withdraw",     // 10 껍질에숨기
	"SkullBash",    // 11 로케트박치기
	"HydroPump",    // 12 하이드로펌프
	"LeechSeed",    // 13 씨뿌리기
	"VineWhip",     // 14 덩굴채찍
	"RazorLeaf",    // 15 잎날가르기
	"SleepPowder",  // 16 수면가루
	"SolarBeam",    // 17 솔라빔
	"SandAttack",   // 18 모래뿌리기
	"Gust",         // 19 바람일으키기
	"QuickAttack",  // 20 전광석화
	"Twister",      // 21 회오리
	"FeatherDance", // 22 깃털댄스
	"WingAttack",   // 23 날개치기
	"AirSlash",     // 24 에어슬래시
	"Peck",         // 25 쪼기
	"FuryAttack",   // 26 마구찌르기
	"Pursuit",      // 27 따라가때리기
	"FastMove",     // 28 고속이동
	"Assurance",    // 29 승부굳히기
	"DrillPeck",    // 30 회전부리
	"DefenseCurl",  // 31 웅크리기
	"RockPolish",   // 32 록커트
	"RockThrow",    // 33 돌떨구기
	"Magnitude",    // 34 매그니튜드
	"Selfdestruct", // 35 자폭
	"Earthquake",   // 36 지진
	"StoneEdge",    // 37 스톤에지
	"Bind",         // 38 조이기
	"RockTomb",     // 39 암석봉인
	"DragonBreath", // 40 용의숨결
	"IronTail",     // 41 아이언테일
	"SandTomb",     // 42 모래지옥
	"Bite",         // 43 물기
	"HyperFang",    // 44 필살앞니
	"Crunch",       // 45 깨물어부수기
	"SuperFang",    // 46 분노의앞니
	"DoubleEdge",   // 47 이판사판태클
	"Thunderbolt",
	"Thunder",
};