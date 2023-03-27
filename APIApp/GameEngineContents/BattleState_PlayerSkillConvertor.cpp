#include "BattleState_PlayerTurn.h"
#include "PokeSkillBase.h"
#include "BattlePlayerMonsterFSM.h"

BattlePlayerMonster_StateType BattleState_PlayerTurn::ConvertSkill(PokeSkill _SkillType)
{
	switch (_SkillType)
	{
	case PokeSkill::Tackle:
	case PokeSkill::SkullBash:
	case PokeSkill::DoubleEdge:
	case PokeSkill::QuickAttack:
	case PokeSkill::Peck:
	case PokeSkill::FuryAttack:
	case PokeSkill::Pursuit:
	case PokeSkill::Assurance:
	case PokeSkill::IronTail:
	case PokeSkill::WingAttack:
		return BattlePlayerMonster_StateType::Skill_Tackle;

	case PokeSkill::Slash:
	case PokeSkill::Scratch:
	case PokeSkill::AirSlash:
	case PokeSkill::Bite:
	case PokeSkill::HyperFang:
	{
		MsgAssert("아직 안 만들었습니다");
		return BattlePlayerMonster_StateType::COUNT;
	}


	case PokeSkill::FeatherDance:
	case PokeSkill::FastMove:
	{
		MsgAssert("아직 안 만들었습니다");
		return BattlePlayerMonster_StateType::COUNT;
	}


	case PokeSkill::Magnitude:
	case PokeSkill::RockPolish:
	case PokeSkill::DefenseCurl:
	case PokeSkill::Withdraw:
	{
		MsgAssert("아직 안 만들었습니다");
		return BattlePlayerMonster_StateType::COUNT;
	}
		

	case PokeSkill::Ember:
	case PokeSkill::DragonBreath:
	case PokeSkill::Flamethrower:
	{
		MsgAssert("아직 안 만들었습니다");
		return BattlePlayerMonster_StateType::COUNT;
	}
		

	case PokeSkill::Bubble:
	case PokeSkill::WaterGun:
	case PokeSkill::HydroPump:
	case PokeSkill::SolarBeam:
	{
		MsgAssert("아직 안 만들었습니다");
		return BattlePlayerMonster_StateType::COUNT;
	}
		

	case PokeSkill::Bind:
	case PokeSkill::VineWhip:
	case PokeSkill::RazorLeaf:
	{
		MsgAssert("아직 안 만들었습니다");
		return BattlePlayerMonster_StateType::COUNT;
	}


	case PokeSkill::Twister:
	case PokeSkill::DrillPeck:
	case PokeSkill::Gust:
	{
		MsgAssert("아직 안 만들었습니다");
		return BattlePlayerMonster_StateType::COUNT;
	}
		

	case PokeSkill::RockThrow:
	case PokeSkill::StoneEdge:
	case PokeSkill::RockTomb:
	{
		MsgAssert("아직 안 만들었습니다");
		return BattlePlayerMonster_StateType::COUNT;
	}
		

	case PokeSkill::Growl:
	case PokeSkill::Leer:
	case PokeSkill::TailWhip:
	case PokeSkill::LeechSeed:
	case PokeSkill::SleepPowder:
	case PokeSkill::SandAttack:
	case PokeSkill::Selfdestruct:
	case PokeSkill::Earthquake:
	case PokeSkill::SandTomb:
	case PokeSkill::Crunch:
	case PokeSkill::SuperFang:
	case PokeSkill::Unknown:
	default:
		MsgAssert("사용하지 않는 스킬들입니다");
		break;
	}

	return BattlePlayerMonster_StateType::COUNT;
}