#pragma once
#include <string>

enum class ItemCode
{
	Potion,			// 0. 상처약
	Repel,			// 1. 벌레퇴치스프레이
	Revive,			// 2. 기력의 조각
	RareCandy,		// 3. 이상한사탕
	Ether,			// 4. PP에이드
	WiseGlasses,	// 5. 박식안경	(특공 상승)
	MuscleBand,		// 6. 힘의 띠 (물공 상승)
	ChoiceBand,		// 7. 머리띠 (방어 상승)
	ChoiceScarf,	// 8. 스카프 (특방 상승)
	Bike,			// 9. 자전거
	MonsterBall,	// 10. 몬스터볼 
	MasterBall,		// 11. 마스터볼 
	Cancel			// 12. 취소
};

// 설명 :
class Item
{
public:
	// constrcuter destructer
	Item(ItemCode _Code)
		: Code(_Code)
	{

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

