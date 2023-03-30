#pragma once

#include <string>
#include <vector>
#include <list>

#include <GameEngineBase/GameEngineDebug.h>
#include "PokeSkillBase.h"
#include "ContentsEnum.h"

// ������ȣ�� +1�� ǥ��
enum class PokeNumber
{
	Bulbasaur,  // 0 �̻��ؾ�
	Ivysaur,    // 1 �̻���Ǯ
	Venusaur,   // 2 �̻��ز�
	Charmander, // 3 ���̸�
	Charmeleon, // 4 ���ڵ�
	Charizard,  // 5 ���ڸ�
	Squirtle,   // 6 ���α�
	Wartortle,  // 7 ��Ϻα�
	Blastoise,  // 8 �źϿ�
	Pidgey,     // 9 ����
	Rattata,    // 10 ����
	Spearow,    // 11 ������
	Geodude,    // 12 ������
	Onix,       // 13 �ս���
	Max,        // 14 max
};

// ���ϸ� Ÿ��
enum class PokeType
{
	Normal,   // 0 �븻
	Fight,    // 1 ����
	Flying,   // 2 ����
	Poision,  // 3 ��
	Bug,      // 4 ����
	Ground,   // 5 ��
	Rock,     // 6 ����
	Ghost,    // 7 ��Ʈ
	Steel,    // 8 ��ö
	Fire,     // 9 ��
	Water,    // 10 ��
	Grass,    // 11 Ǯ
	Electro,  // 12 ����
	Ice,      // 13 ����
	Psvchc,   // 14 ������
	Dragon,   // 15 �巡��
	Drak,     // 16 ��
};

// ���ϸ� ����
enum class PokePersonality
{
	Lonely,   // 0 �ܷο�
	Adamant,  // 1 ����������
	Naughty,  // 2 ����θ���
	Brave,    // 3 �밨��
	Bold,     // 4 ������
	Impish,   // 5 �峭�� ����
	Lax,      // 6 ������
	Relaxed,  // 7 ������
	Modest,   // 8 �ұ�����
	Mild,     // 9 �����
	Rash,     // 10 ������
	Quiet,    // 11 ������
	Calm,     // 12 ��ȭ��
	Gentle,   // 13 ������
	Careful,  // 14 ������
	Sassy,    // 15 �ǹ���
	Timid,    // 16 �̸���
	Hasty,    // 17 ������
	Jolly,    // 18 ��Ȱ��
	Naive,    // 19 ������
	Bashful,  // 20 ������
	Hardy,    // 21 ����ϴ�
	Docile,   // 22 ��а����
	Quirky,   // 23 ����������
	Serious,  // 24 ������
};

// ���ϸ� Ư��
enum class PokeCharacteristic
{
	�ɷ�,        // 0
	��ȭ,        // 1
	�޷�,        // 2
	��ī�ο,   // 3
	�ټ�,        // 4
	���Ӹ�,      // 5
};

class GameEngineRender;

// ���� :
class PokeDataBase
{
public:
	// constrcuter destructer
	PokeDataBase();
	~PokeDataBase();

	// delete Function
	//PokeDataBase(const PokeDataBase& _Other) = delete;
	//PokeDataBase(PokeDataBase&& _Other) noexcept = delete;
	//PokeDataBase& operator=(const PokeDataBase& _Other) = delete;
	//PokeDataBase& operator=(PokeDataBase&& _Other) noexcept = delete;

	static PokeDataBase PokeCreate(int _PokeDexNumber, int _Level = 1);
	static int PokeExperienceGain(PokeDataBase& _Ownerpokemon, PokeDataBase& _knockeddownpokemon);

	// ������ ������?
	bool IsPokemonItemPossession()
	{
		return IshaveItem;
	}

	// ��ó�� ���
	void ForInven_UsePotion()
	{
		int Itemeffect = 20;
		int ToapplyHP = CurrentHealthPoint;
		
		int AddHP = ToapplyHP + Itemeffect;

		if (AddHP >= MaxHealthPoint)
		{
			CurrentHealthPoint = MaxHealthPoint;
		}
		else
		{
			CurrentHealthPoint += Itemeffect;
		}
	}

