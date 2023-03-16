#pragma once

#include <string>

class GameEngineRender;

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

protected:

private:
	// ���ϸ� ������

	GameEngineRender* MonsterImage = nullptr;  // ���ϸ� �̹���

	std::string Name = "�ȳ�";                 // ���ϸ� �̸�

	bool IsMan = true;                         // ���ϸ� ����
	bool IsbeCaught = false;                   // �߻����ϸ����� ���� ���ϸ�����

	int PokeDexNumber = 0;                    // ���ϸ� ���� ��ȣ
	int HealthPoint = 0;                       // ���� ü��
	int AttackPower = 0;                       // ���� ���ݷ�
	int Defense = 0;                           // ���� ����
	int SpecialAttackPower = 0;                // ���� Ư�����ݷ�
	int SpecialDefense = 0;                    // ���� Ư������
	int Agility = 0;                           // ���� ��ø��
	int MonsterLevel = 0;                      // ���� ����
	int Experience = 0;						   // ���� ����ġ
	int RemainingExperience = 0;               // ���� ���� �������� ���� ����ġ

	int PoketBall = 0;                        // ���ϸ��� ����ִ� ���Ϻ� ����
	int PokeType = 0;
	// Ÿ�� (��, ��, ��, ���� ��)
	// Ư�� (
	// ����
	// 


};

