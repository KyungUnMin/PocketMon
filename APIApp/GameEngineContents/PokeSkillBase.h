#pragma once

#include <string>
#include <map>

enum class PokeSkill
{
	Scratch,      // ������
	Growl,        // �����Ҹ�
	Ember,        // �Ҳɼ���
	Leer,         // °������
	Slash,        // �������
	Flamethrower, // ȭ�����
	Tackle,       // �����ġ��
	TailWhip,     // ��������
	Bubble,       // ��ǰ
	WaterGun,     // ������
	Withdraw,     // ����������
	SkullBash,    // ����Ʈ��ġ��
	HydroPump,    // ���̵������
	LeechSeed,    // ���Ѹ���
	VineWhip,     // ����ä��
	RazorLeaf,    // �ٳ�������
	SleepPowder,  // ���鰡��
	SolarBeam,    // �ֶ��
	SandAttack,   // �𷡻Ѹ���
	Gust,         // �ٶ�����Ű��
	QuickAttack,  // ������ȭ
	Twister,      // ȸ����
	FeatherDance, // ���д�
	WingAttack,   // ����ġ��
	AirSlash,     // �������
	Peck,         // �ɱ�
	FuryAttack,   // �������
	Pursuit,      // ���󰡶�����
	FastMove,     // ����̵�
	Assurance,    // �ºα�����
	DrillPeck,    // ȸ���θ�
	DefenseCurl,  // ��ũ����
	RockPolish,   // ��ĿƮ
	RockThrow,    // ��������
	Magnitude,    // �ű״�Ʃ��
	Selfdestruct, // ����
	Earthquake,   // ����
	StoneEdge,    // ���濡��
	Bind,         // ���̱�
	RockTomb,     // �ϼ�����
	DragonBreath, // ���Ǽ���
	IronTail,     // ���̾�����
	SandTomb,     // ������
	Bite,         // ����
	HyperFang,    // �ʻ�մ�
	Crunch,       // ������μ���
	SuperFang,    // �г��Ǿմ�
	DoubleEdge,   // ���ǻ�����Ŭ
	Unknown,      // �����Ҵ��
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
	PokeSkillBase(const PokeSkillBase& _Other) = delete;
	PokeSkillBase(PokeSkillBase&& _Other) noexcept = delete;
	PokeSkillBase& operator=(const PokeSkillBase& _Other) = delete;
	PokeSkillBase& operator=(PokeSkillBase&& _Other) noexcept = delete;

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

	// ��ų�̸� ��������
	std::string_view ForUI_GetSkillName()
	{
		return Name;
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