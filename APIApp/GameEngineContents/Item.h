#pragma once
#include <string>
#include "ContentsEnum.h"
// 설명 :
class Item
{
public:
	// constrcuter destructer
	Item();
	~Item();

	static Item GetItem(ItemCode _ItemCode);
	// 아이템 이름 가져오기
	std::string_view GetItemName()
	{
		return Name;
	}
	// 아이템 설명 가져오기
	std::string_view GetItemExplanation()
	{
		return ItemExplanation;
	}
	ItemCode GetItemCode()
	{
		return CodeNumber;
	}
	int GetItemCodeInt()
	{
		return static_cast<int>(CodeNumber);
	}
	int GetPrice()
	{
		return Price;
	}
	// 배틀중에 사용가능?
	bool IsBattleuse()
	{
		return IsBattle;
	}
	int GetNum()
	{
		return Num;
	}
	void AddNum(int _Num)
	{
		Num += _Num;
	}

protected:

private:
	ItemCode CodeNumber = ItemCode::Bike;          // 아이템 이넘 넘버
	std::string_view Name = "error";                    // 아이템 이름
	std::string_view ItemExplanation = "this is";       // 아이템 설명
	int Price = 0;
	bool IsBattle = false;                         // 액티브 아이템인지 아닌지

	int Num = 1;


	static Item PotionData();
	static Item RepelData();
	static Item ReviveData();
	static Item RareCandyData();
	static Item EtherData();
	static Item WiseGlassesData();
	static Item MuscleBandData();
	static Item ChoiceBandData();
	static Item ChoiceScarfData();
	static Item BikeData();
	static Item MonsterBallData();
	static Item MasterBallData();
	static Item CancelData();

};

