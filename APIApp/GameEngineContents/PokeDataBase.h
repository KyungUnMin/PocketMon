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
	static void PokeStatusUp(PokeDataBase* _PoKeCreatePtr);
	void PokeExperienceAcquisition(int _EXP);
	void PokeLevelUp(int _EXP);
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
	inline int GetMonsterLevel()
	{
		return MonsterLevel;
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
	inline int GetMonsterMaxHP()
	{
		return MaxHealthPoint;
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
	inline int GetMonsterAttackPower()
	{
		return AttackPower;
	}

	// ���� ��������
	inline int GetMonsterDefense()
	{
		return Defense;
	}

	// Ư�����ݷ� ��������
	inline int GetMonsterSpecialAttackPower()
	{
		return SpecialAttackPower;
	}

	// Ư������ ��������
	inline int GetMonsterSpecialDefense()
	{
		return SpecialDefense;
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
	static std::list<PokeDataBase*> AllPokemons;		    // ��� ���ϸ�
	static std::list<PokeSkillBase*> AllSkills;			    // ��� ��ų
	static PokeDataBase Ptr;                                // ������� ������...

	// ���ϸ� ������
	GameEngineRender* MonsterImage;					// ���ϸ� �̹���
	std::string Name;							    // ���ϸ� �̸�

	std::vector<PokeSkillBase*> SkillList = std::vector<PokeSkillBase*>(4);			// ���ϸ� ��ų����Ʈ
								    
	bool IsMan;										// ���ϸ� ����
	bool IsbeCaught;									// �߻����ϸ����� ���� ���ϸ�����

	PokeNumber PokeDexNumber;					    // ���ϸ� ���� ��ȣ
	int MaxHealthPoint;								// ���� �ִ� ü��
	int CurrentHealthPoint;						    // ���� �ܿ� ü��
	int AttackPower;									// ���� ���ݷ�
	int Defense;										// ���� ����
	int SpecialAttackPower;							// ���� Ư�����ݷ�
	int SpecialDefense;								// ���� Ư������
	int Agility;									    // ���� ��ø��
	int MonsterLevel;								// ���� ����
	int Experience;									// ���� ����ġ
	int RemainingExperience;						    // ���� ���� �������� ���� ����ġ
									    
	int PokeBall;									// ���ϸ��� ����ִ� ���Ϻ� ����
	PokeType Type;								    // ���ϸ� �Ӽ� Ÿ��
	PokePersonality Personality;			            // ���ϸ� ����
	PokeCharacteristic Characteristic;	            // ���ϸ� Ư��

	// ������ ���� ����
	static void PersonalityDecision(PokeDataBase* _PoKeCreatePtr);                                 // ����
	static void GenderDecision(PokeDataBase* _PoKeCreatePtr);                                      // ����
	static void PokeSkillInit(int _Index, PokeSkill _SkillName, PokeDataBase* _PoKeCreatePtr);     // ��ų �Ҵ�

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

	// ����
	void Attack();
};