	// ��� ��ų max ȸ��
	void ForInven_AllPowerPointRecovery()
	{
		SkillList[1].SkillPP_MAXRecovery();
		SkillList[2].SkillPP_MAXRecovery();
		SkillList[3].SkillPP_MAXRecovery();
		SkillList[4].SkillPP_MAXRecovery();
	}

	// ���Ͱ� ���������Դϱ�?
	bool IsMonsterStern()
	{
		return IsMonsterDeath;
	}

	// ���͸� �������·� ����� (����)
	void Stern()
	{
		IsMonsterDeath = true;
	}

	// ������ ������ �ڵ�
	ItemCode GetPossession()
	{
		return Possession;
	}

	// ������ �ڵ� ����
	void SetPossession(ItemCode _enumnumber)
	{
		Possession = _enumnumber;
	}

	// ü�±��
	void MinusMonsterCurrentHP(int _Value)
	{
		CurrentHealthPoint -= _Value;
	}

	// ���ϸ� �̸� ��������
	std::string ForUI_GetMonsterName()
	{
		return Name;
	}

	// ���ϸ� �ѹ� �̸� ��������
	std::string ForUI_GetMonsterNumberName()
	{
		return NumberName;
	}

	// ���ϸ� Ÿ�� �̸� ��������
	std::string ForUI_GetMonsterTypeName()
	{
		return TypeName;
	}

	// ���ϸ� �ѹ� �������� (int)
	int GetPokeNumber_int()
	{
		return (static_cast<int>(PokeDexNumber) + 1);
	}

	// ���ϸ� �ѹ� �������� (�̳�)
	PokeNumber GetPokeNumber_enum()
	{
		return PokeDexNumber;
	}

	// ���ϸ� ���� ���� ��������
	std::string ForUI_GetPokeDexText()
	{
		return PokeDexText;
	}

	// ���ϸ� �̸� ����
	void PokeNameEdit(std::string _EditName)
	{
		Name = _EditName;
	}

	// ���ϸ� ���� ��������
	inline int GetMonsterLevel_int()
	{
		return MonsterLevel;
	}

	// ���ϸ� ���� ��������(����)
	inline float GetMonsterLevel_float()
	{
		return static_cast<float>(MonsterLevel);
	}

	// UI�� ���� string ��ȯ
	inline std::string ForUI_GetMonsterLevel()
	{
		return std::to_string(MonsterLevel);
	}

	// ���ϸ� ����ġ ��������
	inline int GetMonsterExperience()
	{
		return Experience;
	}

	// ���ϸ� ����ġ ȹ��
	inline void PlusMonsterExperience(int _EXP)
	{
		Experience += _EXP;
	}

	// UI�� ����ġ string ��ȯ
	inline std::string ForUI_GetMonsterExperience()
	{
		return std::to_string(Experience);
	}

	// UI�� ���ݷ� string ��ȯ
	inline std::string ForUI_GetMonsterAttackPower()
	{
		return std::to_string(AttackPower);
	}

	// UI�� ���� string ��ȯ
	inline std::string ForUI_GetMonsterDefense()
	{
		return std::to_string(Defense);
	}

	// UI�� Ư�����ݷ� string ��ȯ
	inline std::string ForUI_GetMonsterSpecialAttackPower()
	{
		return std::to_string(SpecialAttackPower);
	}

	// UI�� Ư������ string ��ȯ
	inline std::string ForUI_GetMonsterSpecialDefense()
	{
		return std::to_string(SpecialDefense);
	}

	// UI�� ���ǵ� string ��ȯ
	inline std::string ForUI_GetMonsterAgility()
	{
		return std::to_string(Agility);
	}

	// ���ϸ� ���� ��������
	inline int GetMonsterGender()
	{
		return IsMan;
	}

	// ���ϸ� �ִ� ü�� ��������
	inline int GetMonsterMaxHP_int()
	{
		return MaxHealthPoint;
	}

	// ���ϸ� �ִ� ü�� �������� (����)
	inline float GetMonsterMaxHP_float()
	{
		return static_cast<float>(MaxHealthPoint);
	}

	// UI�� �ִ� ü�� string ��ȯ
	inline std::string ForUI_GetMonsterMaxHP()
	{
		return std::to_string(MaxHealthPoint);
	}

	// ���ϸ� ���� ü�� ��������
	inline int GetMonsterCurrentHP()
	{
		return CurrentHealthPoint;
	}

