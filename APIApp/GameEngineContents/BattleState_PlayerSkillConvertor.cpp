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
	
	SkillName += " ��ų�� ���� ������ �ʾҰų� ���������� ���� ��ų�Դϴ�.\n �����ġ��� ��ü�մϴ�\n";
	DebugMsgBox(SkillName);
	return BattlePlayerMonster_StateType::Skill_Tackle;
}

const std::string_view BattleState_PlayerTurn::ConvertSkillNames[static_cast<size_t>(PokeSkill::Unknown)] =
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