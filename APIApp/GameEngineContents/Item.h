#pragma once
#include <string>

#include "ContentsEnum.h"
// ���� :
class Item
{
public:
	// constrcuter destructer
	Item(ItemCode _Code)
		: Code(_Code)
	{
		// �ӽÿ� �ڵ�
		IsBattleItem = true;
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

