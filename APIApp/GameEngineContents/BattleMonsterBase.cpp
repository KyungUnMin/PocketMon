#include "BattleMonsterBase.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "PokeDataBase.h"
#include "ContentsEnum.h"
#include "PokeSkillBase.h"

BattleMonsterBase::BattleMonsterBase()
{
	
}

BattleMonsterBase::~BattleMonsterBase()
{

}

void BattleMonsterBase::Init(PokeDataBase _MonsterDB)
{
	IsInit = true;
	SetName(NameEnumToString[static_cast<size_t>(_MonsterDB.GetPokeNumber_int() - 1)]);
	DbPtr = _MonsterDB;
}



//
//BattleSkillBase* BattleMonsterBase::CreateSkill(PokeSkill _SkillType, BattleMonsterBase* _Owner)
//{
//	BattleSkillBase* Skill = nullptr;
//
//	switch (_SkillType)
//	{
//	case PokeSkill::Scratch:
//		break;
//	case PokeSkill::Growl:
//		break;
//	case PokeSkill::Ember:
//		break;
//	case PokeSkill::Leer:
//		break;
//	case PokeSkill::Slash:
//		break;
//	case PokeSkill::Flamethrower:
//		break;
//	case PokeSkill::Tackle:
//		break;
//	case PokeSkill::TailWhip:
//		break;
//	case PokeSkill::Bubble:
//		break;
//	case PokeSkill::WaterGun:
//		break;
//	case PokeSkill::Withdraw:
//		break;
//	case PokeSkill::SkullBash:
//		break;
//	case PokeSkill::HydroPump:
//		break;
//	case PokeSkill::LeechSeed:
//		break;
//	case PokeSkill::VineWhip:
//		break;
//	case PokeSkill::RazorLeaf:
//		break;
//	case PokeSkill::SleepPowder:
//		break;
//	case PokeSkill::SolarBeam:
//		break;
//	case PokeSkill::SandAttack:
//		break;
//	case PokeSkill::Gust:
//		break;
//	case PokeSkill::QuickAttack:
//		break;
//	case PokeSkill::Twister:
//		break;
//	case PokeSkill::FeatherDance:
//		break;
//	case PokeSkill::WingAttack:
//		break;
//	case PokeSkill::AirSlash:
//		break;
//	case PokeSkill::Peck:
//		break;
//	case PokeSkill::FuryAttack:
//		break;
//	case PokeSkill::Pursuit:
//		break;
//	case PokeSkill::FastMove:
//		break;
//	case PokeSkill::Assurance:
//		break;
//	case PokeSkill::DrillPeck:
//		break;
//	case PokeSkill::DefenseCurl:
//		break;
//	case PokeSkill::RockPolish:
//		break;
//	case PokeSkill::RockThrow:
//		break;
//	case PokeSkill::Magnitude:
//		break;
//	case PokeSkill::Selfdestruct:
//		break;
//	case PokeSkill::Earthquake:
//		break;
//	case PokeSkill::StoneEdge:
//		break;
//	case PokeSkill::Bind:
//		break;
//	case PokeSkill::RockTomb:
//		break;
//	case PokeSkill::DragonBreath:
//		break;
//	case PokeSkill::IronTail:
//		break;
//	case PokeSkill::SandTomb:
//		break;
//	case PokeSkill::Bite:
//		break;
//	case PokeSkill::HyperFang:
//		break;
//	case PokeSkill::Crunch:
//		break;
//	case PokeSkill::SuperFang:
//		break;
//	case PokeSkill::DoubleEdge:
//		break;
//	case PokeSkill::Unknown:
//		break;
//	default:
//		break;
//	}
//
//	//Skill->Init(_Owner);
//
//	return Skill;
//}



//GameEngineRender* BattleMonsterBase::CreateSkiilEffect(PokeSkill _SkillType)
//{
//	//임시, 크기 얼마가 될 지 모름
//	static const float4 RenderScale = float4{ 256.f, 256.f };
//
//	std::string ImagePath = SkiilEnumToString[static_cast<size_t>(_SkillType)].data();
//	ImagePath = "BattleSkill_" + ImagePath + ".bmp";
//
//	/*GameEngineRender* SkillRender = CreateRender(BattleRenderOrder::SkillEffect);
//	SkillRender->CreateAnimation
//	({
//		.AnimationName = "Skiil",
//		.ImageName = ImagePath,
//		.Start = 0,
//		.End = SkiilAniFrame[static_cast<size_t>(_SkillType)],
//		.Loop = false
//	});*/
//
//	return nullptr;
//}


