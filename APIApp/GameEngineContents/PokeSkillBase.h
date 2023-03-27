#pragma once

#include <string>
#include <map>

enum class PokeSkill
{
	Scratch,      // 0 ������
	Growl,        // 1 �����Ҹ�
	Ember,        // 2 �Ҳɼ���
	Leer,         // 3 °������
	Slash,        // 4 �������
	Flamethrower, // 5 ȭ�����
	Tackle,       // 6 �����ġ��
	TailWhip,     // 7 ��������
	Bubble,       // 8 ��ǰ
	WaterGun,     // 9 ������
	Withdraw,     // 10 ����������
	SkullBash,    // 11 ����Ʈ��ġ��
	HydroPump,    // 12 ���̵������
	LeechSeed,    // 13 ���Ѹ���
	VineWhip,     // 14 ����ä��
	RazorLeaf,    // 15 �ٳ�������
	SleepPowder,  // 16 ���鰡��
	SolarBeam,    // 17 �ֶ��
	SandAttack,   // 18 �𷡻Ѹ���
	Gust,         // 19 �ٶ�����Ű��
	QuickAttack,  // 20 ������ȭ
	Twister,      // 21 ȸ����
	FeatherDance, // 22 ���д�
	WingAttack,   // 23 ����ġ��
	AirSlash,     // 24 �������
	Peck,         // 25 �ɱ�
	FuryAttack,   // 26 �������
	Pursuit,      // 27 ���󰡶�����
	FastMove,     // 28 ����̵�
	Assurance,    // 29 �ºα�����
	DrillPeck,    // 30 ȸ���θ�
	DefenseCurl,  // 31 ��ũ����
	RockPolish,   // 32 ��ĿƮ
	RockThrow,    // 33 ��������
	Magnitude,    // 34 �ű״�Ʃ��
	Selfdestruct, // 35 ����
	Earthquake,   // 36 ����
	StoneEdge,    // 37 ���濡��
	Bind,         // 38 ���̱�
	RockTomb,     // 39 �ϼ�����
	DragonBreath, // 40 ���Ǽ���
	IronTail,     // 41 ���̾�����
	SandTomb,     // 42 ������
	Bite,         // 43 ����
	HyperFang,    // 44 �ʻ�մ�
	Crunch,       // 45 ������μ���
	SuperFang,    // 46 �г��Ǿմ�
	DoubleEdge,   // 47 ���ǻ�����Ŭ
	Unknown,      // 48 Max
};

enum class SkillType
{
	Normal,   // 0 �븻 (���)
	Fight,    // 1 ����
	Flying,   // 2 ���� (���)
	Poision,  // 3 ��
	Bug,      // 4 ����
	Ground,   // 5 ��   (���)
	Rock,     // 6 ����  (���)
	Ghost,    // 7 ��Ʈ
	Steel,    // 8 ��ö (���)
	Fire,     // 9 ��  (���)
	Water,    // 10 �� (���)
	Grass,    // 11 Ǯ (���)
	Electro,  // 12 ����
	Ice,      // 13 ����
	Psvchc,   // 14 ������ (���)
	Dragon,   // 15 �巡�� (���)
	Drak,     // 16 �� (���)
};

// ���� :
class PokeSkillBase
{
	friend class PokeDataBase;

public:
	// constrcuter destructer
	PokeSkillBase();
	~PokeSkillBase();

	// delete Function
	// PokeSkillBase(const PokeSkillBase& _Other) = delete;
	// PokeSkillBase(PokeSkillBase&& _Other) noexcept = delete;
	// PokeSkillBase& operator=(const PokeSkillBase& _Other) = delete;
	// PokeSkillBase& operator=(PokeSkillBase&& _Other) noexcept = delete;

	// ��ų�̸� ��������
	std::string ForUI_GetSkillName()
	{
		return Name;
	}

	// �̰��� ���ݽ�ų�Դϱ�?
	inline bool ItisAttackSkill()
	{
		return IsAttackSkill;
	}

	// �̰��� Ư�������Դϱ�?
	inline bool ItisSpecialSkill()
	{
		return IsSpecialSkill;
	}

	// ��ų ���ݷ� ��������
	inline int GetSkillDamage()
	{
		return SkillDamage;
	}

	// ��ų �ִ� PP ��������
	inline int GetMaxSkillPowerPoint()
	{
		return MaxSkillPowerPoint;
	}

	// UI�� �ִ� PP ��ȯ
	inline std::string ForUI_GetMaxSkillPowerPoint()
	{
		return std::to_string(MaxSkillPowerPoint);
	}

	// ��ų ���� PP ��������
	inline int GetCurrentSkillPowerPoint()
	{
		return CurrentSkillPowerPoint;
	}

	// UI�� ���� PP ��ȯ
	inline std::string ForUI_GetCurrentSkillPowerPoint()
	{
		return std::to_string(CurrentSkillPowerPoint);
	}

	// ��ų ���߷� ��������
	inline float GetSkillHitrate()
	{
		return SkillHitrate;
	}

	// ��ų Ÿ�� ��������
	SkillType GetSkillType()
	{
		return SkillType;
	}

	// ��ų ���� ��������
	PokeSkill GetSkill()
	{
		return Skills;
	}

	// pp 1 ����
	void MinusPowerPoint()
	{
		if (0 < CurrentSkillPowerPoint)
		{
			CurrentSkillPowerPoint -= 1;
		}
		else
		{
			CurrentSkillPowerPoint = -1;
		}
	}

	// pp�� 0�Դϱ�?
	bool IsPowerPointZero()
	{
		return 0 == CurrentSkillPowerPoint;
	}

protected:

private:
	PokeSkill Skills = PokeSkill::Tackle;          // ��ų ����
	SkillType SkillType = SkillType::Normal;       // ��ų Ÿ��
	std::string Name = "������";					   // ��ų �̸�

	bool IsAttackSkill = true;                     // ���ݽ�ų���� ������ų����
	bool IsSpecialSkill = false;				   // �������� ��������

	int SkillDamage = 0;                           // ��ų���ݷ�
	int MaxSkillPowerPoint = 0;                    // �ִ� ��ų �Ŀ�����Ʈ
	int CurrentSkillPowerPoint = 0;                // �ܿ� ��ų �Ŀ�����Ʈ
	float SkillHitrate = 0.f;                      // ��ų ���߷�

	void InitCreateSkill(PokeSkill _SkillName);    // ���� ���� ���� �� ȣ��Ǵ� ��ų Init �Լ�
	void ChangeSkill(PokeSkill _modifyskill);       // ��ų ���� �� Change �ϴ� �Լ�

	// ��ų ������ ���̽�
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