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
		MsgAssert("������ �ѹ��� 12(Cancle)���� �����մϴ�.");
		return Item();
	}
	else if (_ItemCode < ItemCode::Potion)
	{
		MsgAssert("������ �ѹ��� 0(��ó��)�̸��� �� �����ϴ�.");
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

// 0. ��ó��
Item Item::PotionData()
{
	Item NewItem;
	NewItem.IsBattle = true;              // ��� ���� ������?
	NewItem.Name = "POTION";                  // ������ �̸�
	NewItem.ItemExplanation = "A spray-type sound medicine. It restores the HP of one POK@MON ny 20 points."; // ������ ����
	NewItem.CodeNumber = ItemCode::Potion;    // �̳� �ѹ�
	NewItem.Price = 300;                      // ����

	return NewItem;
}

// 1. ������ġ ��������
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

// 2. ����� ����
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

// 3. �̻��� ����
Item Item::RareCandyData()
{
	Item NewItem;

	NewItem.IsBattle = true;

	NewItem.Name = "RARE CANDY";
	NewItem.ItemExplanation = "A candy that is packed with energy, It raises the level of a POK@MON by one.";

	NewItem.CodeNumber = ItemCode::RareCandy;
	NewItem.Price = 10;

	return NewItem;
}

// 4. pp ���̵�
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

// 5. �ڽ��� �Ȱ� (Ư��)
Item Item::WiseGlassesData()
{
	Item NewItem;

	NewItem.IsBattle = false;

	NewItem.Name = "WISE GLASSES";
	NewItem.ItemExplanation = "Increases the special attack power of the POK@MON holding this item.";

	NewItem.CodeNumber = ItemCode::WiseGlasses;
	NewItem.Price = 0;

	return NewItem;
}

// 6. ���� �� (����)
Item Item::MuscleBandData()
{
	Item NewItem;

	NewItem.IsBattle = false;

	NewItem.Name = "MUSLE BAND";
	NewItem.ItemExplanation = "Increases the attack power of the POK@MON holding this item.";

	NewItem.CodeNumber = ItemCode::MuscleBand;
	NewItem.Price = 0;

	return NewItem;
}

// 7. �Ӹ��� (���)
Item Item::ChoiceBandData()
{
	Item NewItem;

	NewItem.IsBattle = false;

	NewItem.Name = "CHOICE BAND";
	NewItem.ItemExplanation = "Increases the defense of the POK@MON holding this item.";

	NewItem.CodeNumber = ItemCode::ChoiceBand;
	NewItem.Price = 0;

	return NewItem;
}

// 8. ��ī�� (Ư��)
Item Item::ChoiceScarfData()
{
	Item NewItem;

	NewItem.IsBattle = false;

	NewItem.Name = "CHOICE SCARF";
	NewItem.ItemExplanation = "Increases the special defense of the POK@MON holding this item.";

	NewItem.CodeNumber = ItemCode::ChoiceScarf;
	NewItem.Price = 0;

	return NewItem;
}

// 9. ������
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

// 10. ���ͺ�
Item Item::MonsterBallData()
{
	Item NewItem;

	NewItem.IsBattle = true;

	NewItem.Name = "POK@ BALL";
	NewItem.ItemExplanation = "A BALL throw to catch a wild POK@MON. It is designed in a capsule style.";

	NewItem.CodeNumber = ItemCode::MonsterBall;
	NewItem.Price = 200;

	return NewItem;
}

// 11. �����ͺ�
Item Item::MasterBallData()
{
	Item NewItem;

	NewItem.IsBattle = true;

	NewItem.Name = "MASTER BALL";
	NewItem.ItemExplanation = "You can definitely catch a wild POK@MON.";

	NewItem.CodeNumber = ItemCode::MasterBall;
	NewItem.Price = 10;

	return NewItem;
}

// 12, ���
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