	// ���ϸ� ������ �� ����ü���� �ƽ�ü������ ����
	inline void SetMonsterCurrentHP(int _MaxHP)
	{
		CurrentHealthPoint = _MaxHP;
	}

	// UI�� ���� ü�� string ��ȯ
	inline std::string ForUI_GetMonsterCurrentHP()
	{
		return std::to_string(CurrentHealthPoint);
	}

	// ���ݷ� ��������
	inline int GetMonsterAttackPower_int()
	{
		return AttackPower;
	}

	// ���ݷ� �������� (����)
	inline float GetMonsterAttackPower_float()
	{
		return static_cast<float>(AttackPower);
	}

	// ���� ��������
	inline int GetMonsterDefense_int()
	{
		return Defense;
	}

	// ���� �������� (����)
	inline float GetMonsterDefense_float()
	{
		return static_cast<float>(Defense);
	}

	// Ư�����ݷ� ��������
	inline int GetMonsterSpecialAttackPower_int()
	{
		return SpecialAttackPower;
	}

	// Ư�����ݷ� �������� (����)
	inline float GetMonsterSpecialAttackPower_float()
	{
		return static_cast<float>(SpecialAttackPower);
	}

	// Ư������ ��������
	inline int GetMonsterSpecialDefense_int()
	{
		return SpecialDefense;
	}

	// Ư������ �������� (����)
	inline float GetMonsterSpecialDefense_float()
	{
		return static_cast<float>(SpecialDefense);
	}

	// ���ǵ� ��������
	inline int GetMonsterAgility()
	{
		return Agility;
	}

	// ���ϸ� ��ų����Ʈ ��������
	PokeSkillBase& GetMonsterSkillList(int _SkillNumber)
	{
		if (_SkillNumber <= 0 || _SkillNumber >= 5)
		{
			MsgAssert("��ų����� 1, 2, 3, 4 �Դϴ�.");
		}

		return SkillList[_SkillNumber - 1];
	}

	// ���ϸ� ��ų ����
	void ChangeMonsterSkill(int _SkillNumber, PokeSkill _modifyskill)
	{
		if (_SkillNumber <= 0 || _SkillNumber >= 5)
		{
			MsgAssert("��ų����� 1, 2, 3, 4 �Դϴ�.");
			return;
		}

		SkillList[_SkillNumber - 1].ChangeSkill(_modifyskill);;
	}

	// ���ϸ� Ÿ�� ��������
	PokeType GetMonsterType()
	{
		return Type;
	}

	// ���ϸ� Ư�� ��������
	PokePersonality GetMonsterPersonality()
	{
		return Personality;
	}

	// ���ϸ� ���� ��������
	PokeCharacteristic GetMonsterCharacteristic()
	{
		return Characteristic;
	}

	// ��������
	int GetAttackbuffstack()
	{
		return AttackStack;
	}
	void PlusAttackbuffstack()
	{
		AttackStack += 1;
	}
	void MinusAttackbuffstack()
	{
		AttackStack -= 1;
	}

	int GetDefensebuffstack()
	{
		return DefenseStack;
	}
	void PlusDefensebuffstack()
	{
		DefenseStack += 1;
	}
	void MinusDefensebuffstack()
	{
		DefenseStack -= 1;
	}

	int GetSpcialAttackbuffstack()
	{
		return SpecialAttackStack;
	}
	void PlusSpcialAttackbuffstack()
	{
		SpecialAttackStack += 1;
	}
	void MinusSpcialAttackbuffstack()
	{
		SpecialAttackStack -= 1;
	}

	int GetSpcialDefensekbuffstack()
	{
		return SpecialDefenseStack;
	}
	void PlusSpcialDefensebuffstack()
	{
		SpecialDefenseStack += 1;
	}
	void MinusSpcialDefensebuffstack()
	{
		SpecialDefenseStack -= 1;
	}

	// ��Ʋ ���� or ���ϸ� ü������ �ش� �Լ� ȣ��
	void Resetbuffstack()
	{
		AttackStack = 0;
		DefenseStack = 0;
		SpecialAttackStack = 0;
		SpecialDefenseStack = 0;
	}

