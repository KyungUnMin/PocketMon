#pragma once

#include <list>
#include <string>

#include "ContentsEnum.h"

// ���� :
class ItemDataBase
{
public:
	// constrcuter destructer
	ItemDataBase();
	~ItemDataBase();

	// delete Function
	ItemDataBase(const ItemDataBase& _Other) = delete;
	ItemDataBase(ItemDataBase&& _Other) noexcept = delete;
	ItemDataBase& operator=(const ItemDataBase& _Other) = delete;
	ItemDataBase& operator=(ItemDataBase&& _Other) noexcept = delete;

	static ItemDataBase* ItemCreate(ItemCode _ItemNumber);

	// ������ �̸� ��������
	std::string ForUI_GetItemName()
	{
		return Name;
	}

	// ������ ���� ��������
	std::string ForUI_GetItemExplanation()
	{
		return ItemExplanation;
	}

	/// <summary>
	/// �޸� ������ ������ Get �Լ��Դϴ�. ȣ���ؼ� ������� ������. �����ϴ�.
	/// </summary>
	static ItemDataBase& GetPtr()
	{
		return Ptr;
	}

	void Release();

protected:

private:
	static std::list<ItemDataBase*> AllItem;     // ��� ������
	static ItemDataBase Ptr;                     // ������� ������...

	bool IsActiveitem = false;                   // ��Ƽ�� ���������� �ƴ���
	
	std::string Name = "error";                  // ������ �̸�
	std::string ItemExplanation = "this is";     // ������ ����

	ItemCode CodeNumber = ItemCode::Bike;        // ������ �̳� �ѹ�

	int Price = 0;
	
	static void PotionData(ItemDataBase* _ItemPtr);
	static void RepelData(ItemDataBase* _ItemPtr);
	static void ReviveData(ItemDataBase* _ItemPtr);
	static void RareCandyData(ItemDataBase* _ItemPtr);
	static void EtherData(ItemDataBase* _ItemPtr);
	static void WiseGlassesData(ItemDataBase* _ItemPtr);
	static void MuscleBandData(ItemDataBase* _ItemPtr);
	static void ChoiceBandData(ItemDataBase* _ItemPtr);
	static void ChoiceScarfData(ItemDataBase* _ItemPtr);
	static void BikeData(ItemDataBase* _ItemPtr);
	static void MonsterBallData(ItemDataBase* _ItemPtr);
	static void MasterBallData(ItemDataBase* _ItemPtr);
	static void CancelData(ItemDataBase* _ItemPtr);
};

