#include "ItemDataBase.h"

#include <GameEngineBase/GameEngineDebug.h>

#include "ContentsEnum.h"

ItemDataBase ItemDataBase::Ptr;
std::list<ItemDataBase*> ItemDataBase::AllItem = std::list<ItemDataBase*>();

ItemDataBase::ItemDataBase() 
{
}

ItemDataBase::~ItemDataBase() 
{
}

//////////////////////////////////////////////////////////////// 아이템 데이터 릴리즈 구조 (수정은 엄태건에게 요청)

void ItemDataBase::Release()
{
	for (ItemDataBase* tems : AllItem)
	{
		if (nullptr == tems)
		{
			continue;
		}

		delete tems;
		tems = nullptr;
	}
}

ItemDataBase* ItemDataBase::ItemCreate(ItemCode _ItemNumber)
{
	ItemDataBase* ItemCreatePtr = nullptr;

	int debugvalue = static_cast<int>(_ItemNumber);

	if (debugvalue >= 13)
	{
		MsgAssert("아이템 넘버는 12(Cancle)까지 존재합니다.");
		return nullptr;
	}
	else if (debugvalue < 0)
	{
		MsgAssert("아이템 넘버는 0(상처약)미만일 수 없습니다.");
		return nullptr;
	}

	ItemCreatePtr = new ItemDataBase();

	switch (_ItemNumber)
	{
	case ItemCode::Potion:
		PotionData(ItemCreatePtr);
		break;
	case ItemCode::Repel:
		RepelData(ItemCreatePtr);
		break;
	case ItemCode::Revive:
		ReviveData(ItemCreatePtr);
		break;
	case ItemCode::RareCandy:
		RareCandyData(ItemCreatePtr);
		break;
	case ItemCode::Ether:
		EtherData(ItemCreatePtr);
		break;
	case ItemCode::WiseGlasses:
		WiseGlassesData(ItemCreatePtr);
		break;
	case ItemCode::MuscleBand:
		MuscleBandData(ItemCreatePtr);
		break;
	case ItemCode::ChoiceBand:
		ChoiceBandData(ItemCreatePtr);
		break;
	case ItemCode::ChoiceScarf:
		ChoiceScarfData(ItemCreatePtr);
		break;
	case ItemCode::Bike:
		BikeData(ItemCreatePtr);
		break;
	case ItemCode::MonsterBall:
		MonsterBallData(ItemCreatePtr);
		break;
	case ItemCode::MasterBall:
		MasterBallData(ItemCreatePtr);
		break;
	case ItemCode::Cancel:
		CancelData(ItemCreatePtr);
		break;
	default:
		break;
	}

	AllItem.push_back(ItemCreatePtr);

	return ItemCreatePtr;
}


// 0. 상처약
void ItemDataBase::PotionData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = true;              // 사용 가능 아이템?

	_ItemPtr->Name = "POTION";                  // 아이템 이름
	_ItemPtr->ItemExplanation = "A spray-type sound medicine. It restores the HP of one POK@MON ny 20 points."; // 아이템 설명

	_ItemPtr->CodeNumber = ItemCode::Potion;    // 이넘 넘버
	_ItemPtr->Price = 300;                      // 가격
}

// 1. 벌레퇴치 스프레이
void ItemDataBase::RepelData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = true;

	_ItemPtr->Name = "REPEL";
	_ItemPtr->ItemExplanation = "Prevents weak wild POK@MON from appearing for 100 steps.";

	_ItemPtr->CodeNumber = ItemCode::Repel;
	_ItemPtr->Price = 200;
}

// 2. 기력의 조각
void ItemDataBase::ReviveData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = false;

	_ItemPtr->Name = "REVIVE";
	_ItemPtr->ItemExplanation = "Recovers a fainted POK@MON's HP by half.";

	_ItemPtr->CodeNumber = ItemCode::Revive;
	_ItemPtr->Price = 1000;
}

// 3. 이상한 사탕
void ItemDataBase::RareCandyData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = true;

	_ItemPtr->Name = "RARECANDY";
	_ItemPtr->ItemExplanation = "A candy that is packed with energy, It raises the level of a POK@MON by one.";

	_ItemPtr->CodeNumber = ItemCode::RareCandy;
	_ItemPtr->Price = 10;
}

// 4. pp 에이드
void ItemDataBase::EtherData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = true;

	_ItemPtr->Name = "ETHER";
	_ItemPtr->ItemExplanation = "Restores 10 PP for one skill.";

	_ItemPtr->CodeNumber = ItemCode::Ether;
	_ItemPtr->Price = 400;
}

// 5. 박식의 안경 (특공)
void ItemDataBase::WiseGlassesData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = false;

	_ItemPtr->Name = "WISEGLASSES";
	_ItemPtr->ItemExplanation = "Increases the special attack power of the POK@MON holding this item.";

	_ItemPtr->CodeNumber = ItemCode::WiseGlasses;
	_ItemPtr->Price = 0;
}

// 6. 힘의 띠 (물공)
void ItemDataBase::MuscleBandData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = false;

	_ItemPtr->Name = "MUSLEBAND";
	_ItemPtr->ItemExplanation = "Increases the attack power of the POK@MON holding this item.";

	_ItemPtr->CodeNumber = ItemCode::MuscleBand;
	_ItemPtr->Price = 0;
}

// 7. 머리띠 (방어)
void ItemDataBase::ChoiceBandData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = false;

	_ItemPtr->Name = "CHOICEBAND";
	_ItemPtr->ItemExplanation = "Increases the defense of the POK@MON holding this item.";

	_ItemPtr->CodeNumber = ItemCode::ChoiceBand;
	_ItemPtr->Price = 0;
}

// 8. 스카프 (특방)
void ItemDataBase::ChoiceScarfData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = false;

	_ItemPtr->Name = "CHOICESCARF";
	_ItemPtr->ItemExplanation = "Increases the special defense of the POK@MON holding this item.";

	_ItemPtr->CodeNumber = ItemCode::ChoiceScarf;
	_ItemPtr->Price = 0;
}

// 9. 자전거
void ItemDataBase::BikeData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = false;

	_ItemPtr->Name = "BIKE";
	_ItemPtr->ItemExplanation = "A folding bike that allows faster movement than the WalKING.";

	_ItemPtr->CodeNumber = ItemCode::Bike;
	_ItemPtr->Price = 0;
}

// 10. 몬스터볼
void ItemDataBase::MonsterBallData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = true;

	_ItemPtr->Name = "POK@BALL";
	_ItemPtr->ItemExplanation = "A BALL throw to catch a wild POK@MON. It is designed in a capsule style.";

	_ItemPtr->CodeNumber = ItemCode::MonsterBall;
	_ItemPtr->Price = 200;
}

// 11. 마스터볼
void ItemDataBase::MasterBallData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = true;

	_ItemPtr->Name = "MASTERBALL";
	_ItemPtr->ItemExplanation = "You can definitely catch a wild POK@MON.";

	_ItemPtr->CodeNumber = ItemCode::MasterBall;
	_ItemPtr->Price = 10;
}

// 12, 취소
void ItemDataBase::CancelData(ItemDataBase* _ItemPtr)
{
	_ItemPtr->IsBattle = false;

	_ItemPtr->Name = "CANCLE";
	_ItemPtr->ItemExplanation = "Quite";

	_ItemPtr->CodeNumber = ItemCode::Cancel;
	_ItemPtr->Price = 0;
}