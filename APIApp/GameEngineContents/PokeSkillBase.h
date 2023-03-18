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
};

enum class SkillType
{
	Normal,   // �븻
	Fight,    // ����
	Flying,   // ����
	Poision,  // ��
	Bug,      // ����
	Ground,   // ��
	Rock,     // ����
	Ghost,    // ��Ʈ
	Steel,    // ��ö
	Fire,     // ��
	Water,    // ��
	Grass,    // Ǯ
	Electro,  // ����
	Ice,      // ����
	Psvchc,   // ������
	Dragon,   // �巡��
	Drak,     // ��
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

protected:

private:
	PokeSkill Skills = PokeSkill::Tackle;         // ��ų �̸�
	SkillType SkillType = SkillType::Normal;      // ��ų Ÿ��

	bool IsAttackSkill = true;                    // ���ݽ�ų���� ������ų����

	int SkillDamage = 0;                          // ��ų���ݷ�
	int MaxSkillPowerPoint = 0;                   // �ִ� ��ų �Ŀ�����Ʈ
	int CurrentSkillPowerPoint = 0;               // �ܿ� ��ų �Ŀ�����Ʈ
	float SkillHitrate = 0.f;                     // ��ų ���߷�

	void CreateSkill(PokeSkill _SkillName);
	void InitCreateSkill(PokeSkill _SkillName);

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
};