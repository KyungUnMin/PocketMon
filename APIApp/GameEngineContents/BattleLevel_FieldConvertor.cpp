#include "BattleLevel.h"

BattleFieldType BattleLevel::FieldConvertor(GroundType _FieldType)
{
	switch (_FieldType)
	{
	case GroundType::Grass:
		return BattleFieldType::Forest;
	case GroundType::Rock:
		return BattleFieldType::Gym;
	case GroundType::Beige:
		return BattleFieldType::Indoor;
	case GroundType::Gold:
		return BattleFieldType::Forest;
	case GroundType::Water:
	case GroundType::Blue:
	case GroundType::Grey:
	case GroundType::Purple:
	case GroundType::Cyan:
	case GroundType::Unknown:
		return BattleFieldType::Indoor;
	default:
		MsgAssert("�ش� ��ġ������ ������ �� �� �����ϴ�");
		break;
	}

	return BattleFieldType::Forest;
}



