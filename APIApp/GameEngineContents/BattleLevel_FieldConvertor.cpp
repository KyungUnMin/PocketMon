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

	case GroundType::Water:
	case GroundType::Blue:
	case GroundType::Grey:
	case GroundType::Gold:
	case GroundType::Purple:
	case GroundType::Cyan:
	case GroundType::Unknown:
	default:
		MsgAssert("해당 위치에서는 전투를 할 수 없습니다");
		break;
	}

	return BattleFieldType::Forest;
}