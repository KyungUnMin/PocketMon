#include "BattleState_EnemyTurn.h"
#include <GameEngineBase/GameEngineDebug.h>
#include "BattleEnemyMonsterFSM.h"

BattleEnemyMonster_StateType BattleState_EnemyTurn::ConvertSkill(PokeSkill _SkillType)
{
	std::string SkillName = "";

	switch (_SkillType)
	{
	case PokeSkill::Tackle:
		return BattleEnemyMonster_StateType::Skill_Tackle;
	case PokeSkill::Growl:
		return BattleEnemyMonster_StateType::Skill_Growl;
	case PokeSkill::Leer:
		return BattleEnemyMonster_StateType::Skill_Leer;
	case PokeSkill::Earthquake:
		return BattleEnemyMonster_StateType::Skill_Earthquake;
	case PokeSkill::TailWhip:
		return BattleEnemyMonster_StateType::Skill_TailWhip;



	case PokeSkill::QuickAttack:
		return BattleEnemyMonster_StateType::Skill_QuickAttack;
	case PokeSkill::Gust:
		return BattleEnemyMonster_StateType::Skill_Gust;
	case PokeSkill::Thunderbolt :
		return BattleEnemyMonster_StateType::Skill_Thunderbolt;
	case PokeSkill::Thunder:
		return BattleEnemyMonster_StateType::Skill_Thunder;
	case PokeSkill::WaterGun:
		return BattleEnemyMonster_StateType::Skill_WaterGun;
	case PokeSkill::Bubble:
		return BattleEnemyMonster_StateType::Skill_Bubble;
	case PokeSkill::VineWhip:
		return BattleEnemyMonster_StateType::Skill_VineWhip;
	case PokeSkill::RazorLeaf:
		return BattleEnemyMonster_StateType::Skill_RazorLeaf;



	case PokeSkill::Scratch:
		return BattleEnemyMonster_StateType::Skill_Scratch;
	case PokeSkill::FeatherDance:
		return BattleEnemyMonster_StateType::Skill_FeatherDance;
	case PokeSkill::Ember:
		return BattleEnemyMonster_StateType::Skill_Ember;

	case PokeSkill::Flamethrower:
		return BattleEnemyMonster_StateType::Skill_Flamethrower;

	case PokeSkill::DefenseCurl:
		return BattleEnemyMonster_StateType::Skill_DefenseCurl;
		break;


	case PokeSkill::Slash:
		SkillName = "Slash";
		break;
	
	case PokeSkill::Withdraw:
		SkillName = "Withdraw";
		break;
	case PokeSkill::SkullBash:
		SkillName = "SkullBash";
		break;
	case PokeSkill::HydroPump:
		SkillName = "HydroPump";
		break;
	case PokeSkill::LeechSeed:
		SkillName = "LeechSeed";
		break;
	case PokeSkill::SleepPowder:
		SkillName = "SleepPowder";
		break;
	case PokeSkill::SolarBeam:
		SkillName = "SolarBeam";
		break;
	case PokeSkill::SandAttack:
		SkillName = "SandAttack";
		break;
	case PokeSkill::Twister:
		SkillName = "Twister";
		break;
	case PokeSkill::WingAttack:
		SkillName = "WingAttack";
		break;
	case PokeSkill::AirSlash:
		SkillName = "AirSlash";
		break;
	case PokeSkill::Peck:
		SkillName = "Peck";
		break;
	case PokeSkill::FuryAttack:
		SkillName = "FuryAttack";
		break;
	case PokeSkill::Pursuit:
		SkillName = "Pursuit";
		break;
	case PokeSkill::FastMove:
		SkillName = "FastMove";
		break;
	case PokeSkill::Assurance:
		SkillName = "Assurance";
		break;
	case PokeSkill::DrillPeck:
		SkillName = "DrillPeck";
		break;
	
	case PokeSkill::RockPolish:
		SkillName = "RockPolish";
		break;
	case PokeSkill::RockThrow:
		SkillName = "RockThrow";
		break;
	case PokeSkill::Magnitude:
		SkillName = "Magnitude";
		break;
	case PokeSkill::Selfdestruct:
		SkillName = "Selfdestruct";
		break;
	case PokeSkill::StoneEdge:
		SkillName = "StoneEdge";
		break;
	case PokeSkill::Bind:
		SkillName = "Bind";
		break;
	case PokeSkill::RockTomb:
		SkillName = "RockTomb";
		break;
	case PokeSkill::DragonBreath:
		SkillName = "DragonBreath";
		break;
	case PokeSkill::IronTail:
		SkillName = "IronTail";
		break;
	case PokeSkill::SandTomb:
		SkillName = "SandTomb";
		break;
	case PokeSkill::Bite:
		SkillName = "Bite";
		break;
	case PokeSkill::HyperFang:
		SkillName = "HyperFang";
		break;
	case PokeSkill::Crunch:
		SkillName = "Crunch";
		break;
	case PokeSkill::SuperFang:
		SkillName = "SuperFang";
		break;
	case PokeSkill::DoubleEdge:
		SkillName = "DoubleEdge";
		break;
	default:
		SkillName = "????";
		break;
	}

	SkillName += " 스킬은 아직 만들지 않았거나 연결해주지 않은 스킬입니다.\n 몸통박치기로 대체합니다\n";
	DebugMsgBox(SkillName);
	return BattleEnemyMonster_StateType::Skill_Tackle;
}