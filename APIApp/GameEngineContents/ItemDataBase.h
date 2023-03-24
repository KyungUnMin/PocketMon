#pragma once

#include <list>
#include <string>

#include "ContentsEnum.h"

// 설명 : 처음 게임을 시작할 때 모든 아이템을 싹 만들어서 리스트에 넣어둠
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

	// 아이템 이름 가져오기
	std::string ForUI_GetItemName()
	{
		return Name;
	}

	// 아이템 설명 가져오기
	std::string ForUI_GetItemExplanation()
	{
		return ItemExplanation;
	}

	// 배틀중에 사용가능?
	bool IsBattleuse()
	{
		return IsBattle;
	}

	/// <summary>
	/// 메모리 해제용 포인터 Get 함수입니다. 호출해서 사용하지 마세요. 터집니다.
	/// </summary>
	static ItemDataBase& GetPtr()
	{
		return Ptr;
	}

	void Release();

protected:

private:
	static std::list<ItemDataBase*> AllItem;       // 모든 아이템
	static ItemDataBase Ptr;                       // 사용하지 마세요...

	bool IsBattle = false;                         // 액티브 아이템인지 아닌지
	
	std::string Name = "error";                    // 아이템 이름
	std::string ItemExplanation = "this is";       // 아이템 설명

	ItemCode CodeNumber = ItemCode::Bike;          // 아이템 이넘 넘버

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

