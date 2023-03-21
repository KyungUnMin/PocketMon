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

// PokeDataBase() Ŭ���������� �̿��ϴ� ���� ��ų �Է� �Լ��Դϴ�.
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
	case PokeSkill::Unknown:
		UnknownData();
		break;
	default:
		break;
	}
}

//////////////////////////////////////////////////////////////// ǪŰ�� ��ų ������

// CreateSkill(), InitCreateSkill() �Լ��� ȣ���ϸ� �ش� ������ �Լ��� ���������� ȣ���Ͽ� �����͸� �Է����ݴϴ�.

// ������
void PokeSkillBase::ScratchData() 
{
	IsAttackSkill = true;            // ���� ��ų����, ����(�����) ��ų���� Ȯ��
	SkillType = SkillType::Normal;   // ��ų���� Ÿ�� ����
	Name = "Scratch";                // ��ų �̸� ����

	SkillDamage = 40;                // ��ų���ݷ� ����
	MaxSkillPowerPoint = 35;         // ��ų �ִ� �Ŀ�����Ʈ ����
	CurrentSkillPowerPoint = 35;     // ��ų �ܿ� �Ŀ�����Ʈ ����
	SkillHitrate = 1.0f;             // ��ų ���߷� ����
}

// �����Ҹ�
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

// �Ҳɼ���
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

// °������
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

// �������
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

// ȭ�����
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

// �����ġ��
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

// ��������
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

// ��ǰ
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

// ������
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

// ����������
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

// ����Ʈ��ġ��
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

// ���̵������
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

// ���Ѹ���
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

// ����ä��
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

// �ٳ�������
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

// ���鰡��
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

// �ֶ�� (������� �� ��)
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

// �𷡻Ѹ���
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

// �ٶ�����Ű��
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

// ������ȭ
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

// ȸ����
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

// ���д�
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

// ����ġ��
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

// �������
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

// �ɱ�
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

// ������� (�ִ� 3�� ����)
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

// ���󰡶����� (�������� ����)
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

// ����̵�
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

// �ºα�����
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

// ȸ���θ�
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

// ��ũ����
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

// ��ĿƮ
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

// ��������
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

// �ű״�Ʃ��
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

// ����
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

// ����
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

// ���濡��
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

// ���̱� (���� ��)
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

// �ϼ�����
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

// ���Ǽ���
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

// ���̾�����
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

// ������ (���ӵ�)
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

// ����
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

// �ʻ�մ�
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

// ������μ���
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

// �г��Ǿմ�
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

// ���ǻ�����Ŭ
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