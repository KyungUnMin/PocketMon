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



	case PokeSkill::Slash:
		SkillName = "Slash";
	case PokeSkill::FastMove:
		SkillName = "FastMove";
	case PokeSkill::Magnitude:
		SkillName = "Magnitude";
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
	case PokeSkill::RockThrow:
		SkillName = "RockThrow";
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
	case PokeSkill::Peck:
		SkillName = "Peck";
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
	case PokeSkill::SuperFang:
		SkillName = "SuperFang";
	default:
		SkillName = "???";
	}
	
	SkillName += " 스킬은 아직 만들지 않았거나 연결해주지 않은 스킬입니다.\n 몸통박치기로 대체합니다\n";
	DebugMsgBox(SkillName);
	return BattlePlayerMonster_StateType::Skill_Tackle;
}

