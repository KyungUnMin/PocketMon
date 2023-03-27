#pragma once
#include <string>
#include "ContentsEnum.h"
// ���� :
class Item
{
public:
	// constrcuter destructer
	Item();
	~Item();

	static Item GetItem(ItemCode _ItemCode);
	// ������ �̸� ��������
	std::string_view GetItemName()
	{
		return Name;
	}
	// ������ ���� ��������
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
	// ��Ʋ�߿� ��밡��?
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
	ItemCode CodeNumber = ItemCode::Bike;          // ������ �̳� �ѹ�
	std::string_view Name = "error";                    // ������ �̸�
	std::string_view ItemExplanation = "this is";       // ������ ����
	int Price = 0;
	bool IsBattle = false;                         // ��Ƽ�� ���������� �ƴ���

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

