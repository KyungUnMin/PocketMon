#pragma once

#include <string>
#include <vector>
#include <list>

#include <GameEngineBase/GameEngineDebug.h>
#include "PokeSkillBase.h"

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
	Max,        // max
};

// ���ϸ� Ÿ��
enum class PokeType
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

// ���ϸ� ����
enum class PokePersonality
{
	Lonely,   // �ܷο�
	Adamant,  // ����������
	Naughty,  // ����θ���
	Brave,    // �밨��
	Bold,     // ������
	Impish,   // �峭�� ����
	Lax,      // ������
	Relaxed,  // ������
	Modest,   // �ұ�����
	Mild,     // �����
	Rash,     // ������
	Quiet,    // ������
	Calm,     // ��ȭ��
	Gentle,   // ������
	Careful,  // ������
	Sassy,    // �ǹ���
	Timid,    // �̸���
	Hasty,    // ������
	Jolly,    // ��Ȱ��
	Naive,    // ������
	Bashful,  // ������
	Hardy,    // ����ϴ�
	Docile,   // ��а����
	Quirky,   // ����������
	Serious,  // ������
};

// ���ϸ� Ư��
enum class PokeCharacteristic
{
	�ɷ�,
	��ȭ,
	�޷�,
	��ī�ο,
	�ټ�,
	���Ӹ�,
};

class GameEngineRender;
// class PokeSkillBase;

// ���� :
class PokeDataBase
{
public:
	// constrcuter destructer
	PokeDataBase();
	~PokeDataBase();

	// delete Function
	PokeDataBase(const PokeDataBase& _Other) = delete;
	PokeDataBase(PokeDataBase&& _Other) noexcept = delete;
	PokeDataBase& operator=(const PokeDataBase& _Other) = delete;
	PokeDataBase& operator=(PokeDataBase&& _Other) noexcept = delete;

	static PokeDataBase* PokeCreate(int _PokeDexNumber, int _Level = 1);
	static void PokeExperienceGain(PokeDataBase* _Ownerpokemon, PokeDataBase* _knockeddownpokemon);

	//void PokeEvolution();
	//void PokeSkillAcquisition();

	// ü�±��
	void MinusMonsterCurrentHP(int _Value)
	{
		CurrentHealthPoint -= _Value;
	}

	// ���ϸ� �̸� ��������
	std::string_view ForUI_GetMonsterName()
	{
		return Name;
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

	inline void PlusMonsterExperience(int _EXP)
	{
		Experience += _EXP;
	}

	// UI�� ����ġ string ��ȯ
	inline std::string ForUI_GetMonsterExperience()
	{
		return std::to_string(Experience);
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
	PokeSkillBase* GetMonsterSkillList(int _SkillNumber)
	{
		if (_SkillNumber <= 0 || _SkillNumber >= 5)
		{
			MsgAssert("��ų����� 1, 2, 3, 4 �Դϴ�.");
			return nullptr; 
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

		SkillList[_SkillNumber - 1]->ChangeSkill(_modifyskill);;
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

	/// <summary>
	/// �޸� ������ ������ Get �Լ��Դϴ�. ȣ���ؼ� ������� ������. �����ϴ�.
	/// </summary>
	static PokeDataBase& GetPtr()
	{
		return Ptr;
	}
	static void Release();

protected:

private:
	// �޸� �Ҵ�, ������ ����Ʈ, ������ (������� ������...)
	static std::list<PokeDataBase*> AllPokemons;		          // ��� ���ϸ�
	static std::list<PokeSkillBase*> AllSkills;			          // ��� ��ų
	static PokeDataBase Ptr;                                      // ������� ������...

	// ���ϸ� ������
	GameEngineRender* MonsterImage = nullptr;					  // ���ϸ� �̹���
	std::string Name = "�ȳ�";							          // ���ϸ� �̸�

	std::vector<PokeSkillBase*> SkillList = std::vector<PokeSkillBase*>(4);			// ���ϸ� ��ų����Ʈ
								    
	bool IsMan = true;										      // ���ϸ� ����
	bool IsbeCaught = false;									  // �߻����ϸ����� ���� ���ϸ�����

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

	// ������ ���� ����
	static void PersonalityDecision(PokeDataBase* _PoKeCreatePtr);                                 // ����
	static void GenderDecision(PokeDataBase* _PoKeCreatePtr);                                      // ����
	static void PokeSkillInit(int _Index, PokeSkill _SkillName, PokeDataBase* _PoKeCreatePtr);     // ��ų �Ҵ�
	static void PokeStatusUp(PokeDataBase* _PoKeCreatePtr);                                        // 1 �̻� ���� �Ҵ� �� ȣ���

	// ����ġ�� 100�� �ѱ� �� ȣ��
	static void PokeLevelUp(PokeDataBase* _Ownerpokemon);

	// ���ϸ� ���̽� ������
	static void BulbasaurData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void IvysaurData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void VenusaurData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void CharmanderData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void CharmeleonData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void CharizardData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void SquirtleData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void WartortleData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void BlastoiseData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void PidgeyData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void RattataData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void SpearowData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void GeodudeData(int _Level, PokeDataBase* _PoKeCreatePtr);
	static void OnixData(int _Level, PokeDataBase* _PoKeCreatePtr);

};