	/// <summary>
	/// �޸� ������ ������ Get �Լ��Դϴ�. ȣ���ؼ� ������� ������. �����ϴ�.
	/// </summary>
	//static PokeDataBase& GetPtr()
	//{
	//	return Ptr;
	//}
	//
	//void Release();

protected:

private:
	// �޸� �Ҵ�, ������ ����Ʈ, ������ (������� ������...)
	// static std::list<PokeDataBase*> AllPokemons;		          // ��� ���ϸ�
	// static std::list<PokeSkillBase*> AllSkills;			          // ��� ��ų
	// static PokeDataBase Ptr;                                      // ������� ������...

	// ���ϸ� ������
	GameEngineRender* MonsterImage = nullptr;					  // ���ϸ� �̹���
	std::string Name = "�ȳ�";							          // ���ϸ� �̸�
	std::string TypeName = "Grass";							      // ���ϸ� Ÿ�� �̸�
	std::string NumberName = "000";							      // ���ϸ� ��ȣ �̸�
	std::string PokeDexText = "�� ���ϸ��� ~";				      // ���ϸ� �̸�

	std::vector<PokeSkillBase> SkillList = std::vector<PokeSkillBase>(4);			// ���ϸ� ��ų����Ʈ
								    
	bool IsMan = true;										      // ���ϸ� ����
	bool IsbeCaught = false;									  // �߻����ϸ����� ���� ���ϸ�����
	bool IsMonsterDeath = false;                                  // ��Ʋ�� ���� ü���� 0�̵Ǹ� true�� �ȴ�.

	// ����ǰ
	ItemCode Possession = ItemCode::Cancel;

	bool IshaveItem = false;                                      // �������� ��������
	bool AttackPowerItem = false;                                 // ���ݷ� �� ������
	bool DefenseItem = false;                                     // ���� �� ������
	bool SpecialAttackPowerItem = false;                          // ����Ȱ��ݷ� �� ������
	bool SpecialDefenseItem = false;                              // ����ȹ��� �� ������

	PokeNumber PokeDexNumber = PokeNumber::Blastoise;			  // ���ϸ� ���� ��ȣ
	int MaxHealthPoint = 0;								          // ���� �ִ� ü��
	int CurrentHealthPoint = 0;						              // ���� �ܿ� ü��
	int AttackPower = 0;								     	  // ���� ���ݷ�
	int Defense = 0;										      // ���� ����
	int SpecialAttackPower = 0;							          // ���� Ư�����ݷ�
	int SpecialDefense = 0;								          // ���� Ư������
	int Agility = 0;									          // ���� ��ø��
	int MonsterLevel = 0;								          // ���� ����
	int Experience = 0;									          // ���� ����ġ
	int RemainingExperience = 0;						          // ���� ���� �������� ���� ����ġ
									    
	int PokeBall = 0;									          // ���ϸ��� ����ִ� ���Ϻ� ����
	PokeType Type = PokeType::Bug;								  // ���ϸ� �Ӽ� Ÿ��
	PokePersonality Personality = PokePersonality::Adamant;		  // ���ϸ� ����
	PokeCharacteristic Characteristic = PokeCharacteristic::�ټ�; // ���ϸ� Ư��

	// ���� ����
	int AttackStack = 0;
	int DefenseStack = 0;
	int SpecialAttackStack = 0;
	int SpecialDefenseStack = 0;

	// ������ ���� ����
	static void PersonalityDecision(PokeDataBase& _PoKeCreatePtr);                                 // ����
	static void GenderDecision(PokeDataBase& _PoKeCreatePtr);                                      // ����
	static void PokeSkillInit(int _Index, PokeSkill _SkillName, PokeDataBase& _PoKeCreatePtr);     // ��ų �Ҵ�
	static void PokeStatusUp(PokeDataBase& _PoKeCreatePtr);                                        // 1 �̻� ���� �Ҵ� �� ȣ���

	// ����ġ�� 100�� �ѱ� �� ȣ��
	static void PokeLevelUp(PokeDataBase& _Ownerpokemon);

	// ���ϸ� ���̽� ������
	static void BulbasaurData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void IvysaurData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void VenusaurData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void CharmanderData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void CharmeleonData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void CharizardData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void SquirtleData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void WartortleData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void BlastoiseData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void PidgeyData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void RattataData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void SpearowData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void GeodudeData(int _Level, PokeDataBase& _PoKeCreatePtr);
	static void OnixData(int _Level, PokeDataBase& _PoKeCreatePtr);

};

