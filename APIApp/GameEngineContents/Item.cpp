#include "Item.h"
#include <GameEngineBase/GameEngineDebug.h>

Item::Item()
{
}

Item::~Item() 
{
}

Item Item::GetItem(ItemCode _ItemCode)
{

	if (_ItemCode > ItemCode::Cancel)
	{
		MsgAssert("아이템 넘버는 12(Cancle)까지 존재합니다.");
		return Item();
	}
	else if (_ItemCode < ItemCode::Potion)
	{
		MsgAssert("아이템 넘버는 0(상처약)미만일 수 없습니다.");
		return Item();
	}

	switch (_ItemCode)
	{
	case ItemCode::Potion:
		return PotionData();
	case ItemCode::Repel:
		return RepelData();
	case ItemCode::Revive:
		return ReviveData();
	case ItemCode::RareCandy:
		return RareCandyData();
	case ItemCode::Ether:
		return EtherData();
	case ItemCode::WiseGlasses:
		return WiseGlassesData();
	case ItemCode::MuscleBand:
		return MuscleBandData();
	case ItemCode::ChoiceBand:
		return ChoiceBandData();
	case ItemCode::ChoiceScarf:
		return ChoiceScarfData();
	case ItemCode::Bike:
		return BikeData();
	case ItemCode::MonsterBall:
		return MonsterBallData();
	case ItemCode::MasterBall:
		return MasterBallData();
	case ItemCode::Cancel:
		return CancelData();
	default:
		return Item();
	}
}

// 0. 상처약
Item Item::PotionData()
{
	Item NewItem;
	NewItem.IsBattle = true;              // 사용 가능 아이템?
	NewItem.Name = "POTION";                  // 아이템 이름
	NewItem.ItemExplanation = "A spray-type sound medicine. It restores the HP of one POK@MON ny 20 points."; // 아이템 설명
	NewItem.CodeNumber = ItemCode::Potion;    // 이넘 넘버
	NewItem.Price = 300;                      // 가격

	return NewItem;
}

// 1. 벌레퇴치 스프레이
Item Item::RepelData()
{
	Item NewItem;

	NewItem.IsBattle = true;

	NewItem.Name = "REPEL";
	NewItem.ItemExplanation = "Prevents weak wild POK@MON from appearing for 100 steps.";

	NewItem.CodeNumber = ItemCode::Repel;
	NewItem.Price = 200;

	return NewItem;
}

// 2. 기력의 조각
Item Item::ReviveData()
{
	Item NewItem;

	NewItem.IsBattle = false;

	NewItem.Name = "REVIVE";
	NewItem.ItemExplanation = "Recovers a fainted POK@MON's HP by half.";

	NewItem.CodeNumber = ItemCode::Revive;
	NewItem.Price = 1000;

	return NewItem;
}

// 3. 이상한 사탕
Item Item::RareCandyData()
{
	Item NewItem;

	NewItem.IsBattle = true;

	NewItem.Name = "RARECANDY";
	NewItem.ItemExplanation = "A candy that is packed with energy, It raises the level of a POK@MON by one.";

	NewItem.CodeNumber = ItemCode::RareCandy;
	NewItem.Price = 10;

	return NewItem;
}

// 4. pp 에이드
Item Item::EtherData()
{
	Item NewItem;

	NewItem.IsBattle = true;

	NewItem.Name = "ETHER";
	NewItem.ItemExplanation = "Restores 10 PP for one skill.";

	NewItem.CodeNumber = ItemCode::Ether;
	NewItem.Price = 400;

	return NewItem;
}

// 5. 박식의 안경 (특공)
Item Item::WiseGlassesData()
{
	Item NewItem;

	NewItem.IsBattle = false;

	NewItem.Name = "WISEGLASSES";
	NewItem.ItemExplanation = "Increases the special attack power of the POK@MON holding this item.";

	NewItem.CodeNumber = ItemCode::WiseGlasses;
	NewItem.Price = 0;

	return NewItem;
}

// 6. 힘의 띠 (물공)
Item Item::MuscleBandData()
{
	Item NewItem;

	NewItem.IsBattle = false;

	NewItem.Name = "MUSLEBAND";
	NewItem.ItemExplanation = "Increases the attack power of the POK@MON holding this item.";

	NewItem.CodeNumber = ItemCode::MuscleBand;
	NewItem.Price = 0;

	return NewItem;
}

// 7. 머리띠 (방어)
Item Item::ChoiceBandData()
{
	Item NewItem;

	NewItem.IsBattle = false;

	NewItem.Name = "CHOICEBAND";
	NewItem.ItemExplanation = "Increases the defense of the POK@MON holding this item.";

	NewItem.CodeNumber = ItemCode::ChoiceBand;
	NewItem.Price = 0;

	return NewItem;
}

// 8. 스카프 (특방)
Item Item::ChoiceScarfData()
{
	Item NewItem;

	NewItem.IsBattle = false;

	NewItem.Name = "CHOICESCARF";
	NewItem.ItemExplanation = "Increases the special defense of the POK@MON holding this item.";

	NewItem.CodeNumber = ItemCode::ChoiceScarf;
	NewItem.Price = 0;

	return NewItem;
}

// 9. 자전거
Item Item::BikeData()
{
	Item NewItem;

	NewItem.IsBattle = false;

	NewItem.Name = "BIKE";
	NewItem.ItemExplanation = "A folding bike that allows faster movement than the WalKING.";

	NewItem.CodeNumber = ItemCode::Bike;
	NewItem.Price = 0;

	return NewItem;
}

// 10. 몬스터볼
Item Item::MonsterBallData()
{
	Item NewItem;

	NewItem.IsBattle = true;

	NewItem.Name = "POK@BALL";
	NewItem.ItemExplanation = "A BALL throw to catch a wild POK@MON. It is designed in a capsule style.";

	NewItem.CodeNumber = ItemCode::MonsterBall;
	NewItem.Price = 200;

	return NewItem;
}

// 11. 마스터볼
Item Item::MasterBallData()
{
	Item NewItem;

	NewItem.IsBattle = true;

	NewItem.Name = "MASTERBALL";
	NewItem.ItemExplanation = "You can definitely catch a wild POK@MON.";

	NewItem.CodeNumber = ItemCode::MasterBall;
	NewItem.Price = 10;

	return NewItem;
}

// 12, 취소
Item Item::CancelData()
{
	Item NewItem;

	NewItem.IsBattle = false;

	NewItem.Name = "CANCLE";
	NewItem.ItemExplanation = "Quite";

	NewItem.CodeNumber = ItemCode::Cancel;
	NewItem.Price = 0;

	return NewItem;
}