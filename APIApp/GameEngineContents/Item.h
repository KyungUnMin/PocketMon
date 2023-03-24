#pragma once
#include <string>

#include "ContentsEnum.h"
// 설명 :
class Item
{
public:
	// constrcuter destructer
	Item(ItemCode _Code)
		: Code(_Code)
	{
		// 임시용 코드
		IsBattleItem = true;
	}
	~Item() {}

	int Num = 0;// 개수
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
	bool IsBattleItem = false;		// 배틀때 사용가능여부
};

