#pragma once

#include <string>
#include <vector>

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
};

class GameEngineRender;
class PokeSkillBase;

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

	void PokeCreate(int _PokeDexNumber, int _Level);
	void PokeExperienceAcquisition(int _EXP);
	void PokeLevelUp(int _EXP);
	void PokeStatusUp(int _Status);
	void PokeEvolution();
	void PokeSkillAcquisition();
	void PokeNameEdit(std::string _EditName);

protected:

private:
	// ���ϸ� ������
	GameEngineRender* MonsterImage = nullptr;						 // ���ϸ� �̹���
	// ��� 4�� ����

	std::string Name = "�ȳ�";									     // ���ϸ� �̸�
											    
	bool IsMan = true;											     // ���ϸ� ����
	bool IsbeCaught = false;									     // �߻����ϸ����� ���� ���ϸ�����

	PokeNumber PokeDexNumber = PokeNumber::Max;					     // ���ϸ� ���� ��ȣ
	int HealthPoint = 0;										     // ���� ü��
	int AttackPower = 0;											 // ���� ���ݷ�
	int Defense = 0;												 // ���� ����
	int SpecialAttackPower = 0;										 // ���� Ư�����ݷ�
	int SpecialDefense = 0;											 // ���� Ư������
	int Agility = 0;											     // ���� ��ø��
	int MonsterLevel = 0;										     // ���� ����
	int Experience = 0;												 // ���� ����ġ
	int RemainingExperience = 0;								     // ���� ���� �������� ���� ����ġ
											    
	int PokeBall = 0;												 // ���ϸ��� ����ִ� ���Ϻ� ����
	PokeType Type = PokeType::Normal;								 // ���ϸ� �Ӽ� Ÿ��
	PokePersonality Personality = PokePersonality::Serious;			 // ���ϸ� ����
	PokeCharacteristic Characteristic = PokeCharacteristic::�ɷ�;	 // ���ϸ� Ư��

	// ����, ���� ����
	void PersonalityDecision();
	void GenderDecision();


	// ���ϸ� ���̽� ������
	void BulbasaurData(int _Level);
	void CharmanderData(int _Level);
	void SquirtleData(int _Level);

	// ��ų
	std::vector<PokeSkillBase*> SkillList = std::vector<PokeSkillBase*>(4);
};

