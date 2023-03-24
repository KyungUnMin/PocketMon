#pragma once
#include <string>

enum class ItemCode
{
	Potion,			// 0. ��ó��
	Repel,			// 1. ������ġ��������
	Revive,			// 2. ����� ����
	RareCandy,		// 3. �̻��ѻ���
	Ether,			// 4. PP���̵�
	WiseGlasses,	// 5. �ڽľȰ�	(Ư�� ���)
	MuscleBand,		// 6. ���� �� (���� ���)
	ChoiceBand,		// 7. �Ӹ��� (��� ���)
	ChoiceScarf,	// 8. ��ī�� (Ư�� ���)
	Bike,			// 9. ������
	MonsterBall,	// 10. ���ͺ� 
	MasterBall,		// 11. �����ͺ� 
	Cancel			// 12. ���
};

// ���� :
class Item
{
public:
	// constrcuter destructer
	Item(ItemCode _Code)
		: Code(_Code)
	{

	}
	~Item() {}

	int Num = 0;// ����
	ItemCode GetItemCode()
	{
		return Code;
	}
	int GetItemCodeInt()
	{
		return static_cast<int>(Code);
	}
	const char* GetName()
	{
		return Name.data();
	}
	const char* GetInfo()
	{
		return Information.data();
	}
	bool GetIsBattleItem()
	{
		return IsBattleItem;
	}
	// delete Function
	//Item(const Item& _Other) = delete;
	//Item(Item&& _Other) noexcept = delete;
	//Item& operator=(const Item& _Other) = delete;
	//Item& operator=(Item&& _Other) noexcept = delete;

protected:

private:
	ItemCode Code = ItemCode::Cancel;
	std::string_view Name = "a";
	std::string_view Information = "a";
	bool IsBattleItem = false;		// ��Ʋ�� ��밡�ɿ���
};

