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
		
	case PokeSkill::DragonBreath:
		return BattleEnemyMonster_StateType::Skill_DragonBreath;
	
	case PokeSkill::Magnitude:
		return BattleEnemyMonster_StateType::Skill_IronDefense;


	case PokeSkill::RockThrow:
		return BattleEnemyMonster_StateType::Skill_RockThrow;

	case PokeSkill::SuperFang:
		return BattleEnemyMonster_StateType::Skill_SuperFang;

	case PokeSkill::FastMove:
		return BattleEnemyMonster_StateType::Skill_Agility;

	case PokeSkill::Peck:
		return BattleEnemyMonster_StateType::Skill_Tackle;


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
	case PokeSkill::FuryAttack:
		SkillName = "FuryAttack";
		break;
	case PokeSkill::Pursuit:
		SkillName = "Pursuit";
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
	case PokeSkill::DoubleEdge:
		SkillName = "DoubleEdge";
		break;
	default:
		SkillName = "????";
		break;
	}

	SkillName += " ��ų�� ���� ������ �ʾҰų� ���������� ���� ��ų�Դϴ�.\n �����ġ��� ��ü�մϴ�\n";
	DebugMsgBox(SkillName);
	return BattleEnemyMonster_StateType::Skill_Tackle;
}


const std::string_view BattleState_EnemyTurn::ConvertSkillNames[static_cast<size_t>(PokeSkill::Unknown)] =
{
	"Scratch",      // 0 ������
	"Growl",        // 1 �����Ҹ�
	"Ember",        // 2 �Ҳɼ���
	"Leer",         // 3 °������
	"Slash",        // 4 �������
	"Flamethrower", // 5 ȭ�����
	"Tackle",       // 6 �����ġ��
	"TailWhip",     // 7 ��������
	"Bubble",       // 8 ��ǰ
	"WaterGun",     // 9 ������
	"Withdraw",     // 10 ����������
	"SkullBash",    // 11 ����Ʈ��ġ��
	"HydroPump",    // 12 ���̵������
	"LeechSeed",    // 13 ���Ѹ���
	"VineWhip",     // 14 ����ä��
	"RazorLeaf",    // 15 �ٳ�������
	"SleepPowder",  // 16 ���鰡��
	"SolarBeam",    // 17 �ֶ��
	"SandAttack",   // 18 �𷡻Ѹ���
	"Gust",         // 19 �ٶ�����Ű��
	"QuickAttack",  // 20 ������ȭ
	"Twister",      // 21 ȸ����
	"FeatherDance", // 22 ���д�
	"WingAttack",   // 23 ����ġ��
	"AirSlash",     // 24 �������
	"Peck",         // 25 �ɱ�
	"FuryAttack",   // 26 �������
	"Pursuit",      // 27 ���󰡶�����
	"FastMove",     // 28 ����̵�
	"Assurance",    // 29 �ºα�����
	"DrillPeck",    // 30 ȸ���θ�
	"DefenseCurl",  // 31 ��ũ����
	"RockPolish",   // 32 ��ĿƮ
	"RockThrow",    // 33 ��������
	"Magnitude",    // 34 �ű״�Ʃ��
	"Selfdestruct", // 35 ����
	"Earthquake",   // 36 ����
	"StoneEdge",    // 37 ���濡��
	"Bind",         // 38 ���̱�
	"RockTomb",     // 39 �ϼ�����
	"DragonBreath", // 40 ���Ǽ���
	"IronTail",     // 41 ���̾�����
	"SandTomb",     // 42 ������
	"Bite",         // 43 ����
	"HyperFang",    // 44 �ʻ�մ�
	"Crunch",       // 45 ������μ���
	"SuperFang",    // 46 �г��Ǿմ�
	"DoubleEdge",   // 47 ���ǻ�����Ŭ
	"Thunderbolt",
	"Thunder",
};

//
//std::vector<const std::string_view> BattleState_EnemyTurn::ConvertSkillNames =
//{
//	"Scratch",      // 0 ������
//	"Growl",        // 1 �����Ҹ�
//	"Ember",        // 2 �Ҳɼ���
//	"Leer",         // 3 °������
//	"Slash",        // 4 �������
//	"Flamethrower", // 5 ȭ�����
//	"Tackle",       // 6 �����ġ��
//	"TailWhip",     // 7 ��������
//	"Bubble",       // 8 ��ǰ
//	"WaterGun",     // 9 ������
//	"Withdraw",     // 10 ����������
//	"SkullBash",    // 11 ����Ʈ��ġ��
//	"HydroPump",    // 12 ���̵������
//	"LeechSeed",    // 13 ���Ѹ���
//	"VineWhip",     // 14 ����ä��
//	"RazorLeaf",    // 15 �ٳ�������
//	"SleepPowder",  // 16 ���鰡��
//	"SolarBeam",    // 17 �ֶ��
//	"SandAttack",   // 18 �𷡻Ѹ���
//	"Gust",         // 19 �ٶ�����Ű��
//	"QuickAttack",  // 20 ������ȭ
//	"Twister",      // 21 ȸ����
//	"FeatherDance", // 22 ���д�
//	"WingAttack",   // 23 ����ġ��
//	"AirSlash",     // 24 �������
//	"Peck",         // 25 �ɱ�
//	"FuryAttack",   // 26 �������
//	"Pursuit",      // 27 ���󰡶�����
//	"FastMove",     // 28 ����̵�
//	"Assurance",    // 29 �ºα�����
//	"DrillPeck",    // 30 ȸ���θ�
//	"DefenseCurl",  // 31 ��ũ����
//	"RockPolish",   // 32 ��ĿƮ
//	"RockThrow",    // 33 ��������
//	"Magnitude",    // 34 �ű״�Ʃ��
//	"Selfdestruct", // 35 ����
//	"Earthquake",   // 36 ����
//	"StoneEdge",    // 37 ���濡��
//	"Bind",         // 38 ���̱�
//	"RockTomb",     // 39 �ϼ�����
//	"DragonBreath", // 40 ���Ǽ���
//	"IronTail",     // 41 ���̾�����
//	"SandTomb",     // 42 ������
//	"Bite",         // 43 ����
//	"HyperFang",    // 44 �ʻ�մ�
//	"Crunch",       // 45 ������μ���
//	"SuperFang",    // 46 �г��Ǿմ�
//	"DoubleEdge",   // 47 ���ǻ�����Ŭ
//	"Thunderbolt",
//	"Thunder",
//	"Unknown"      // 48 Max
//};